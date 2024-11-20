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
    expect("LBRACE")
    block = []
    while pos < len(tokens) and tokens[pos][0] != "RBRACE":  # Process until "}"
        statement = parse_statement()
        if statement:  # Ignore invalid or None nodes
            block.append(statement)
    expect("RBRACE")
    return block

def parse_statement():
    global pos
    if tokens[pos][0] == "DEFINE_TASK":
        expect("DEFINE_TASK")
        if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
            identifier = expect(tokens[pos][0])
            task_id_node = Node(tokens[pos - 1][0], identifier)
        else:
            raise SyntaxError(f"Expected STRING or IDENTIFIER for task ID, found {tokens[pos]} at position {pos}.")
        expect("AS")
        if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
            task_name = expect(tokens[pos][0])
            task_name_node = Node(tokens[pos - 1][0], task_name)
        else:
            raise SyntaxError(f"Expected STRING or IDENTIFIER for task name, found {tokens[pos]} at position {pos}.")
        expect("SEMICOLON")
        return Node("DEFINE_TASK", None, [task_id_node, task_name_node])

    elif tokens[pos][0] == "SET_DEADLINE":
        expect("SET_DEADLINE")
        if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
            identifier = expect(tokens[pos][0])
            task_id_node = Node(tokens[pos - 1][0], identifier)
        else:
            raise SyntaxError(f"Expected STRING or IDENTIFIER for task ID, found {tokens[pos]} at position {pos}.")
        expect("AS")
        if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
            deadline = expect(tokens[pos][0])
            deadline_node = Node(tokens[pos - 1][0], deadline)
        else:
            raise SyntaxError(f"Expected STRING or IDENTIFIER for deadline, found {tokens[pos]} at position {pos}.")
        expect("SEMICOLON")
        return Node("SET_DEADLINE", None, [task_id_node, deadline_node])

    elif tokens[pos][0] == "IF_TIME_LEFT":
        expect("IF_TIME_LEFT")
        expect("BEFORE")
        if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
            condition = expect(tokens[pos][0])
            condition_node = Node(tokens[pos - 1][0], condition)
        else:
            raise SyntaxError(f"Expected STRING or IDENTIFIER for condition, found {tokens[pos]} at position {pos}.")
        true_block = parse_block()
        else_block = None
        if pos < len(tokens) and tokens[pos][0] == "OTHERWISE_FOCUS":
            expect("OTHERWISE_FOCUS")
            if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
                else_value = expect(tokens[pos][0])
                else_node = Node("ELSE_BLOCK", Node(tokens[pos - 1][0], else_value), [])
            else:
                raise SyntaxError(f"Expected STRING or IDENTIFIER after OTHERWISE_FOCUS, found {tokens[pos]} at position {pos}.")
            else_block = else_node
        return Node("IF", None, [
            condition_node,
            Node("TRUE_BLOCK", None, true_block),
            else_block if else_block else None
        ])

    elif tokens[pos][0] == "REPEAT_UNTIL_COMPLETE":
        expect("REPEAT_UNTIL_COMPLETE")
        loop_block = parse_block()
        return Node("REPEAT_UNTIL_COMPLETE", None, loop_block)

    elif tokens[pos][0] == "DO_IT_AGAIN":
        expect("DO_IT_AGAIN")
        count = int(expect("NUMBER"))
        expect("TIMES")
        loop_block = parse_block()
        return Node("DO_IT_AGAIN", count, loop_block)

    elif tokens[pos][0] == "MARK_AS_DONE":
        expect("MARK_AS_DONE")
        if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
            task_id = expect(tokens[pos][0])
            task_id_node = Node(tokens[pos - 1][0], task_id)
        else:
            raise SyntaxError(f"Expected STRING or IDENTIFIER for task ID, found {tokens[pos]} at position {pos}.")
        if tokens[pos][0] == "AS_DONE":
            expect("AS_DONE")
            status = "done"
        elif tokens[pos][0] == "AS_NOT_DONE":
            expect("AS_NOT_DONE")
            status = "not done"
        else:
            raise SyntaxError(f"Expected 'as done' or 'as not done', found {tokens[pos]} at position {pos}")
        expect("SEMICOLON")
        return Node("MARK_AS_DONE", status, [task_id_node])

    elif tokens[pos][0] == "SET_ATTRIBUTE":
        expect("SET_ATTRIBUTE")
        attribute = expect("IDENTIFIER")
        expect("FOR_TASK")
        if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
            task_id = expect(tokens[pos][0])
            task_id_node = Node(tokens[pos - 1][0], task_id)
        else:
            raise SyntaxError(f"Expected STRING or IDENTIFIER for task ID, found {tokens[pos]} at position {pos}.")
        expect("AS")
        if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
            value = expect(tokens[pos][0])
            value_node = Node(tokens[pos - 1][0], value)
        else:
            raise SyntaxError(f"Expected STRING or IDENTIFIER for value, found {tokens[pos]} at position {pos}.")
        expect("SEMICOLON")
        return Node("SET_ATTRIBUTE", attribute, [task_id_node, value_node])

    elif tokens[pos][0] == "REVIEW_ALL_TASKS":
        expect("REVIEW_ALL_TASKS")
        expect("SEMICOLON")
        return Node("REVIEW_ALL_TASKS", None, [])

    elif tokens[pos][0] == "SHOW_ME":
        expect("SHOW_ME")
        if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
            message = expect(tokens[pos][0])
            message_node = Node(tokens[pos - 1][0], message)
        else:
            raise SyntaxError(f"Expected STRING or IDENTIFIER after SHOW_ME, found {tokens[pos]} at position {pos}.")
        expect("SEMICOLON")
        return Node("SHOW_ME", None, [message_node])

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

    elif tokens[pos][0] == "DEFINE_FUNCTION":
        expect("DEFINE_FUNCTION")
        func_name = expect("IDENTIFIER")
        expect("LPAREN")
        func_params = []
        if tokens[pos][0] == "IDENTIFIER":
            func_params.append(expect("IDENTIFIER"))
            while tokens[pos][0] == "COMMA":
                expect("COMMA")
                func_params.append(expect("IDENTIFIER"))
        expect("RPAREN")
        func_body = parse_block()
        return Node("DEFINE_FUNCTION", func_name, [Node("PARAMS", func_params), Node("BODY", None, func_body)])

    elif tokens[pos][0] == "RUN_FUNCTION":
        expect("RUN_FUNCTION")
        func_name = expect("IDENTIFIER")
        expect("LPAREN")
        func_args = []
        if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
            func_args.append(expect(tokens[pos][0]))
            while tokens[pos][0] == "COMMA":
                expect("COMMA")
                if tokens[pos][0] in ["STRING", "IDENTIFIER"]:
                    func_args.append(expect(tokens[pos][0]))
                else:
                    raise SyntaxError(f"Expected STRING or IDENTIFIER in function arguments, found {tokens[pos]} at position {pos}")
        expect("RPAREN")
        expect("SEMICOLON")
        return Node("RUN_FUNCTION", func_name, [Node("ARGS", func_args)])

    elif tokens[pos][0] == "SEMICOLON":
        pos += 1
        return None

    else:
        raise SyntaxError(f"Unexpected token: {tokens[pos]} at position {pos}")

def parse(tokens_input):
    """Parses the entire program."""
    global tokens, pos
    tokens = tokens_input
    pos = 0
    ast = []
    while pos < len(tokens):
        statement = parse_statement()
        if statement:  # Ignore invalid or None nodes
            ast.append(statement)
    return ast
