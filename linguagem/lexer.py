import re

# Definição dos tokens
TOKENS = [
    # Condicionais
    ("IF_TIME_LEFT", r"If there's time left"),
    ("OTHERWISE_FOCUS", r"Otherwise focus on"),
    ("BEFORE", r"before"),

    #loops
    ("REPEAT_UNTIL_COMPLETE", r"Repeat until complete"),
    ("DO_IT_AGAIN", r"Do it again"),
    ("TIMES", r"times"),

    # Outras definições
    ("DEFINE_TASK", r"Define a task"),
    ("SET_DEADLINE", r"Set deadline for"),
    ("PRIORITIZE", r"Prioritize this"),
    ("REPEAT_UNTIL_COMPLETE", r"Repeat until complete"),
    ("DO_IT_AGAIN", r"Do it again"),
    ("IF_TIME_LEFT", r"If there's time left"),
    ("OTHERWISE_FOCUS", r"Otherwise focus on"),
    ("AS", r"as"),
    ("STRING", r'"[^"]*"'),  # Strings entre aspas
    ("IDENTIFIER", r"[a-zA-Z_][a-zA-Z0-9_]*"),  # Identificadores
    ("NUMBER", r"\d+"),  # Números inteiros
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
