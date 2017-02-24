/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     PRINT = 266,
     WHILE = 267,
     IF = 268,
     ELSE = 269,
     ENDIF = 270,
     STRUCT = 271,
     ARRAY = 272,
     RETURN = 273,
     JUNK_TOKEN = 274
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
#define PRINT 266
#define WHILE 267
#define IF 268
#define ELSE 269
#define ENDIF 270
#define STRUCT 271
#define ARRAY 272
#define RETURN 273
#define JUNK_TOKEN 274




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
    cSymbol*        symbol;
    cSymbolTable::symbolTable_t*  sym_table;
    cDeclNode*      decl_node;
    cDeclsNode*     decls_node;
    cVarExprNode*   var_expr;
    cFuncDeclNode*	func_decl_node;
    cFuncExprNode*	func_expr_node;
    cParamListNode*	param_list_node;
    cParamsNode* 	  params_node;
    }
/* Line 1529 of yacc.c.  */
#line 107 "langparse.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
