from datetime import datetime

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

    def run(self, ast):
        """Itera sobre a AST e executa os nós."""
        for node in ast:
            self.execute(node)
