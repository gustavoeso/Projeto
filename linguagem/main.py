from lexer import tokenize
from parser import parse
from interpreter import Interpreter

if __name__ == "__main__":
    with open("test.org", "r") as f:
        code = f.read()

    # Gera os tokens
    tokens = tokenize(code)

    # Cria a AST com o parser
    ast = parse(tokens)

    # Executa o programa usando o interpretador
    interpreter = Interpreter()
    interpreter.run(ast)
 