import sys
from lexer import tokenize
from parser import parse
from interpreter import Interpreter
from prepro import preprocess_code

def preprocess_code(code):
    """Remove comentários do código."""
    lines = code.splitlines()
    preprocessed_lines = []
    for line in lines:
        preprocessed_line = line.split("#", 1)[0].strip()
        if preprocessed_line:  # Adiciona apenas linhas não vazias
            preprocessed_lines.append(preprocessed_line)
    return "\n".join(preprocessed_lines)

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 2:
        print("Usage: python main.py <filename>")
        sys.exit(1)

    filename = sys.argv[1]
    try:
        with open(filename, "r") as f:
            code = f.read()
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        sys.exit(1)

    # Pré-processa o código para remover comentários
    code = preprocess_code(code)

    # Gera os tokens
    tokens = tokenize(code)

    # Cria a AST com o parser
    ast = parse(tokens)

    # Executa o programa usando o interpretador
    interpreter = Interpreter()
    interpreter.run(ast)
