from datetime import datetime
import json

class Interpreter:
    def __init__(self):
        self.tasks = {}

    def execute(self, node):
        if not node:  # Ignora nós inválidos ou None
            return

        if node.type == "DEFINE_TASK":
            task_id = node.value
            task_name = node.children[0].value.strip('"')
            self.tasks[task_id] = {"name": task_name}
            print(f"Task '{task_name}' defined.")

        elif node.type == "SET_DEADLINE":
            task_id = node.value
            deadline = node.children[0].value.strip('"')
            if task_id in self.tasks:
                self.tasks[task_id]["deadline"] = deadline
                print(f"Deadline for '{self.tasks[task_id]['name']}' set to {deadline}.")
            else:
                print(f"Task {task_id} not found.")

        elif node.type == "IF":
            condition = node.value.strip('"')  # Exemplo: "2024-12-01"
            today = datetime.now().strftime("%Y-%m-%d")

            if today < condition:  # Avalia a condição
                true_block = node.children[0]  # TRUE_BLOCK
                for child in true_block.children:  # Iterar corretamente no TRUE_BLOCK
                    self.execute(child)
            else:  # Executa ELSE_BLOCK se houver
                if len(node.children) > 1 and node.children[1]:  # ELSE_BLOCK existe
                    print(f"Focus on: {node.children[1].value.strip('"')}")

        elif node.type == "REPEAT_UNTIL_COMPLETE":
            # Limitar o loop para evitar infinito (pode ser ajustado com condições futuras)
            print("Executing REPEAT_UNTIL_COMPLETE block.")
            for _ in range(10):  # Simulação de limite (pode ser adaptado para condições reais)
                for child in node.children:
                    self.execute(child)

        elif node.type == "DO_IT_AGAIN":
            print(f"Executing DO_IT_AGAIN block {node.value} times.")
            for _ in range(node.value):  # Executa o bloco o número de vezes especificado
                for child in node.children:
                    self.execute(child)

        elif node.type == "MARK_AS_DONE":
            task_id = node.value
            status = node.children[0].value
            if task_id in self.tasks:
                self.tasks[task_id]["status"] = status
                print(f"Task '{self.tasks[task_id]['name']}' marked as {status}.")
            else:
                print(f"Task {task_id} not found.")

        elif node.type == "SET_ATTRIBUTE":
            task_id = node.value
            attribute = node.children[0].value
            attr_value = node.children[1].value.strip('"')
            if task_id in self.tasks:
                self.tasks[task_id][attribute] = attr_value
                print(f"Set {attribute} for '{self.tasks[task_id]['name']}' to {attr_value}.")
            else:
                print(f"Task {task_id} not found.")

        elif node.type == "REVIEW_ALL_TASKS":
            print("Reviewing all tasks:")
            print(f"{'Task ID':<10} | {'Name':<20} | {'Deadline':<15} | {'Status':<10} | Other Attributes")
            print("-" * 70)
            for task_id, task_info in self.tasks.items():
                task_name = task_info.get("name", "Unnamed task")
                deadline = task_info.get("deadline", "No deadline set")
                status = task_info.get("status", "not done")
                other_attributes = ", ".join(
                    f"{key}: {value}" for key, value in task_info.items() if key not in ["name", "deadline", "status"]
                )
                print(f"{task_id:<10} | {task_name:<20} | {deadline:<15} | {status:<10} | {other_attributes}")


        elif node.type == "SHOW_ME":
            # Mostrar uma string diretamente
            message = node.children[0].value.strip('"')  # Remove aspas da string
            print(message)

        elif node.type == "SHOW_ME_VARIABLE":
            variable = node.value
            if variable in self.tasks:
                task_info = self.tasks[variable]
                task_name = task_info.get("name", "Unnamed task")
                deadline = task_info.get("deadline", "No deadline set")
                status = task_info.get("status", "not done")
                print(f"{variable}: '{task_name}', Deadline: {deadline}, Status: {status}")
            else:
                print(f"RuntimeError: Variable '{variable}' not found.")


        # Salvar tarefas
        elif node.type == "SAVE_TASKS":
            filename = node.value.strip('"')  # Remove aspas
            try:
                with open(filename, "w") as file:
                    json.dump(self.tasks, file, indent=4)
                print(f"Tasks saved to {filename}.")
            except IOError:
                print(f"Error: Could not write to file '{filename}'.")

        # Carregar tarefas
        elif node.type == "LOAD_TASKS":
            filename = node.value.strip('"')  # Remove aspas
            try:
                with open(filename, "r") as file:
                    self.tasks = json.load(file)
                print(f"Tasks loaded from {filename}, overwriting the current state.")
            except FileNotFoundError:
                print(f"Error: File '{filename}' not found.")

    def run(self, ast):
        """Itera sobre a AST e executa os nós."""
        for node in ast:
            self.execute(node)
