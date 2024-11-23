/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

/* C code section */

#define _XOPEN_SOURCE 700  /* For strptime */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "types.h"

int yylex(void);
void yyerror(const char *s);
extern int yylineno;

int inside_function = 0;
int inside_block = 0;

Task* task_list = NULL;
Function* function_list = NULL;

/* Function prototypes */
Task* create_task(char* id, char* name);
void add_task(Task* task);
Task* find_task(char* id);
void review_all_tasks();
void free_tasks();
void set_task_attribute(Task* task, char* key, char* value);
char* get_task_attribute(Task* task, char* key);
void free_task_attributes(Task* task);

void add_function(Function* func);
Function* find_function(char* name);
void execute_function(Function* func, char** arguments, int arg_count);

void execute_show_me(Statement* stmt, char** param_names, char** param_values, int param_count);
void execute_mark_as_done(Statement* stmt, char** param_names, char** param_values, int param_count);
void execute_statement(Statement* stmt, char** param_names, char** param_values, int param_count);
int check_deadline(char* deadline);


#line 113 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEFINE_FUNCTION = 3,            /* DEFINE_FUNCTION  */
  YYSYMBOL_DEFINE_TASK = 4,                /* DEFINE_TASK  */
  YYSYMBOL_SET_DEADLINE = 5,               /* SET_DEADLINE  */
  YYSYMBOL_SET_ATTRIBUTE = 6,              /* SET_ATTRIBUTE  */
  YYSYMBOL_FOR_TASK = 7,                   /* FOR_TASK  */
  YYSYMBOL_AS_NOT_DONE = 8,                /* AS_NOT_DONE  */
  YYSYMBOL_AS_DONE = 9,                    /* AS_DONE  */
  YYSYMBOL_AS = 10,                        /* AS  */
  YYSYMBOL_MARK_AS_DONE = 11,              /* MARK_AS_DONE  */
  YYSYMBOL_REVIEW_ALL_TASKS = 12,          /* REVIEW_ALL_TASKS  */
  YYSYMBOL_SHOW_ME = 13,                   /* SHOW_ME  */
  YYSYMBOL_SAVE_TASKS = 14,                /* SAVE_TASKS  */
  YYSYMBOL_LOAD_TASKS = 15,                /* LOAD_TASKS  */
  YYSYMBOL_IF_TIME_LEFT = 16,              /* IF_TIME_LEFT  */
  YYSYMBOL_BEFORE = 17,                    /* BEFORE  */
  YYSYMBOL_OTHERWISE_FOCUS = 18,           /* OTHERWISE_FOCUS  */
  YYSYMBOL_REPEAT_UNTIL_COMPLETE = 19,     /* REPEAT_UNTIL_COMPLETE  */
  YYSYMBOL_DO_IT_AGAIN = 20,               /* DO_IT_AGAIN  */
  YYSYMBOL_TIMES = 21,                     /* TIMES  */
  YYSYMBOL_RUN_FUNCTION = 22,              /* RUN_FUNCTION  */
  YYSYMBOL_IDENTIFIER = 23,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_NUMBER = 25,                    /* NUMBER  */
  YYSYMBOL_SEMICOLON = 26,                 /* SEMICOLON  */
  YYSYMBOL_LBRACE = 27,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 28,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 29,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 30,                    /* RPAREN  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_statement = 34,                 /* statement  */
  YYSYMBOL_define_task = 35,               /* define_task  */
  YYSYMBOL_set_deadline = 36,              /* set_deadline  */
  YYSYMBOL_set_attribute = 37,             /* set_attribute  */
  YYSYMBOL_mark_as_done = 38,              /* mark_as_done  */
  YYSYMBOL_status = 39,                    /* status  */
  YYSYMBOL_review_all_tasks = 40,          /* review_all_tasks  */
  YYSYMBOL_show_me = 41,                   /* show_me  */
  YYSYMBOL_save_tasks = 42,                /* save_tasks  */
  YYSYMBOL_load_tasks = 43,                /* load_tasks  */
  YYSYMBOL_function_definition = 44,       /* function_definition  */
  YYSYMBOL_run_function = 45,              /* run_function  */
  YYSYMBOL_conditional = 46,               /* conditional  */
  YYSYMBOL_optional_else = 47,             /* optional_else  */
  YYSYMBOL_loop = 48,                      /* loop  */
  YYSYMBOL_parameter_list = 49,            /* parameter_list  */
  YYSYMBOL_parameters = 50,                /* parameters  */
  YYSYMBOL_argument_list = 51,             /* argument_list  */
  YYSYMBOL_arguments = 52,                 /* arguments  */
  YYSYMBOL_value_list = 53,                /* value_list  */
  YYSYMBOL_value = 54,                     /* value  */
  YYSYMBOL_block = 55,                     /* block  */
  YYSYMBOL_begin_block = 56,               /* begin_block  */
  YYSYMBOL_end_block = 57,                 /* end_block  */
  YYSYMBOL_func_statements = 58,           /* func_statements  */
  YYSYMBOL_func_statement = 59             /* func_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   92

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    99,    99,   101,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   120,   140,   165,   199,
     222,   226,   233,   240,   260,   268,   276,   294,   307,   334,
     337,   344,   362,   390,   394,   401,   408,   420,   424,   431,
     438,   449,   455,   466,   470,   477,   484,   488,   492,   496,
     514,   515,   516,   517,   518,   519,   520
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEFINE_FUNCTION",
  "DEFINE_TASK", "SET_DEADLINE", "SET_ATTRIBUTE", "FOR_TASK",
  "AS_NOT_DONE", "AS_DONE", "AS", "MARK_AS_DONE", "REVIEW_ALL_TASKS",
  "SHOW_ME", "SAVE_TASKS", "LOAD_TASKS", "IF_TIME_LEFT", "BEFORE",
  "OTHERWISE_FOCUS", "REPEAT_UNTIL_COMPLETE", "DO_IT_AGAIN", "TIMES",
  "RUN_FUNCTION", "IDENTIFIER", "STRING", "NUMBER", "SEMICOLON", "LBRACE",
  "RBRACE", "LPAREN", "RPAREN", "COMMA", "$accept", "program", "statement",
  "define_task", "set_deadline", "set_attribute", "mark_as_done", "status",
  "review_all_tasks", "show_me", "save_tasks", "load_tasks",
  "function_definition", "run_function", "conditional", "optional_else",
  "loop", "parameter_list", "parameters", "argument_list", "arguments",
  "value_list", "value", "block", "begin_block", "end_block",
  "func_statements", "func_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -57,    35,   -57,   -22,   -20,    -2,    -9,    -3,    -1,   -14,
       3,     4,     9,     6,    11,     8,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,     5,
      32,    20,    37,    15,   -57,   -57,   -57,    -7,   -57,    19,
      36,   -14,   -57,   -57,    54,    40,    34,    41,   -14,    56,
      45,   -57,   -57,    43,   -57,   -57,   -57,   -57,     6,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,     2,   -57,     6,   -14,
     -57,    42,    44,    50,   -14,    61,   -57,    59,   -57,   -57,
     -57,   -57,    48,    49,   -57,     6,    58,   -57,    53,   -14,
     -14,   -57,    57,   -14,   -57,   -57,   -57,    60,    62,   -57,
     -57,   -57,   -57
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,    22,    44,    43,     0,    41,     0,
       0,     0,    46,    31,     0,     0,     0,    33,     0,     0,
       0,    21,    20,     0,    23,    42,    24,    25,     0,    52,
      53,    54,    50,    51,    56,    55,     0,    48,     0,    37,
      35,     0,    34,     0,     0,     0,    19,    29,    47,    45,
      49,    32,     0,    38,    39,     0,     0,    16,     0,     0,
       0,    28,     0,     0,    26,    36,    17,     0,     0,    27,
      40,    18,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,    81,    83,    84,    86,   -57,   -57,    88,
     -57,   -57,   -57,   -57,    89,   -57,    90,   -57,   -57,   -57,
     -57,   -57,   -37,   -56,   -57,   -57,   -57,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    16,    59,    60,    61,    62,    53,    21,    63,
      23,    24,    25,    26,    64,    91,    65,    71,    72,    82,
      83,    37,    38,    43,    44,    79,    66,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,    29,    77,    30,    58,    31,     4,     5,     6,    35,
      36,    73,    81,     7,    32,     9,    35,    36,    12,    54,
      33,    13,    14,    51,    52,    34,    41,    39,    40,    94,
      78,    46,    84,    42,    47,     2,    45,    88,     3,     4,
       5,     6,    48,    49,    50,    56,     7,     8,     9,    10,
      11,    12,    97,    98,    13,    14,   100,    15,     4,     5,
       6,    68,    57,    69,    70,     7,    74,     9,    75,    76,
      12,    89,    85,    13,    14,    86,    87,    90,    92,    96,
      93,    95,    17,    99,    18,    19,   101,    20,   102,    22,
      27,    28,    80
};

static const yytype_int8 yycheck[] =
{
      37,    23,    58,    23,    41,     7,     4,     5,     6,    23,
      24,    48,    68,    11,    23,    13,    23,    24,    16,    26,
      23,    19,    20,     8,     9,    26,    17,    24,    24,    85,
      28,    23,    69,    27,    29,     0,    25,    74,     3,     4,
       5,     6,    10,    23,     7,    26,    11,    12,    13,    14,
      15,    16,    89,    90,    19,    20,    93,    22,     4,     5,
       6,    21,    26,    29,    23,    11,    10,    13,    23,    26,
      16,    10,    30,    19,    20,    31,    26,    18,    30,    26,
      31,    23,     1,    26,     1,     1,    26,     1,    26,     1,
       1,     1,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,     0,     3,     4,     5,     6,    11,    12,    13,
      14,    15,    16,    19,    20,    22,    34,    35,    36,    37,
      38,    40,    41,    42,    43,    44,    45,    46,    48,    23,
      23,     7,    23,    23,    26,    23,    24,    53,    54,    24,
      24,    17,    27,    55,    56,    25,    23,    29,    10,    23,
       7,     8,     9,    39,    26,    54,    26,    26,    54,    35,
      36,    37,    38,    41,    46,    48,    58,    59,    21,    29,
      23,    49,    50,    54,    10,    23,    26,    55,    28,    57,
      59,    55,    51,    52,    54,    30,    31,    26,    54,    10,
      18,    47,    30,    31,    55,    23,    26,    54,    54,    26,
      54,    26,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    35,    36,    37,    38,
      39,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    56,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     6,     7,     4,
       1,     1,     2,     3,     3,     3,     6,     6,     5,     0,
       3,     2,     4,     0,     1,     1,     3,     0,     1,     1,
       3,     1,     2,     1,     1,     3,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* statement: define_task  */
#line 105 "parser.y"
                               {}
#line 1226 "parser.tab.c"
    break;

  case 5: /* statement: set_deadline  */
#line 106 "parser.y"
                               {}
#line 1232 "parser.tab.c"
    break;

  case 6: /* statement: set_attribute  */
#line 107 "parser.y"
                               {}
#line 1238 "parser.tab.c"
    break;

  case 7: /* statement: mark_as_done  */
#line 108 "parser.y"
                               {}
#line 1244 "parser.tab.c"
    break;

  case 8: /* statement: review_all_tasks  */
#line 109 "parser.y"
                               {}
#line 1250 "parser.tab.c"
    break;

  case 9: /* statement: show_me  */
#line 110 "parser.y"
                               {}
#line 1256 "parser.tab.c"
    break;

  case 10: /* statement: save_tasks  */
#line 111 "parser.y"
                               {}
#line 1262 "parser.tab.c"
    break;

  case 11: /* statement: load_tasks  */
#line 112 "parser.y"
                               {}
#line 1268 "parser.tab.c"
    break;

  case 12: /* statement: function_definition  */
#line 113 "parser.y"
                               {}
#line 1274 "parser.tab.c"
    break;

  case 13: /* statement: run_function  */
#line 114 "parser.y"
                               {}
#line 1280 "parser.tab.c"
    break;

  case 14: /* statement: conditional  */
#line 115 "parser.y"
                               {}
#line 1286 "parser.tab.c"
    break;

  case 15: /* statement: loop  */
#line 116 "parser.y"
                               {}
#line 1292 "parser.tab.c"
    break;

  case 16: /* define_task: DEFINE_TASK IDENTIFIER AS value SEMICOLON  */
#line 121 "parser.y"
    {
        printf("Define task: %s as %s\n", (yyvsp[-3].string), (yyvsp[-1].string));
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("define_task");
        stmt->data = malloc(sizeof(char*) * 2);
        ((char**)stmt->data)[0] = strdup((yyvsp[-3].string)); // Task ID
        ((char**)stmt->data)[1] = strdup((yyvsp[-1].string)); // Task Name
        stmt->next = NULL;
        if (inside_function || inside_block) {
            (yyval.stmt) = stmt;
        } else {
            Task* new_task = create_task((yyvsp[-3].string), (yyvsp[-1].string));
            add_task(new_task);
            (yyval.stmt) = NULL;
        }
    }
#line 1313 "parser.tab.c"
    break;

  case 17: /* set_deadline: SET_DEADLINE FOR_TASK IDENTIFIER AS value SEMICOLON  */
#line 141 "parser.y"
    {
        printf("Set deadline for %s as %s\n", (yyvsp[-3].string), (yyvsp[-1].string));
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("set_deadline");
        stmt->data = malloc(sizeof(char*) * 2);
        ((char**)stmt->data)[0] = strdup((yyvsp[-3].string)); // Task ID
        ((char**)stmt->data)[1] = strdup((yyvsp[-1].string)); // Deadline
        stmt->next = NULL;
        if (inside_function || inside_block) {
            (yyval.stmt) = stmt;
        } else {
            Task* task = find_task((yyvsp[-3].string));
            if (task) {
                if (task->deadline) free(task->deadline);
                task->deadline = strdup((yyvsp[-1].string));
            } else {
                printf("Error: Task %s not found.\n", (yyvsp[-3].string));
            }
            (yyval.stmt) = NULL;
        }
    }
#line 1339 "parser.tab.c"
    break;

  case 18: /* set_attribute: SET_ATTRIBUTE IDENTIFIER FOR_TASK IDENTIFIER AS value SEMICOLON  */
#line 166 "parser.y"
    {
        printf("Set attribute %s for %s as %s\n", (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string));
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("set_attribute");
        stmt->data = malloc(sizeof(char*) * 3);
        ((char**)stmt->data)[0] = strdup((yyvsp[-5].string)); // Attribute Key
        ((char**)stmt->data)[1] = strdup((yyvsp[-3].string)); // Task ID
        ((char**)stmt->data)[2] = strdup((yyvsp[-1].string)); // Attribute Value
        stmt->next = NULL;
        if (inside_function || inside_block) {
            (yyval.stmt) = stmt;
        } else {
            Task* task = find_task((yyvsp[-3].string));
            if (task) {
                if (strcmp((yyvsp[-5].string), "priority") == 0) {
                    if (task->priority) free(task->priority);
                    task->priority = strdup((yyvsp[-1].string));
                } else if (strcmp((yyvsp[-5].string), "completion_status") == 0) {
                    if (task->completion_status) free(task->completion_status);
                    task->completion_status = strdup((yyvsp[-1].string));
                } else {
                    // Custom attributes
                    set_task_attribute(task, (yyvsp[-5].string), (yyvsp[-1].string));
                }
            } else {
                printf("Error: Task %s not found.\n", (yyvsp[-3].string));
            }
            (yyval.stmt) = NULL;
        }
    }
#line 1374 "parser.tab.c"
    break;

  case 19: /* mark_as_done: MARK_AS_DONE IDENTIFIER status SEMICOLON  */
#line 200 "parser.y"
    {
        printf("Mark %s as %s\n", (yyvsp[-2].string), (yyvsp[-1].string));
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("mark_as_done");
        stmt->data = strdup((yyvsp[-2].string));
        stmt->next = NULL;
        if (inside_function || inside_block) {
            (yyval.stmt) = stmt;
        } else {
            Task* task = find_task((yyvsp[-2].string));
            if (task) {
                if (task->completion_status) free(task->completion_status);
                task->completion_status = strdup((yyvsp[-1].string));
            } else {
                printf("Error: Task %s not found.\n", (yyvsp[-2].string));
            }
            (yyval.stmt) = NULL;
        }
    }
#line 1398 "parser.tab.c"
    break;

  case 20: /* status: AS_DONE  */
#line 223 "parser.y"
      {
          (yyval.string) = strdup("done");
      }
#line 1406 "parser.tab.c"
    break;

  case 21: /* status: AS_NOT_DONE  */
#line 227 "parser.y"
      {
          (yyval.string) = strdup("not done");
      }
#line 1414 "parser.tab.c"
    break;

  case 22: /* review_all_tasks: REVIEW_ALL_TASKS SEMICOLON  */
#line 234 "parser.y"
    {
        review_all_tasks();
    }
#line 1422 "parser.tab.c"
    break;

  case 23: /* show_me: SHOW_ME value_list SEMICOLON  */
#line 241 "parser.y"
    {
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("show_me");
        stmt->data = (yyvsp[-1].str_list);
        stmt->next = NULL;
        if (inside_function || inside_block) {
            (yyval.stmt) = stmt;
        } else {
            // Execute immediately
            execute_show_me(stmt, NULL, NULL, 0);
            // Free memory
            free(stmt->type);
            free(stmt);
            (yyval.stmt) = NULL;
        }
    }
#line 1443 "parser.tab.c"
    break;

  case 24: /* save_tasks: SAVE_TASKS STRING SEMICOLON  */
#line 261 "parser.y"
    {
        printf("Save tasks to %s\n", (yyvsp[-1].string));
        // Implement saving logic here
    }
#line 1452 "parser.tab.c"
    break;

  case 25: /* load_tasks: LOAD_TASKS STRING SEMICOLON  */
#line 269 "parser.y"
    {
        printf("Load tasks from %s\n", (yyvsp[-1].string));
        // Implement loading logic here
    }
#line 1461 "parser.tab.c"
    break;

  case 26: /* function_definition: DEFINE_FUNCTION IDENTIFIER LPAREN parameter_list RPAREN block  */
#line 277 "parser.y"
    {
        printf("Define function %s\n", (yyvsp[-4].string));
        inside_function = 1;

        Function* new_func = (Function*)malloc(sizeof(Function));
        new_func->name = strdup((yyvsp[-4].string));
        new_func->parameters = (yyvsp[-2].param_data).list;
        new_func->param_count = (yyvsp[-2].param_data).count;
        new_func->body = (yyvsp[0].stmt_list);
        new_func->next = NULL;

        inside_function = 0;
        add_function(new_func);
    }
#line 1480 "parser.tab.c"
    break;

  case 27: /* run_function: RUN_FUNCTION IDENTIFIER LPAREN argument_list RPAREN SEMICOLON  */
#line 295 "parser.y"
    {
        printf("Run function %s\n", (yyvsp[-4].string));
        Function* func = find_function((yyvsp[-4].string));
        if (func) {
            execute_function(func, (yyvsp[-2].param_data).list, (yyvsp[-2].param_data).count);
        } else {
            printf("Error: Function %s not found.\n", (yyvsp[-4].string));
        }
    }
#line 1494 "parser.tab.c"
    break;

  case 28: /* conditional: IF_TIME_LEFT BEFORE value block optional_else  */
#line 308 "parser.y"
    {
        printf("If there's time left before %s\n", (yyvsp[-2].string));
        Statement* stmt = malloc(sizeof(Statement));
        stmt->type = strdup("conditional");
        stmt->data = malloc(sizeof(void*) * 3); // Data[0]: deadline, Data[1]: then_block, Data[2]: else_value
        ((char**)stmt->data)[0] = strdup((yyvsp[-2].string)); // Deadline
        ((Statement**)stmt->data)[1] = (yyvsp[-1].stmt_list);    // Then block
        ((char**)stmt->data)[2] = (yyvsp[0].string);         // Else value
        stmt->next = NULL;
        if (inside_function || inside_block) {
            (yyval.stmt) = stmt;
        } else {
            // Execute immediately
            execute_statement(stmt, NULL, NULL, 0);
            // Free memory
            free(stmt->type);
            free(((char**)stmt->data)[0]);
            free(stmt->data);
            free(stmt);
            (yyval.stmt) = NULL;
        }
    }
#line 1521 "parser.tab.c"
    break;

  case 29: /* optional_else: %empty  */
#line 334 "parser.y"
          {
              (yyval.string) = NULL;
          }
#line 1529 "parser.tab.c"
    break;

  case 30: /* optional_else: OTHERWISE_FOCUS value SEMICOLON  */
#line 338 "parser.y"
          {
              (yyval.string) = strdup((yyvsp[-1].string));
          }
#line 1537 "parser.tab.c"
    break;

  case 31: /* loop: REPEAT_UNTIL_COMPLETE block  */
#line 345 "parser.y"
      {
          printf("Repeat until complete\n");
          Statement* stmt = malloc(sizeof(Statement));
          stmt->type = strdup("repeat_until_complete");
          stmt->data = (yyvsp[0].stmt_list);
          stmt->next = NULL;
          if (inside_function || inside_block) {
              (yyval.stmt) = stmt;
          } else {
              // Execute immediately
              execute_statement(stmt, NULL, NULL, 0);
              // Free memory
              free(stmt->type);
              free(stmt);
              (yyval.stmt) = NULL;
          }
      }
#line 1559 "parser.tab.c"
    break;

  case 32: /* loop: DO_IT_AGAIN NUMBER TIMES block  */
#line 363 "parser.y"
      {
          printf("Do it again %d times\n", (yyvsp[-2].number));
          Statement* stmt = malloc(sizeof(Statement));
          stmt->type = strdup("loop");
          stmt->data = malloc(sizeof(void*) * 2);
          int* times_ptr = malloc(sizeof(int));
          *times_ptr = (yyvsp[-2].number);
          ((void**)stmt->data)[0] = times_ptr;
          ((void**)stmt->data)[1] = (yyvsp[0].stmt_list);
          stmt->next = NULL;
          if (inside_function || inside_block) {
              (yyval.stmt) = stmt;
          } else {
              // Execute immediately
              execute_statement(stmt, NULL, NULL, 0);
              // Free memory
              free(times_ptr);
              free(stmt->data);
              free(stmt->type);
              free(stmt);
              (yyval.stmt) = NULL;
          }
      }
#line 1587 "parser.tab.c"
    break;

  case 33: /* parameter_list: %empty  */
#line 390 "parser.y"
      {
          (yyval.param_data).list = NULL;
          (yyval.param_data).count = 0;
      }
#line 1596 "parser.tab.c"
    break;

  case 34: /* parameter_list: parameters  */
#line 395 "parser.y"
      {
          (yyval.param_data) = (yyvsp[0].param_data);
      }
#line 1604 "parser.tab.c"
    break;

  case 35: /* parameters: IDENTIFIER  */
#line 402 "parser.y"
    {
        (yyval.param_data).list = malloc(2 * sizeof(char*));
        (yyval.param_data).list[0] = strdup((yyvsp[0].string));
        (yyval.param_data).list[1] = NULL;
        (yyval.param_data).count = 1;
    }
#line 1615 "parser.tab.c"
    break;

  case 36: /* parameters: parameters COMMA IDENTIFIER  */
#line 409 "parser.y"
    {
        int i = (yyvsp[-2].param_data).count;
        (yyval.param_data).list = realloc((yyvsp[-2].param_data).list, (i + 2) * sizeof(char*));
        (yyval.param_data).list[i] = strdup((yyvsp[0].string));
        (yyval.param_data).list[i + 1] = NULL;
        (yyval.param_data).count = i + 1;
    }
#line 1627 "parser.tab.c"
    break;

  case 37: /* argument_list: %empty  */
#line 420 "parser.y"
      {
          (yyval.param_data).list = NULL;
          (yyval.param_data).count = 0;
      }
#line 1636 "parser.tab.c"
    break;

  case 38: /* argument_list: arguments  */
#line 425 "parser.y"
      {
          (yyval.param_data) = (yyvsp[0].param_data);
      }
#line 1644 "parser.tab.c"
    break;

  case 39: /* arguments: value  */
#line 432 "parser.y"
    {
        (yyval.param_data).list = malloc(2 * sizeof(char*));
        (yyval.param_data).list[0] = strdup((yyvsp[0].string));
        (yyval.param_data).list[1] = NULL;
        (yyval.param_data).count = 1;
    }
#line 1655 "parser.tab.c"
    break;

  case 40: /* arguments: arguments COMMA value  */
#line 439 "parser.y"
    {
        int i = (yyvsp[-2].param_data).count;
        (yyval.param_data).list = realloc((yyvsp[-2].param_data).list, (i + 2) * sizeof(char*));
        (yyval.param_data).list[i] = strdup((yyvsp[0].string));
        (yyval.param_data).list[i + 1] = NULL;
        (yyval.param_data).count = i + 1;
    }
#line 1667 "parser.tab.c"
    break;

  case 41: /* value_list: value  */
#line 450 "parser.y"
    {
        (yyval.str_list) = malloc(2 * sizeof(char*));
        (yyval.str_list)[0] = strdup((yyvsp[0].string));
        (yyval.str_list)[1] = NULL;
    }
#line 1677 "parser.tab.c"
    break;

  case 42: /* value_list: value_list value  */
#line 456 "parser.y"
    {
        int i = 0;
        while ((yyvsp[-1].str_list)[i] != NULL) i++;
        (yyval.str_list) = realloc((yyvsp[-1].str_list), (i + 2) * sizeof(char*));
        (yyval.str_list)[i] = strdup((yyvsp[0].string));
        (yyval.str_list)[i + 1] = NULL;
    }
#line 1689 "parser.tab.c"
    break;

  case 43: /* value: STRING  */
#line 467 "parser.y"
    {
        (yyval.string) = strdup((yyvsp[0].string));
    }
#line 1697 "parser.tab.c"
    break;

  case 44: /* value: IDENTIFIER  */
#line 471 "parser.y"
    {
        (yyval.string) = strdup((yyvsp[0].string));
    }
#line 1705 "parser.tab.c"
    break;

  case 45: /* block: begin_block func_statements end_block  */
#line 478 "parser.y"
    {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
    }
#line 1713 "parser.tab.c"
    break;

  case 46: /* begin_block: LBRACE  */
#line 484 "parser.y"
           { inside_block++; }
#line 1719 "parser.tab.c"
    break;

  case 47: /* end_block: RBRACE  */
#line 488 "parser.y"
           { inside_block--; }
#line 1725 "parser.tab.c"
    break;

  case 48: /* func_statements: func_statement  */
#line 493 "parser.y"
        {
            (yyval.stmt_list) = (yyvsp[0].stmt);
        }
#line 1733 "parser.tab.c"
    break;

  case 49: /* func_statements: func_statements func_statement  */
#line 497 "parser.y"
        {
            if ((yyvsp[-1].stmt_list) == NULL) {
                (yyval.stmt_list) = (yyvsp[0].stmt);
            } else if ((yyvsp[0].stmt) == NULL) {
                (yyval.stmt_list) = (yyvsp[-1].stmt_list);
            } else {
                Statement* temp = (yyvsp[-1].stmt_list);
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = (yyvsp[0].stmt);
                (yyval.stmt_list) = (yyvsp[-1].stmt_list);
            }
        }
#line 1752 "parser.tab.c"
    break;

  case 50: /* func_statement: mark_as_done  */
#line 514 "parser.y"
                            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1758 "parser.tab.c"
    break;

  case 51: /* func_statement: show_me  */
#line 515 "parser.y"
                            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1764 "parser.tab.c"
    break;

  case 52: /* func_statement: define_task  */
#line 516 "parser.y"
                            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1770 "parser.tab.c"
    break;

  case 53: /* func_statement: set_deadline  */
#line 517 "parser.y"
                            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1776 "parser.tab.c"
    break;

  case 54: /* func_statement: set_attribute  */
#line 518 "parser.y"
                            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1782 "parser.tab.c"
    break;

  case 55: /* func_statement: loop  */
#line 519 "parser.y"
                            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1788 "parser.tab.c"
    break;

  case 56: /* func_statement: conditional  */
#line 520 "parser.y"
                            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1794 "parser.tab.c"
    break;


#line 1798 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 523 "parser.y"


/* Auxiliary function implementations */

Task* create_task(char* id, char* name) {
    Task* task = malloc(sizeof(Task));
    task->id = strdup(id);
    task->name = strdup(name);
    task->deadline = NULL;
    task->completion_status = strdup("not done");
    task->priority = NULL;
    task->attributes = NULL;
    task->next = NULL;
    return task;
}

void add_task(Task* task) {
    task->next = task_list;
    task_list = task;
}

Task* find_task(char* id) {
    Task* current = task_list;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void review_all_tasks() {
    printf("Reviewing all tasks:\n");
    printf("Task ID              | Name                 | Deadline        | Done       | Priority   | Attributes\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    Task* current = task_list;
    while (current != NULL) {
        printf("%-20s| %-20s| %-15s| %-10s| %-10s| ", current->id, current->name ? current->name : "N/A", current->deadline ? current->deadline : "N/A", current->completion_status ? current->completion_status : "N/A", current->priority ? current->priority : "N/A");
        // Print custom attributes
        Attribute* attr = current->attributes;
        while (attr != NULL) {
            printf("%s: \"%s\" ", attr->key, attr->value);
            attr = attr->next;
        }
        printf("\n");
        current = current->next;
    }
}

void free_task_attributes(Task* task) {
    Attribute* current = task->attributes;
    while (current != NULL) {
        Attribute* temp = current;
        current = current->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
}

void free_tasks() {
    Task* current = task_list;
    while (current != NULL) {
        Task* temp = current;
        current = current->next;
        free(temp->id);
        free(temp->name);
        if (temp->deadline) free(temp->deadline);
        if (temp->completion_status) free(temp->completion_status);
        if (temp->priority) free(temp->priority);
        free_task_attributes(temp);
        free(temp);
    }
}

void set_task_attribute(Task* task, char* key, char* value) {
    Attribute* new_attr = malloc(sizeof(Attribute));
    new_attr->key = strdup(key);
    new_attr->value = strdup(value);
    new_attr->next = task->attributes;
    task->attributes = new_attr;
}

char* get_task_attribute(Task* task, char* key) {
    Attribute* current = task->attributes;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void add_function(Function* func) {
    func->next = function_list;
    function_list = func;
}

Function* find_function(char* name) {
    Function* current = function_list;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void execute_function(Function* func, char** arguments, int arg_count) {
    int param_count = func->param_count;
    char** param_names = func->parameters;
    char** param_values = arguments;

    if (param_count != arg_count) {
        printf("Error: Function %s expects %d arguments, but %d were provided.\n", func->name, param_count, arg_count);
        return;
    }

    // Execute statements
    Statement* stmt = func->body;
    while (stmt != NULL) {
        execute_statement(stmt, param_names, param_values, param_count);
        stmt = stmt->next;
    }
}

void execute_statement(Statement* stmt, char** param_names, char** param_values, int param_count) {
    if (!stmt || !stmt->type) return;

    if (strcmp(stmt->type, "show_me") == 0) {
        execute_show_me(stmt, param_names, param_values, param_count);
    } else if (strcmp(stmt->type, "mark_as_done") == 0) {
        execute_mark_as_done(stmt, param_names, param_values, param_count);
    } else if (strcmp(stmt->type, "loop") == 0) {
        void** data = (void**)stmt->data;
        int times = *((int*)data[0]);
        Statement* block = (Statement*)data[1];
        if (block) {
            for (int i = 0; i < times; i++) {
                Statement* inner_stmt = block;
                while (inner_stmt != NULL) {
                    execute_statement(inner_stmt, param_names, param_values, param_count);
                    inner_stmt = inner_stmt->next;
                }
            }
        } else {
            printf("Warning: Loop block is empty.\n");
        }
    } else if (strcmp(stmt->type, "repeat_until_complete") == 0) {
        Statement* block = (Statement*)stmt->data;
        int task_completed = 0;
        while (!task_completed) {
            // Check if any task is marked as "not done"
            Task* current = task_list;
            task_completed = 1; // Assume all tasks are complete
            while (current != NULL) {
                if (strcmp(current->completion_status, "not done") == 0) {
                    task_completed = 0; // Found an incomplete task
                    break;
                }
                current = current->next;
            }
            if (task_completed) {
                break; // All tasks are complete
            }
            // Execute the block
            Statement* inner_stmt = block;
            while (inner_stmt != NULL) {
                execute_statement(inner_stmt, param_names, param_values, param_count);
                inner_stmt = inner_stmt->next;
            }
        }
    } else if (strcmp(stmt->type, "conditional") == 0) {
        char* deadline = ((char**)stmt->data)[0];
        Statement* then_block = ((Statement**)stmt->data)[1];
        char* else_value = ((char**)stmt->data)[2];

        if (check_deadline(deadline)) {
            // There's still time before the deadline
            Statement* inner_stmt = then_block;
            while (inner_stmt != NULL) {
                execute_statement(inner_stmt, param_names, param_values, param_count);
                inner_stmt = inner_stmt->next;
            }
        } else {
            // The deadline has passed
            if (else_value != NULL) {
                printf("Otherwise focus on %s\n", else_value);
            }
        }
    } else if (strcmp(stmt->type, "define_task") == 0) {
        char* id = ((char**)stmt->data)[0];
        char* name = ((char**)stmt->data)[1];
        Task* new_task = create_task(id, name);
        add_task(new_task);
    } else if (strcmp(stmt->type, "set_deadline") == 0) {
        char* id = ((char**)stmt->data)[0];
        char* deadline = ((char**)stmt->data)[1];
        Task* task = find_task(id);
        if (task) {
            if (task->deadline) free(task->deadline);
            task->deadline = strdup(deadline);
        } else {
            printf("Error: Task %s not found.\n", id);
        }
    } else if (strcmp(stmt->type, "set_attribute") == 0) {
        char* key = ((char**)stmt->data)[0];
        char* id = ((char**)stmt->data)[1];
        char* value = ((char**)stmt->data)[2];
        Task* task = find_task(id);
        if (task) {
            if (strcmp(key, "priority") == 0) {
                if (task->priority) free(task->priority);
                task->priority = strdup(value);
            } else if (strcmp(key, "completion_status") == 0) {
                if (task->completion_status) free(task->completion_status);
                task->completion_status = strdup(value);
            } else {
                set_task_attribute(task, key, value);
            }
        } else {
            printf("Error: Task %s not found.\n", id);
        }
    }
    // Add other statement types as needed
}

void execute_show_me(Statement* stmt, char** param_names, char** param_values, int param_count) {
    char** values = (char**)stmt->data;
    for (int i = 0; values[i] != NULL; i++) {
        char* val = values[i];
        int substituted = 0;
        // Substitute parameters
        for (int j = 0; j < param_count; j++) {
            if (strcmp(val, param_names[j]) == 0) {
                val = param_values[j];
                substituted = 1;
                break;
            }
        }
        // Remove quotes if not substituted
        if (!substituted && val[0] == '"' && val[strlen(val) - 1] == '"') {
            val[strlen(val) - 1] = '\0'; // Remove the last quote
            val++; // Skip the first quote
        }
        printf("%s", val);
    }
    printf("\n");
}

void execute_mark_as_done(Statement* stmt, char** param_names, char** param_values, int param_count) {
    char* task_name = (char*)stmt->data;
    // Substitute parameters
    for (int j = 0; j < param_count; j++) {
        if (strcmp(task_name, param_names[j]) == 0) {
            task_name = param_values[j];
            break;
        }
    }
    // Mark the task as done
    Task* task = find_task(task_name);
    if (task) {
        if (task->completion_status) free(task->completion_status);
        task->completion_status = strdup("done");
    } else {
        printf("Error: Task %s not found.\n", task_name);
    }
}

int check_deadline(char* deadline_str) {
    // Remove quotes from the string
    if (deadline_str[0] == '"' && deadline_str[strlen(deadline_str) - 1] == '"') {
        deadline_str[strlen(deadline_str) - 1] = '\0';
        deadline_str++;
    }

    time_t now = time(NULL);
    struct tm deadline_tm = {0};
    strptime(deadline_str, "%Y-%m-%d", &deadline_tm);
    time_t deadline_time = mktime(&deadline_tm);

    // Return 1 if there's still time, 0 if the deadline has passed
    return difftime(deadline_time, now) > 0;
}

int main(int argc, char* argv[]) {
    extern FILE* yyin;
    yydebug = 0;  // Set to 1 to enable debugging

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }
    if (yyparse() == 0) {
        printf("Parsing concluído com sucesso.\n");
    } else {
        printf("Parsing failed.\n");
    }
    free_tasks();  // Clean up allocated memory for tasks
    // Free functions and statements if necessary
    return EXIT_SUCCESS;
}

void yyerror(const char* s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}
