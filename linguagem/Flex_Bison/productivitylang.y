%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estruturas de dados para armazenar informações de tarefas
typedef struct Task {
    char* name;
    char* deadline;
    char* priority;
    char* status;
    struct Task* next;
} Task;

Task* task_list = NULL;

void yyerror(const char* s);
int yylex();

%}

%union {
    char* str;
    int num;
}

%token <str> IDENTIFIER STRING
%token <num> NUMBER
%token DEFINE_TASK SET_DEADLINE SET FOR AS MARK REVIEW_ALL_TASKS SHOW_ME SAVE_TASKS LOAD_TASKS
%token AS_DONE AS_NOT_DONE IF_TIME_LEFT OTHERWISE REPEAT_UNTIL_COMPLETE DO_IT_AGAIN
%token DEFINE_FUNCTION RUN_FUNCTION LBRACE RBRACE LPAREN RPAREN COMMA SEMICOLON

%type <str> program statement block parameter_list argument_list

%%

program:
    program statement
    | /* vazio */
    ;

statement:
    DEFINE_TASK IDENTIFIER AS STRING SEMICOLON
        { printf("Defined task: %s as %s\n", $2, $4); }
    | SET_DEADLINE IDENTIFIER AS STRING SEMICOLON
        { printf("Set deadline for task: %s as %s\n", $2, $4); }
    | SET IDENTIFIER FOR IDENTIFIER AS STRING SEMICOLON
        { printf("Set %s for %s as %s\n", $2, $4, $6); }
    | MARK IDENTIFIER AS_DONE SEMICOLON
        { printf("Marked task: %s as done\n", $2); }
    | MARK IDENTIFIER AS_NOT_DONE SEMICOLON
        { printf("Marked task: %s as not done\n", $2); }
    | REVIEW_ALL_TASKS SEMICOLON
        { printf("Reviewing all tasks...\n"); }
    | SHOW_ME STRING SEMICOLON
        { printf("Show me: %s\n", $2); }
    | SAVE_TASKS STRING SEMICOLON
        { printf("Saved tasks to file: %s\n", $2); }
    | LOAD_TASKS STRING SEMICOLON
        { printf("Loaded tasks from file: %s\n", $2); }
    | IF_TIME_LEFT STRING block OTHERWISE STRING SEMICOLON
        { printf("If there's time left before %s, execute block. Otherwise focus on %s\n", $2, $5); }
    | REPEAT_UNTIL_COMPLETE block
        { printf("Repeat block until complete.\n"); }
    | DO_IT_AGAIN NUMBER "times" block
        { printf("Repeat block %d times.\n", $2); }
    | DEFINE_FUNCTION IDENTIFIER LPAREN parameter_list RPAREN block
        { printf("Defined function: %s\n", $2); }
    | RUN_FUNCTION IDENTIFIER LPAREN argument_list RPAREN SEMICOLON
        { printf("Running function: %s\n", $2); }
    ;

block:
    LBRACE program RBRACE
    ;

parameter_list:
    IDENTIFIER
    | IDENTIFIER COMMA parameter_list
    ;

argument_list:
    STRING
    | STRING COMMA argument_list
    ;
%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    return yyparse();
}
