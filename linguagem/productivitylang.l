%{
#include "productivitylang.tab.h"
#include <string.h>
%}

%option noyywrap

%%
"Define a task"          { return DEFINE_TASK; }
"Set deadline"           { return SET_DEADLINE; }
"Repeat until complete"  { return REPEAT_UNTIL_COMPLETE; }
"as"                     { return AS; }
"{"                      { return LBRACE; }
"}"                      { return RBRACE; }
[a-zA-Z_][a-zA-Z0-9_]*   { yylval.str = strdup(yytext); return IDENTIFIER; }
\"[^\"]*\"               { yylval.str = strdup(yytext); return STRING; }
[ \t\n]+                 { /* Ignore whitespace */ }
.                        { return yytext[0]; }
%%
