#pragma once
//**************************************
// lex.h
//
// Defines global symbols used the the flex generated lexer and 
// bison generated parser.
//
// Author: Phil Howard phil.howard@oit.edu
//

#include "cSymbol.h"

// parse function generated by bison
int yyparse();

// lexer function generated by flex
int yylex();

typedef union
{
    int token;
    cSymbol *symbol;
} yylval_t;

extern cSymbolTable g_SymbolTable;
extern yylval_t yylval;
extern char *yytext;        // text of the current token
extern int yylineno;        // line number of current token
extern FILE *yyin;          // input file for lexer
