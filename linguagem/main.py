import sys
from lexer import tokenize
from parser import parse
from interpreter import Interpreter

if __name__ == "__main__":
    # Verifica se um argumento foi passado
    if len(sys.argv) < 2:
        print("Usage: python main.py <filename>")
        sys.exit(1)

    # Pega o nome do arquivo a partir do argumento
    filename = sys.argv[1]

    try:
        with open(filename, "r") as f:
            code = f.read()
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        sys.exit(1)

    # Gera os tokens
    tokens = tokenize(code)

    # Cria a AST com o parser
    ast = parse(tokens)

    # Executa o programa usando o interpretador
    interpreter = Interpreter()
    interpreter.run(ast)
