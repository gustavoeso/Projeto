/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 44 "parser.y"

    #include "types.h"

#line 53 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEFINE_FUNCTION = 258,         /* DEFINE_FUNCTION  */
    DEFINE_TASK = 259,             /* DEFINE_TASK  */
    SET_DEADLINE = 260,            /* SET_DEADLINE  */
    SET_ATTRIBUTE = 261,           /* SET_ATTRIBUTE  */
    FOR_TASK = 262,                /* FOR_TASK  */
    AS_NOT_DONE = 263,             /* AS_NOT_DONE  */
    AS_DONE = 264,                 /* AS_DONE  */
    AS = 265,                      /* AS  */
    MARK_AS_DONE = 266,            /* MARK_AS_DONE  */
    REVIEW_ALL_TASKS = 267,        /* REVIEW_ALL_TASKS  */
    SHOW_ME = 268,                 /* SHOW_ME  */
    SAVE_TASKS = 269,              /* SAVE_TASKS  */
    LOAD_TASKS = 270,              /* LOAD_TASKS  */
    IF_TIME_LEFT = 271,            /* IF_TIME_LEFT  */
    BEFORE = 272,                  /* BEFORE  */
    OTHERWISE_FOCUS = 273,         /* OTHERWISE_FOCUS  */
    REPEAT_UNTIL_COMPLETE = 274,   /* REPEAT_UNTIL_COMPLETE  */
    DO_IT_AGAIN = 275,             /* DO_IT_AGAIN  */
    TIMES = 276,                   /* TIMES  */
    RUN_FUNCTION = 277,            /* RUN_FUNCTION  */
    IDENTIFIER = 278,              /* IDENTIFIER  */
    STRING = 279,                  /* STRING  */
    NUMBER = 280,                  /* NUMBER  */
    SEMICOLON = 281,               /* SEMICOLON  */
    LBRACE = 282,                  /* LBRACE  */
    RBRACE = 283,                  /* RBRACE  */
    LPAREN = 284,                  /* LPAREN  */
    RPAREN = 285,                  /* RPAREN  */
    COMMA = 286                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "parser.y"

    char* string;
    int number;
    char** str_list;
    Statement* stmt;
    Statement* stmt_list;
    struct {
        char** list;
        int count;
    } param_data;

#line 113 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
