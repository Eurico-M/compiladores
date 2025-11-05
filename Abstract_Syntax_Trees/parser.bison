// Tokens
%token
  INT

// Operator associativity & precedence
%left PLUS MINUS
%left TIMES DIV MOD
%left EQUAL DIFF LT GT LEQ GEQ

// Root-level grammar symbol
%start program;

// Types/values in association to grammar symbols.
%union {
  int intValue;
  Expr* exprValue;
  BoolExpr* boolExprValue;
}

%type <intValue> INT
%type <exprValue> expr
%type <boolExprValue> boolExpr


// Use "%code requires" to make declarations go
// into both parser.c and parser.h
%code requires {
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int yyline;
extern char* yytext;
extern FILE* yyin;
extern void yyerror(const char* msg);
extern Expr* root;
}

%%
program:
  expr { root = $1; }
  |
  boolExpr { root = $1; }
  ;

expr:
  INT { $$ = ast_integer($1); }
  |
  expr PLUS expr { $$ = ast_operation(PLUS, $1, $3); }
  |
  expr MINUS expr { $$ = ast_operation(MINUS, $1, $3); }
  |
  expr TIMES expr { $$ = ast_operation(TIMES, $1, $3); }
  |
  expr DIV expr { $$ = ast_operation(DIV, $1, $3); }
  |
  expr MOD expr { $$ = ast_operation(MOD, $1, $3); }
  ;

boolExpr:
  INT { $$ = ast_bool_integer($1); }
  |
  expr EQUAL expr { $$ = ast_bool_operation(EQUAL, $1, $3); }
  |
  expr DIFF expr { $$ = ast_bool_operation(DIFF, $1, $3); }
  |
  expr LT expr { $$ = ast_bool_operation(LT, $1, $3); }
  |
  expr GT expr { $$ = ast_bool_operation(GT, $1, $3); }
  |
  expr LEQ expr { $$ = ast_bool_operation(LEQ, $1, $3); }
  |
  expr GEQ expr { $$ = ast_bool_operation(GEQ, $1, $3); }
  ;
%%

void yyerror(const char* err) {
  printf("Line %d: %s - '%s'\n", yyline, err, yytext  );
}
