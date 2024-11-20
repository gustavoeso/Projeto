import re

# Definition of tokens
TOKENS = [
    # Conditionals
    ("IF_TIME_LEFT", r"If there's time left"),
    ("OTHERWISE_FOCUS", r"Otherwise focus on"),
    ("BEFORE", r"before"),

    # Loops
    ("REPEAT_UNTIL_COMPLETE", r"Repeat until complete"),
    ("DO_IT_AGAIN", r"Do it again"),
    ("TIMES", r"times"),

    # Completion status
    ("MARK_AS_DONE", r"Mark"),
    ("AS_DONE", r"as done"),
    ("AS_NOT_DONE", r"as not done"),

    # Custom attributes
    ("SET_ATTRIBUTE", r"Set"),
    ("FOR_TASK", r"for"),

    # Review tasks
    ("REVIEW_ALL_TASKS", r"Review all tasks"),

    # Print
    ("SHOW_ME", r"Show me"),

    # Data persistence
    ("SAVE_TASKS", r"Save tasks to"),
    ("LOAD_TASKS", r"Load tasks from"),

    # Functions
    ("DEFINE_FUNCTION", r"Define function"),
    ("RUN_FUNCTION", r"Run"),
    ("LPAREN", r"\("),  # (
    ("RPAREN", r"\)"),  # )
    ("COMMA", r","),    # ,

    # Other definitions
    ("DEFINE_TASK", r"Define a task"),
    ("SET_DEADLINE", r"Set deadline for"),
    ("PRIORITIZE", r"Prioritize this"),
    ("AS", r"as"),
    ("STRING", r'"[^"]*"'),  # Strings in quotes
    ("IDENTIFIER", r"[a-zA-Z_][a-zA-Z0-9_]*"),  # Identifiers
    ("NUMBER", r"\d+"),  # Integers
    ("LBRACE", r"{"),  # {
    ("RBRACE", r"}"),  # }
    ("EQUALS", r"="),  # =
    ("SEMICOLON", r";"),  # ;
]

def tokenize(code):
    tokens = []
    while code:
        match = None
        for token_type, regex in TOKENS:
            regex = re.compile(regex)
            match = regex.match(code)
            if match:
                tokens.append((token_type, match.group(0).strip()))
                code = code[len(match.group(0)):].strip()
                break
        if not match:
            raise ValueError(f"Unexpected token: {code}")
    return tokens
