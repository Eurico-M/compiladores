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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 57 "parser.bison"

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int yyline;
extern char* yytext;
extern FILE* yyin;
extern void yyerror(const char* msg);
extern Stm* program;

#line 62 "parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_INT = 258,               /* TOKEN_INT  */
    TOKEN_FLOAT = 259,             /* TOKEN_FLOAT  */
    TOKEN_ID = 260,                /* TOKEN_ID  */
    TOKEN_STRING = 261,            /* TOKEN_STRING  */
    TOKEN_PLUS = 262,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 263,             /* TOKEN_MINUS  */
    TOKEN_MULT = 264,              /* TOKEN_MULT  */
    TOKEN_DIV = 265,               /* TOKEN_DIV  */
    TOKEN_MOD = 266,               /* TOKEN_MOD  */
    TOKEN_EQUAL = 267,             /* TOKEN_EQUAL  */
    TOKEN_DIFF = 268,              /* TOKEN_DIFF  */
    TOKEN_LESS = 269,              /* TOKEN_LESS  */
    TOKEN_GREATER = 270,           /* TOKEN_GREATER  */
    TOKEN_LESS_EQUAL = 271,        /* TOKEN_LESS_EQUAL  */
    TOKEN_GREATER_EQUAL = 272,     /* TOKEN_GREATER_EQUAL  */
    TOKEN_EOF = 273,               /* TOKEN_EOF  */
    TOKEN_ASSIGN = 274,            /* TOKEN_ASSIGN  */
    TOKEN_SEMI = 275,              /* TOKEN_SEMI  */
    TOKEN_COLON = 276,             /* TOKEN_COLON  */
    TOKEN_IF = 277,                /* TOKEN_IF  */
    TOKEN_THEN = 278,              /* TOKEN_THEN  */
    TOKEN_ELSE = 279,              /* TOKEN_ELSE  */
    TOKEN_WHILE = 280,             /* TOKEN_WHILE  */
    TOKEN_LOOP = 281,              /* TOKEN_LOOP  */
    TOKEN_WITH = 282,              /* TOKEN_WITH  */
    TOKEN_USE = 283,               /* TOKEN_USE  */
    TOKEN_PROC = 284,              /* TOKEN_PROC  */
    TOKEN_IS = 285,                /* TOKEN_IS  */
    TOKEN_BEGIN = 286,             /* TOKEN_BEGIN  */
    TOKEN_END = 287,               /* TOKEN_END  */
    TOKEN_LPAREN = 288,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 289             /* TOKEN_RPAREN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.bison"

    int int_val;
    float float_val;
    char* string_val;
    //bool bool_val;
    Stm* stm_val;
    Expr* expr_val;
    ArExpr* arExpr_val;
    BoolExpr* boolExpr_val;
    Dclr* dclr_val;

#line 125 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
