%{
#include "parser.tab.h"
#include <string.h>
#include <stdlib.h>
#include "types.h"
%}

%option noyywrap
%option yylineno

%%

[ \t\r\n]+          ;  /* Ignore whitespace */

"Define function"    { return DEFINE_FUNCTION; }
"Define a task"      { return DEFINE_TASK; }
"Set deadline"       { return SET_DEADLINE; }
"Set"                { return SET_ATTRIBUTE; }
"for"                { return FOR_TASK; }
"as not done"        { return AS_NOT_DONE; }
"as done"            { return AS_DONE; }
"as"                 { return AS; }
"Mark"               { return MARK_AS_DONE; }
"Review all tasks"   { return REVIEW_ALL_TASKS; }
"Show me"            { return SHOW_ME; }
"Save tasks to"      { return SAVE_TASKS; }
"Load tasks from"    { return LOAD_TASKS; }
"If there's time left" { return IF_TIME_LEFT; }
"before"             { return BEFORE; }
"Otherwise focus on" { return OTHERWISE_FOCUS; }
"Repeat until complete" { return REPEAT_UNTIL_COMPLETE; }
"Do it again"        { return DO_IT_AGAIN; }
"times"              { return TIMES; }
"Run"                { return RUN_FUNCTION; }
","                  { return COMMA; }
"("                  { return LPAREN; }
")"                  { return RPAREN; }
"{"                  { return LBRACE; }
"}"                  { return RBRACE; }
";"                  { return SEMICOLON; }

\"[^\"]*\"           {
                        yylval.string = strdup(yytext);
                        return STRING;
                    }

[a-zA-Z_][a-zA-Z0-9_]* {
                        yylval.string = strdup(yytext);
                        return IDENTIFIER;
                    }

[0-9]+               {
                        yylval.number = atoi(yytext);
                        return NUMBER;
                    }

.                    { /* Ignore unrecognized characters */ }

%%
