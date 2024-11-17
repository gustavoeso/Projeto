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
        expected = token_type
        found = tokens[pos][0] if pos < len(tokens) else "EOF"
        raise SyntaxError(f"SyntaxError: Expected {expected}, found {found} at position {pos}.")


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
        expect("BEFORE")
        condition = expect("STRING")
        expect("LBRACE")
        true_block = parse_block()
        expect("RBRACE")
        else_block = None
        if pos < len(tokens) and tokens[pos][0] == "OTHERWISE_FOCUS":
            expect("OTHERWISE_FOCUS")
            else_block = Node("ELSE_BLOCK", expect("STRING"), [])
        return Node("IF", condition, [
            Node("TRUE_BLOCK", None, true_block),
            else_block if else_block else None
        ])
    
    elif tokens[pos][0] == "REPEAT_UNTIL_COMPLETE":
        expect("REPEAT_UNTIL_COMPLETE")
        expect("LBRACE")
        loop_block = parse_block()
        expect("RBRACE")
        return Node("REPEAT_UNTIL_COMPLETE", None, loop_block)
    
    elif tokens[pos][0] == "DO_IT_AGAIN":
        expect("DO_IT_AGAIN")
        count = int(expect("NUMBER"))
        expect("TIMES")
        expect("LBRACE")
        loop_block = parse_block()
        expect("RBRACE")
        return Node("DO_IT_AGAIN", count, loop_block)
    
    elif tokens[pos][0] == "MARK_AS_DONE":
        expect("MARK_AS_DONE")
        task_id = expect("IDENTIFIER")
        if tokens[pos][0] == "AS_DONE":
            expect("AS_DONE")
            status = "done"
        elif tokens[pos][0] == "AS_NOT_DONE":
            expect("AS_NOT_DONE")
            status = "not done"
        else:
            raise SyntaxError(f"Expected 'as done' or 'as not done', found {tokens[pos]}")
        expect("SEMICOLON")
        return Node("MARK_AS_DONE", task_id, [Node("STATUS", status)])
    
    elif tokens[pos][0] == "SET_ATTRIBUTE":
        expect("SET_ATTRIBUTE")
        attribute = expect("IDENTIFIER")
        expect("FOR_TASK")
        task_id = expect("IDENTIFIER")
        expect("AS")
        value = expect("STRING")
        expect("SEMICOLON")
        return Node("SET_ATTRIBUTE", task_id, [Node("ATTRIBUTE", attribute), Node("VALUE", value)])
    
    elif tokens[pos][0] == "REVIEW_ALL_TASKS":
        expect("REVIEW_ALL_TASKS")
        expect("SEMICOLON")
        return Node("REVIEW_ALL_TASKS", None, [])
    
    elif tokens[pos][0] == "SHOW_ME":
        expect("SHOW_ME")
        if tokens[pos][0] == "STRING":  # Caso seja uma string
            message = expect("STRING")
            expect("SEMICOLON")
            return Node("SHOW_ME", None, [Node("MESSAGE", message)])
        elif tokens[pos][0] == "IDENTIFIER":  # Caso seja uma variável
            variable = expect("IDENTIFIER")
            expect("SEMICOLON")
            return Node("SHOW_ME_VARIABLE", variable, [])
        else:
            raise SyntaxError(f"Expected STRING or IDENTIFIER, found {tokens[pos]}")
        
    elif tokens[pos][0] == "SAVE_TASKS":
        expect("SAVE_TASKS")
        filename = expect("STRING")
        expect("SEMICOLON")
        return Node("SAVE_TASKS", filename, [])

    elif tokens[pos][0] == "LOAD_TASKS":
        expect("LOAD_TASKS")
        filename = expect("STRING")
        expect("SEMICOLON")
        return Node("LOAD_TASKS", filename, [])

    elif tokens[pos][0] == "SEMICOLON":
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
