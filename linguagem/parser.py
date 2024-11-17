class Node:
    def __init__(self, type, value=None, children=None):
        self.type = type
        self.value = value
        self.children = children or []

    def __repr__(self):
        return f"Node({self.type}, {self.value}, {self.children})"

# Parser global position tracker
pos = 0

def expect(token_type):
    global pos
    if pos < len(tokens) and tokens[pos][0] == token_type:
        pos += 1
        return tokens[pos - 1][1]
    else:
        raise SyntaxError(f"Expected {token_type}, found {tokens[pos] if pos < len(tokens) else 'EOF'}")

def parse_block():
    """Parses a block of statements enclosed by '{' and '}'."""
    block = []
    while pos < len(tokens) and tokens[pos][0] != "RBRACE":  # Process until "}"
        statement = parse_statement()
        if statement:  # Ignora nós inválidos ou None
            block.append(statement)
    return block

def parse_statement():
    global pos
    if tokens[pos][0] == "DEFINE_TASK":
        expect("DEFINE_TASK")
        identifier = expect("IDENTIFIER")
        expect("AS")
        task_name = expect("STRING")
        expect("SEMICOLON")
        return Node("DEFINE_TASK", identifier, [Node("STRING", task_name)])
    elif tokens[pos][0] == "SET_DEADLINE":
        expect("SET_DEADLINE")
        identifier = expect("IDENTIFIER")
        expect("AS")
        deadline = expect("STRING")
        expect("SEMICOLON")
        return Node("SET_DEADLINE", identifier, [Node("STRING", deadline)])
    elif tokens[pos][0] == "IF_TIME_LEFT":
        expect("IF_TIME_LEFT")
        expect("BEFORE")  # Processa o 'before'
        condition = expect("STRING")  # Exemplo: "2024-12-01"
        expect("LBRACE")
        true_block = parse_block()
        expect("RBRACE")
        else_block = None
        if pos < len(tokens) and tokens[pos][0] == "OTHERWISE_FOCUS":
            expect("OTHERWISE_FOCUS")
            else_block = Node("ELSE_BLOCK", expect("STRING"), [])
        # Não espera um ";" após um bloco condicional
        return Node("IF", condition, [
            Node("TRUE_BLOCK", None, true_block),
            else_block if else_block else None
        ])
    elif tokens[pos][0] == "SEMICOLON":
        # Ignora tokens ';' fora de comandos diretos
        pos += 1
        return None
    else:
        raise SyntaxError(f"Unexpected token: {tokens[pos]}")

def parse(tokens_input):
    """Parses the entire program."""
    global tokens, pos
    tokens = tokens_input
    pos = 0
    ast = []
    while pos < len(tokens):
        statement = parse_statement()
        if statement:  # Ignora nós inválidos ou None
            ast.append(statement)
    return ast
