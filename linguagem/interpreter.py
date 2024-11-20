import json  # Import the json module
from datetime import datetime
from parser import Node

class Interpreter:
    def __init__(self):
        self.tasks = {}
        self.functions = {}  # Store functions
        self.variable_stack = [{}]  # Stack for variable scopes

    def resolve_variable(self, var_name):
        for scope in reversed(self.variable_stack):
            if var_name in scope:
                return scope[var_name]
        # If not found in variables, return the name itself
        return var_name

    def get_value(self, node):
        if node.type == 'IDENTIFIER':
            return self.resolve_variable(node.value)
        else:
            return node.value.strip('"')

    def execute(self, node):
        if not node:
            return

        if node.type == "DEFINE_TASK":
            task_id_node = node.children[0]
            task_name_node = node.children[1]
            task_id = self.get_value(task_id_node)
            task_name = self.get_value(task_name_node)
            self.tasks[task_id] = {"name": task_name}
            print(f"Task '{task_name}' defined.")

        elif node.type == "SET_DEADLINE":
            task_id_node = node.children[0]
            deadline_node = node.children[1]
            task_id = self.get_value(task_id_node)
            deadline = self.get_value(deadline_node)
            if task_id in self.tasks:
                self.tasks[task_id]["deadline"] = deadline
                print(f"Deadline for '{self.tasks[task_id]['name']}' set to {deadline}.")
            else:
                print(f"Task {task_id} not found.")

        elif node.type == "REPEAT_UNTIL_COMPLETE":
            print("Executing REPEAT_UNTIL_COMPLETE block.")
            for _ in range(10):  # Simulation of a limit
                for child in node.children:
                    self.execute(child)

        elif node.type == "DO_IT_AGAIN":
            print(f"Executing DO_IT_AGAIN block {node.value} times.")
            for _ in range(node.value):
                for child in node.children:
                    self.execute(child)

        elif node.type == "MARK_AS_DONE":
            status = node.value
            task_id_node = node.children[0]
            task_id = self.get_value(task_id_node)
            if task_id in self.tasks:
                self.tasks[task_id]["status"] = status
                print(f"Task '{self.tasks[task_id]['name']}' marked as {status}.")
            else:
                print(f"Task {task_id} not found.")

        elif node.type == "SET_ATTRIBUTE":
            attribute = node.value
            task_id_node = node.children[0]
            value_node = node.children[1]
            task_id = self.get_value(task_id_node)
            attr_value = self.get_value(value_node)
            if task_id in self.tasks:
                self.tasks[task_id][attribute] = attr_value
                print(f"Set {attribute} for '{self.tasks[task_id]['name']}' to {attr_value}.")
            else:
                print(f"Task {task_id} not found.")

        elif node.type == "REVIEW_ALL_TASKS":
            print("Reviewing all tasks:")
            print(f"{'Task ID':<20} | {'Name':<20} | {'Deadline':<15} | {'Status':<10} | Other Attributes")
            print("-" * 85)
            for task_id, task_info in self.tasks.items():
                task_name = task_info.get("name", "Unnamed task")
                deadline = task_info.get("deadline", "No deadline set")
                status = task_info.get("status", "not done")
                other_attributes = ", ".join(
                    f"{key}: {value}" for key, value in task_info.items() if key not in ["name", "deadline", "status"]
                )
                print(f"{task_id:<20} | {task_name:<20} | {deadline:<15} | {status:<10} | {other_attributes}")

        elif node.type == "SHOW_ME":
            message_node = node.children[0]
            if message_node.type == 'IDENTIFIER':
                var_name = message_node.value
                # First, check if it's a task
                if var_name in self.tasks:
                    task_info = self.tasks[var_name]
                    task_name = task_info.get("name", "Unnamed task")
                    deadline = task_info.get("deadline", "No deadline set")
                    status = task_info.get("status", "not done")
                    other_attributes = ", ".join(
                        f"{key}: {value}" for key, value in task_info.items() if key not in ["name", "deadline", "status"]
                    )
                    print(f"{var_name}: '{task_name}', Deadline: {deadline}, Status: {status}")
                    if other_attributes:
                        print(f"Other Attributes: {other_attributes}")
                else:
                    # Check if it's a variable in the variable stack
                    value = self.resolve_variable(var_name)
                    if value != var_name:
                        print(f"{var_name}: {value}")
                    else:
                        print(f"RuntimeError: Variable or task '{var_name}' not found.")
            else:
                # It's a string, print it directly
                message = self.get_value(message_node)
                print(message)

        elif node.type == "SAVE_TASKS":
            filename = node.value.strip('"')
            try:
                with open(filename, 'w') as f:
                    json.dump(self.tasks, f, indent=4)
                print(f"Tasks saved to {filename}.")
            except Exception as e:
                print(f"Error saving tasks to '{filename}': {e}")

        elif node.type == "LOAD_TASKS":
            filename = node.value.strip('"')
            try:
                with open(filename, 'r') as f:
                    self.tasks = json.load(f)
                print(f"Tasks loaded from {filename}.")
            except FileNotFoundError:
                print(f"Error: File '{filename}' not found.")
            except json.JSONDecodeError as e:
                print(f"Error loading tasks from '{filename}': {e}")

        elif node.type == "DEFINE_FUNCTION":
            func_name = node.value
            func_params = node.children[0].value
            func_body = node.children[1].children
            self.functions[func_name] = {"params": func_params, "body": func_body}
            print(f"Function '{func_name}' defined with parameters {func_params}.")

        elif node.type == "RUN_FUNCTION":
            func_name = node.value
            if func_name not in self.functions:
                print(f"RuntimeError: Function '{func_name}' is not defined.")
                return

            func_data = self.functions[func_name]
            func_params = func_data["params"]
            func_body = func_data["body"]
            func_args = node.children[0].value

            if len(func_params) != len(func_args):
                print(f"RuntimeError: Function '{func_name}' expects {len(func_params)} arguments, "
                      f"but {len(func_args)} were provided.")
                return

            local_vars = {}
            for param, arg in zip(func_params, func_args):
                if arg.startswith('"') and arg.endswith('"'):
                    local_vars[param] = arg.strip('"')
                else:
                    resolved_arg = self.resolve_variable(arg)
                    local_vars[param] = resolved_arg

            self.variable_stack.append(local_vars)
            for statement in func_body:
                self.execute(statement)
            self.variable_stack.pop()

        else:
            print(f"RuntimeError: Unrecognized node type '{node.type}'.")

    def run(self, ast):
        """Iterates over the AST and executes the nodes."""
        for node in ast:
            self.execute(node)