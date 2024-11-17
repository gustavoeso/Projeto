def preprocess_code(code):
    """Remove comentários do código."""
    lines = code.splitlines()
    preprocessed_lines = []
    for line in lines:
        # Remove tudo após o símbolo de comentário #
        preprocessed_line = line.split("#", 1)[0].strip()
        if preprocessed_line:  # Adiciona apenas linhas não vazias
            preprocessed_lines.append(preprocessed_line)
    return "\n".join(preprocessed_lines)
