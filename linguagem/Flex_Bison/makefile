# Makefile para compilar o interpretador ProductivityLang usando Flex e Bison

# Nomes dos arquivos
LEXER=lexer.l
PARSER=parser.y
EXECUTABLE=productivitylang
TYPES=types.h

# Arquivos gerados
LEXER_C=lex.yy.c
PARSER_C=parser.tab.c
PARSER_H=parser.tab.h

# Compilador e flags
CC=gcc
CFLAGS=-g -Wall -Wextra -Wno-unused-function

all: $(EXECUTABLE)

$(EXECUTABLE): $(LEXER_C) $(PARSER_C)
	$(CC) $(CFLAGS) -o $@ $(PARSER_C) $(LEXER_C) -lfl

$(LEXER_C): $(LEXER) $(PARSER_H) $(TYPES)
	flex $(LEXER)

$(PARSER_C) $(PARSER_H): $(PARSER) $(TYPES)
	bison -d $(PARSER)

# Adicione esta regra vazia para informar ao make que types.h existe e não precisa ser construído
types.h:

clean:
	rm -f $(EXECUTABLE) $(LEXER_C) $(PARSER_C) $(PARSER_H)
