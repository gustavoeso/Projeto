%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(const char* s);

%}

%union {
    char* str;
}

%token <str> IDENTIFIER STRING
%token DEFINE_TASK SET_DEADLINE REPEAT_UNTIL_COMPLETE AS LBRACE RBRACE

%type <str> program statement

%%
program:
    program statement
    | /* vazio */
    ;

statement:
    DEFINE_TASK IDENTIFIER AS STRING ';'
        { printf("Defined task: %s as %s\n", $2, $4); }
    | SET_DEADLINE IDENTIFIER AS STRING ';'
        { printf("Set deadline for task: %s as %s\n", $2, $4); }
    | REPEAT_UNTIL_COMPLETE LBRACE program RBRACE
        { printf("Repeat block executed.\n"); }
    ;
%%
void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
int main() {
    return yyparse();
}
