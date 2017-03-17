/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     TYPE_ID = 259,
     CHAR_VAL = 260,
     INT_VAL = 261,
     FLOAT_VAL = 262,
     AND = 263,
     OR = 264,
     EQUALS = 265,
     NOT_EQUALS = 266,
     PRINT = 267,
     WHILE = 268,
     IF = 269,
     ELSE = 270,
     ENDIF = 271,
     STRUCT = 272,
     ARRAY = 273,
     RETURN = 274,
     JUNK_TOKEN = 275
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define TYPE_ID 259
#define CHAR_VAL 260
#define INT_VAL 261
#define FLOAT_VAL 262
#define AND 263
#define OR 264
#define EQUALS 265
#define NOT_EQUALS 266
#define PRINT 267
#define WHILE 268
#define IF 269
#define ELSE 270
#define ENDIF 271
#define STRUCT 272
#define ARRAY 273
#define RETURN 274
#define JUNK_TOKEN 275




/* Copy the first part of user declarations.  */
#line 1 "lang.y"

//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Phil Howard
// zachary.wentworth@oit.edu
//
// Date: Jan. 18, 2016
//
#include <iostream>
#include "lex.h"
#include "astnodes.h"



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "lang.y"
{
    int             int_val;
    double          float_val;
    cAstNode*       ast_node;
    cProgramNode*   program_node;
    cBlockNode*     block_node;
    cStmtsNode*     stmts_node;
    cStmtNode*      stmt_node;
    cExprNode*      expr_node;
    cFuncDeclNode*  func_node;
    cFuncExprNode*  funccall_node;
    cSymbol*        symbol;
    cSymbolTable::symbolTable_t*  sym_table;
    cDeclsNode*     decls_node;
    cDeclNode*      decl_node;
    cVarExprNode*   varref_node;
    cParamListNode* params_node;
    }
/* Line 193 of yacc.c.  */
#line 172 "langparse.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */
#line 40 "lang.y"

    int yyerror(const char *msg);

    cAstNode *yyast_root;


/* Line 216 of yacc.c.  */
#line 202 "langparse.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    35,     2,     2,
      27,    26,    33,    31,    28,    32,    30,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
       2,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    22,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    10,    14,    16,    18,    21,    23,
      26,    29,    32,    34,    37,    40,    46,    53,    56,    62,
      67,    71,    74,    78,    82,    84,    86,    89,    91,    99,
     109,   115,   121,   126,   131,   134,   136,   140,   143,   148,
     152,   156,   161,   163,   165,   167,   171,   173,   175,   179,
     183,   185,   189,   193,   195,   199,   203,   207,   209,   213,
     215,   217
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    -1,    39,    41,    51,    40,    -1,
      39,    51,    40,    -1,    21,    -1,    22,    -1,    41,    42,
      -1,    42,    -1,    43,    23,    -1,    44,    23,    -1,    45,
      23,    -1,    46,    -1,     1,    23,    -1,     4,     3,    -1,
      17,    39,    41,    40,     3,    -1,    18,     4,    24,     6,
      25,     3,    -1,    47,    23,    -1,    47,    21,    41,    51,
      22,    -1,    47,    21,    51,    22,    -1,    48,    49,    26,
      -1,    48,    26,    -1,     4,     3,    27,    -1,    49,    28,
      50,    -1,    50,    -1,    43,    -1,    51,    52,    -1,    52,
      -1,    14,    27,    59,    26,    51,    16,    23,    -1,    14,
      27,    59,    26,    51,    15,    51,    16,    23,    -1,    13,
      27,    59,    26,    52,    -1,    12,    27,    59,    26,    23,
      -1,    56,    29,    59,    23,    -1,    56,    29,    53,    23,
      -1,    53,    23,    -1,    38,    -1,    19,    59,    23,    -1,
       1,    23,    -1,     3,    27,    57,    26,    -1,     3,    27,
      26,    -1,    54,    30,    55,    -1,    54,    24,    59,    25,
      -1,    55,    -1,     3,    -1,    54,    -1,    57,    28,    58,
      -1,    58,    -1,    59,    -1,    59,    10,    60,    -1,    59,
      11,    60,    -1,    60,    -1,    60,    31,    61,    -1,    60,
      32,    61,    -1,    61,    -1,    61,    33,    62,    -1,    61,
      34,    62,    -1,    61,    35,    62,    -1,    62,    -1,    27,
      59,    26,    -1,     6,    -1,     7,    -1,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    93,    93,   100,   101,   103,   105,   107,   108,   109,
     110,   111,   112,   113,   115,   116,   118,   121,   125,   131,
     136,   140,   141,   145,   147,   149,   151,   152,   154,   156,
     158,   160,   162,   163,   164,   165,   166,   167,   169,   170,
     172,   173,   174,   176,   178,   180,   181,   183,   185,   186,
     187,   189,   190,   191,   193,   194,   195,   196,   198,   199,
     200,   201
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "TYPE_ID", "CHAR_VAL",
  "INT_VAL", "FLOAT_VAL", "AND", "OR", "EQUALS", "NOT_EQUALS", "PRINT",
  "WHILE", "IF", "ELSE", "ENDIF", "STRUCT", "ARRAY", "RETURN",
  "JUNK_TOKEN", "'{'", "'}'", "';'", "'['", "']'", "')'", "'('", "','",
  "'='", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept", "program",
  "block", "open", "close", "decls", "decl", "var_decl", "struct_decl",
  "array_decl", "func_decl", "func_header", "func_prefix", "paramsspec",
  "paramspec", "stmts", "stmt", "func_call", "varref", "varpart", "lval",
  "params", "param", "expr", "addit", "term", "fact", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   123,   125,    59,    91,    93,    41,    40,    44,    61,
      46,    43,    45,    42,    47,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    40,    41,    41,    42,
      42,    42,    42,    42,    43,    44,    45,    46,    46,    46,
      47,    47,    48,    49,    49,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    54,    55,    56,    57,    57,    58,    59,    59,
      59,    60,    60,    60,    61,    61,    61,    61,    62,    62,
      62,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     3,     1,     1,     2,     1,     2,
       2,     2,     1,     2,     2,     5,     6,     2,     5,     4,
       3,     2,     3,     3,     1,     1,     2,     1,     7,     9,
       5,     5,     4,     4,     2,     1,     3,     2,     4,     3,
       3,     4,     1,     1,     1,     3,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     2,     0,     1,     0,    43,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     8,     0,     0,
       0,    12,     0,     0,     0,    27,     0,    44,    42,     0,
      13,     0,    14,     0,     0,     0,     0,     0,    43,    59,
      60,     0,    61,     0,    50,    53,    57,     7,     0,     9,
      10,    11,     0,    17,     0,    21,    25,     0,    24,     0,
       6,     4,    26,    34,     0,     0,     0,    39,     0,    46,
      47,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     3,     0,     0,
      14,    20,     0,    37,     0,    40,     0,     0,    38,     0,
       0,     0,     0,    13,     0,     0,    58,    48,    49,    51,
      52,    54,    55,    56,     0,    19,    23,    41,    33,    32,
      45,    31,    30,     0,    15,     0,    18,     0,     0,    16,
       0,    28,     0,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    15,     4,    61,    16,    17,    18,    19,    20,
      21,    22,    23,    57,    58,    24,    25,    26,    42,    28,
      29,    68,    69,    70,    44,    45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int16 yypact[] =
{
       0,   -43,    40,   -43,   129,   -43,    20,    28,    59,    67,
      82,    90,     0,   121,    26,   -43,   129,   -43,    73,   108,
     132,   -43,    29,     4,    69,   -43,   133,   -17,   -43,   128,
     136,    12,   138,    26,    26,    26,    10,   135,   -43,   -43,
     -43,    26,   -17,    -1,    37,   105,   -43,   -43,    69,   -43,
     -43,   -43,   129,   -43,   167,   -43,   -43,    21,   -43,   149,
     -43,   -43,   -43,   -43,    26,   168,    39,   -43,    96,   -43,
       6,   -43,    25,    50,    54,   150,    85,   169,    89,    26,
      26,   -43,    26,    26,    26,    26,    26,   -43,   129,    92,
     -43,   -43,   170,   -43,   110,   -43,   153,    48,   -43,    26,
     160,   179,   179,   -43,   182,   162,   -43,    37,    37,   105,
     105,   -43,   -43,   -43,   115,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   148,   -43,   185,   -43,   179,   166,   -43,
     165,   -43,   171,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   190,   183,   -42,     5,   -13,   -18,   -43,   -43,
     -43,   -43,   -43,   -43,   104,   -15,   -22,   131,    -4,   134,
     -43,   -43,   102,   -10,    -2,    62,    68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -38
static const yytype_int16 yytable[] =
{
      27,    48,    62,    47,    43,    56,    87,    64,    54,    79,
      80,    75,    27,    65,     8,    38,    79,    80,    39,    40,
      27,     1,    81,    72,    73,    74,    62,    12,    13,    38,
      55,    78,    39,    40,   104,    79,    80,    89,    67,    41,
       5,    76,     7,    30,    27,    39,    40,    91,    27,    92,
      52,   100,    53,    41,    94,    31,    97,    88,    79,    80,
      79,    80,    32,    47,    79,    80,    41,    62,    82,    83,
      59,   119,     7,   114,    56,    47,   101,   107,   108,   122,
     102,     9,    10,    11,    27,    27,    75,   123,    14,     8,
       1,    60,    62,    59,    33,     7,    49,    27,    27,    79,
      80,    62,    12,    13,     9,    10,    11,    60,    62,    34,
      27,    14,   130,     1,   115,   106,    59,    35,     7,    27,
      79,    80,    98,    27,    99,    37,    27,     9,    10,    11,
       6,    50,     7,     8,    14,   117,     1,   126,    84,    85,
      86,     9,    10,    11,   109,   110,    12,    13,    14,    59,
       1,     7,   111,   112,   113,    51,    63,    66,   -37,    77,
       9,    10,    11,   127,   128,    71,    59,    14,     7,     1,
      90,    38,    93,   103,    54,   105,   118,     9,    10,    11,
      59,   132,     7,   121,    14,   124,     1,   125,   129,   131,
       3,     9,    10,    11,   133,    36,   116,    96,    14,    95,
       1,   120
};

static const yytype_uint8 yycheck[] =
{
       4,    16,    24,    16,    14,    23,    48,    24,     4,    10,
      11,     1,    16,    30,     4,     3,    10,    11,     6,     7,
      24,    21,    23,    33,    34,    35,    48,    17,    18,     3,
      26,    41,     6,     7,    76,    10,    11,    52,    26,    27,
       0,    36,     3,    23,    48,     6,     7,    26,    52,    28,
      21,    26,    23,    27,    64,    27,    66,    52,    10,    11,
      10,    11,     3,    76,    10,    11,    27,    89,    31,    32,
       1,    23,     3,    88,    92,    88,    26,    79,    80,   101,
      26,    12,    13,    14,    88,    89,     1,   102,    19,     4,
      21,    22,   114,     1,    27,     3,    23,   101,   102,    10,
      11,   123,    17,    18,    12,    13,    14,    22,   130,    27,
     114,    19,   127,    21,    22,    26,     1,    27,     3,   123,
      10,    11,    26,   127,    28,     4,   130,    12,    13,    14,
       1,    23,     3,     4,    19,    25,    21,    22,    33,    34,
      35,    12,    13,    14,    82,    83,    17,    18,    19,     1,
      21,     3,    84,    85,    86,    23,    23,    29,    22,    24,
      12,    13,    14,    15,    16,    27,     1,    19,     3,    21,
       3,     3,    23,    23,     4,     6,    23,    12,    13,    14,
       1,    16,     3,    23,    19,     3,    21,    25,     3,    23,
       0,    12,    13,    14,    23,    12,    92,    66,    19,    65,
      21,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    37,    38,    39,     0,     1,     3,     4,    12,
      13,    14,    17,    18,    19,    38,    41,    42,    43,    44,
      45,    46,    47,    48,    51,    52,    53,    54,    55,    56,
      23,    27,     3,    27,    27,    27,    39,     4,     3,     6,
       7,    27,    54,    59,    60,    61,    62,    42,    51,    23,
      23,    23,    21,    23,     4,    26,    43,    49,    50,     1,
      22,    40,    52,    23,    24,    30,    29,    26,    57,    58,
      59,    27,    59,    59,    59,     1,    41,    24,    59,    10,
      11,    23,    31,    32,    33,    34,    35,    40,    41,    51,
       3,    26,    28,    23,    59,    55,    53,    59,    26,    28,
      26,    26,    26,    23,    40,     6,    26,    60,    60,    61,
      61,    62,    62,    62,    51,    22,    50,    25,    23,    23,
      58,    23,    52,    51,     3,    25,    22,    15,    16,     3,
      51,    23,    16,    23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 93 "lang.y"
    { (yyval.program_node) = new cProgramNode((yyvsp[(1) - (1)].block_node));
                                  yyast_root = (yyval.program_node);
                                  if (yynerrs == 0)
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                ;}
    break;

  case 3:
#line 100 "lang.y"
    { (yyval.block_node) = new cBlockNode((yyvsp[(2) - (4)].decls_node), (yyvsp[(3) - (4)].stmts_node)); ;}
    break;

  case 4:
#line 101 "lang.y"
    { (yyval.block_node) = new cBlockNode(nullptr, (yyvsp[(2) - (3)].stmts_node)); ;}
    break;

  case 5:
#line 103 "lang.y"
    { (yyval.sym_table) = g_SymbolTable.IncreaseScope(); ;}
    break;

  case 6:
#line 105 "lang.y"
    { (yyval.sym_table) = g_SymbolTable.DecreaseScope(); ;}
    break;

  case 7:
#line 107 "lang.y"
    { (yyval.decls_node) = (yyvsp[(1) - (2)].decls_node); (yyval.decls_node)->Insert((yyvsp[(2) - (2)].decl_node)); ;}
    break;

  case 8:
#line 108 "lang.y"
    { (yyval.decls_node) = new cDeclsNode((yyvsp[(1) - (1)].decl_node)); ;}
    break;

  case 9:
#line 109 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node); ;}
    break;

  case 10:
#line 110 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node); ;}
    break;

  case 11:
#line 111 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node); ;}
    break;

  case 12:
#line 112 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (1)].func_node); ;}
    break;

  case 13:
#line 113 "lang.y"
    { (yyval.decl_node) = nullptr; ;}
    break;

  case 14:
#line 115 "lang.y"
    { (yyval.decl_node) = new cVarDeclNode((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].symbol)); ;}
    break;

  case 15:
#line 117 "lang.y"
    { (yyval.decl_node) = new cStructDeclNode((yyvsp[(2) - (5)].sym_table), (yyvsp[(3) - (5)].decls_node), (yyvsp[(5) - (5)].symbol)); ;}
    break;

  case 16:
#line 119 "lang.y"
    { (yyval.decl_node) = new cArrayDeclNode((yyvsp[(2) - (6)].symbol), (yyvsp[(6) - (6)].symbol), (yyvsp[(4) - (6)].int_val)); ;}
    break;

  case 17:
#line 122 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (2)].func_node);
                                  g_SymbolTable.DecreaseScope();
                                ;}
    break;

  case 18:
#line 126 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (5)].func_node);
                                  (yyval.func_node)->AddDecls((yyvsp[(3) - (5)].decls_node));
                                  (yyval.func_node)->AddStmts((yyvsp[(4) - (5)].stmts_node));
                                  g_SymbolTable.DecreaseScope();
                                ;}
    break;

  case 19:
#line 132 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (4)].func_node);
                                  (yyval.func_node)->AddStmts((yyvsp[(3) - (4)].stmts_node));
                                  g_SymbolTable.DecreaseScope();
                                ;}
    break;

  case 20:
#line 137 "lang.y"
    {
                                  (yyval.func_node) = (yyvsp[(1) - (3)].func_node); (yyval.func_node)->AddParams((yyvsp[(2) - (3)].decls_node));
                                ;}
    break;

  case 21:
#line 140 "lang.y"
    { (yyval.func_node) = (yyvsp[(1) - (2)].func_node); (yyval.func_node)->AddParams(nullptr);;}
    break;

  case 22:
#line 142 "lang.y"
    { (yyval.func_node) = new cFuncDeclNode((yyvsp[(1) - (3)].symbol), (yyvsp[(2) - (3)].symbol));
                                  g_SymbolTable.IncreaseScope();
                                ;}
    break;

  case 23:
#line 146 "lang.y"
    { (yyval.decls_node) = (yyvsp[(1) - (3)].decls_node); (yyval.decls_node)->Insert((yyvsp[(3) - (3)].decl_node)); ;}
    break;

  case 24:
#line 147 "lang.y"
    { (yyval.decls_node) = new cParamsNode((yyvsp[(1) - (1)].decl_node)); ;}
    break;

  case 25:
#line 149 "lang.y"
    { (yyval.decl_node) = (yyvsp[(1) - (1)].decl_node); ;}
    break;

  case 26:
#line 151 "lang.y"
    { (yyval.stmts_node) = (yyvsp[(1) - (2)].stmts_node); (yyval.stmts_node)->Insert((yyvsp[(2) - (2)].stmt_node)); ;}
    break;

  case 27:
#line 152 "lang.y"
    { (yyval.stmts_node) = new cStmtsNode((yyvsp[(1) - (1)].stmt_node)); ;}
    break;

  case 28:
#line 155 "lang.y"
    { (yyval.stmt_node) = new cIfNode((yyvsp[(3) - (7)].expr_node), (yyvsp[(5) - (7)].stmts_node), nullptr); ;}
    break;

  case 29:
#line 157 "lang.y"
    { (yyval.stmt_node) = new cIfNode((yyvsp[(3) - (9)].expr_node), (yyvsp[(5) - (9)].stmts_node), (yyvsp[(7) - (9)].stmts_node)); ;}
    break;

  case 30:
#line 159 "lang.y"
    { (yyval.stmt_node) = new cWhileNode((yyvsp[(3) - (5)].expr_node), (yyvsp[(5) - (5)].stmt_node)); ;}
    break;

  case 31:
#line 161 "lang.y"
    { (yyval.stmt_node) = new cPrintNode((yyvsp[(3) - (5)].expr_node)); ;}
    break;

  case 32:
#line 162 "lang.y"
    { (yyval.stmt_node) = new cAssignNode((yyvsp[(1) - (4)].varref_node), (yyvsp[(3) - (4)].expr_node)); ;}
    break;

  case 33:
#line 163 "lang.y"
    { (yyval.stmt_node) = new cAssignNode((yyvsp[(1) - (4)].varref_node), (yyvsp[(3) - (4)].funccall_node)); ;}
    break;

  case 34:
#line 164 "lang.y"
    { (yyval.stmt_node) = (yyvsp[(1) - (2)].funccall_node); ;}
    break;

  case 35:
#line 165 "lang.y"
    { (yyval.stmt_node) = (yyvsp[(1) - (1)].block_node); ;}
    break;

  case 36:
#line 166 "lang.y"
    { (yyval.stmt_node) = new cReturnNode((yyvsp[(2) - (3)].expr_node)); ;}
    break;

  case 37:
#line 167 "lang.y"
    { (yyval.stmt_node) = nullptr; ;}
    break;

  case 38:
#line 169 "lang.y"
    { (yyval.funccall_node) = new cFuncExprNode((yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].params_node)); ;}
    break;

  case 39:
#line 170 "lang.y"
    { (yyval.funccall_node) = new cFuncExprNode((yyvsp[(1) - (3)].symbol), nullptr); ;}
    break;

  case 40:
#line 172 "lang.y"
    { (yyval.varref_node) = (yyvsp[(1) - (3)].varref_node); (yyval.varref_node)->AddElement((yyvsp[(3) - (3)].symbol)); ;}
    break;

  case 41:
#line 173 "lang.y"
    { (yyval.varref_node) = (yyvsp[(1) - (4)].varref_node); (yyval.varref_node)->AddElement((yyvsp[(3) - (4)].expr_node)); ;}
    break;

  case 42:
#line 174 "lang.y"
    { (yyval.varref_node) = new cVarExprNode((yyvsp[(1) - (1)].symbol)); ;}
    break;

  case 43:
#line 176 "lang.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;

  case 44:
#line 178 "lang.y"
    { (yyval.varref_node) = (yyvsp[(1) - (1)].varref_node); ;}
    break;

  case 45:
#line 180 "lang.y"
    { (yyval.params_node) = (yyvsp[(1) - (3)].params_node); (yyval.params_node)->Insert((yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 46:
#line 181 "lang.y"
    { (yyval.params_node) = new cParamListNode((yyvsp[(1) - (1)].expr_node)); ;}
    break;

  case 47:
#line 183 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); ;}
    break;

  case 48:
#line 185 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), (yyvsp[(2) - (3)].int_val), (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 49:
#line 186 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), (yyvsp[(2) - (3)].int_val), (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 50:
#line 187 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); ;}
    break;

  case 51:
#line 189 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '+', (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 52:
#line 190 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '-', (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 53:
#line 191 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); ;}
    break;

  case 54:
#line 193 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '*', (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 55:
#line 194 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '/', (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 56:
#line 195 "lang.y"
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[(1) - (3)].expr_node), '%', (yyvsp[(3) - (3)].expr_node)); ;}
    break;

  case 57:
#line 196 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node); ;}
    break;

  case 58:
#line 198 "lang.y"
    { (yyval.expr_node) = (yyvsp[(2) - (3)].expr_node); ;}
    break;

  case 59:
#line 199 "lang.y"
    { (yyval.expr_node) = new cIntExprNode((yyvsp[(1) - (1)].int_val)); ;}
    break;

  case 60:
#line 200 "lang.y"
    { (yyval.expr_node) = new cFloatExprNode((yyvsp[(1) - (1)].float_val)); ;}
    break;

  case 61:
#line 201 "lang.y"
    { (yyval.expr_node) = (yyvsp[(1) - (1)].varref_node); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1864 "langparse.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 203 "lang.y"


// Function to format error messages
int yyerror(const char *msg)
{
    std::cout << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

// Function that gets called when a semantic error happens
void SemanticError(std::string error)
{
    std::cout << "ERROR: " << error << " on line " << yylineno << "\n";
    yynerrs++;
}

