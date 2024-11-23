%{
#include "productivitylang.tab.h"
#include <string.h>
%}

%option noyywrap

%%
// Palavras-chave
"Define a task"          { return DEFINE_TASK; }
"Set deadline for"       { return SET_DEADLINE; }
"Set"                    { return SET; }
"for"                    { return FOR; }
"as"                     { return AS; }
"Mark"                   { return MARK; }
"as done"                { return AS_DONE; }
"as not done"            { return AS_NOT_DONE; }
"Review all tasks"       { return REVIEW_ALL_TASKS; }
"Show me"                { return SHOW_ME; }
"Save tasks to"          { return SAVE_TASKS; }
"Load tasks from"        { return LOAD_TASKS; }
"If there's time left before" { return IF_TIME_LEFT; }
"Otherwise focus on"     { return OTHERWISE; }
"Repeat until complete"  { return REPEAT_UNTIL_COMPLETE; }
"Do it again"            { return DO_IT_AGAIN; }
"Define function"        { return DEFINE_FUNCTION; }
"Run"                    { return RUN_FUNCTION; }

// Símbolos
"{"                      { return LBRACE; }
"}"                      { return RBRACE; }
","                      { return COMMA; }
"("                      { return LPAREN; }
")"                      { return RPAREN; }
";"                      { return SEMICOLON; }

// Identificadores e strings
[a-zA-Z_][a-zA-Z0-9_]*   { yylval.str = strdup(yytext); return IDENTIFIER; }
\"[^\"]*\"               { yylval.str = strdup(yytext); return STRING; }

// Números
[0-9]+                   { yylval.num = atoi(yytext); return NUMBER; }

// Espaços em branco
[ \t\n]+                 { /* Ignore whitespace */ }

// Caracteres inválidos
.                        { return yytext[0]; }
%%
