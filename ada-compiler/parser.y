%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include "ast.h"

  int yylex (void);
  void yyerror (char const *);
%}

// Root-level grammar symbol
%start program;

%union {
    int int_val;
    float float_val;
    char* string_val;
    bool bool_val;
    Stm* stm_val;
    Expr* expr_val;
    ArExpr* arExpr_val;
    BoolExpr* boolExpr_val;
}

%type <int_val> INT
%type <float_val> FLOAT
%type <string_val> ID
%type <bool_val> BOOL
%type <stm_val> stm
%type <expr_val> expr
%type <arExpr_val> arExpr
%type <boolExpr_val> boolExpr


%token ASSIGN
%token SEMI COLON
%token IF THEN ELSE
%token WHILE LOOP

%left PLUS MINUS
%left MULT DIV MOD
%token LPAREN RPAREN
%left EQUAL DIFF LESS GREATER LESS_EQUAL GREATER_EQUAL

%code requires {
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int yyline;
extern char* yytext;
extern FILE* yyin;
extern void yyerror(const char* msg);
}


%%

program:
    stm_list {
        $$ = $1; }
    ;

stm_list:
    stm {
        $$ = $1; }
    |
    stm_list stm {
        $$ = stm_compound($1, $2); }
    ;

stm:
    ID ASSIGN expr SEMI {
        $$ = stm_assign($1, $3); }
    |
    IF expr THEN stm_list ELSE stm_list END IF SEMI {
        $$ = stm_if($2, $4, $6); }
    |
    WHILE expr LOOP stm_list END LOOP SEMI {
        $$ = stm_while($2, $4); }
    ;

expr:
    arExpr {
        $$ = expr_arithmetic($1); }
    |
    boolExpr {
        $$ = expr_boolean($1); }
    |
    ID LPAREN expr RPAREN {
        $$ = expr_function($1, $3); }
    |
    ID {
        $$ = expr_variable($1); }
    ;

arExpr:
    ID {
        $$ = ar_expr_identifier($1); }
    |
    INT {
        $$ = ar_expr_integer($1); }
    |
    FLOAT {
        $$ = ar_expr_float($1); }
    |
    arExpr PLUS arExpr {
        $$ = ar_expr_operation(PLUS, $1, $3); }
    |
    arExpr MINUS arExpr {
        $$ = ar_expr_operation(MINUS, $1, $3); }
    |
    arExpr TIMES arExpr {
        $$ = ar_expr_operation(TIMES, $1, $3); }
    |
    arExpr DIV arExpr {
        $$ = ar_expr_operation(DIV, $1, $3); }
    |
    arExpr MOD arExpr {
        $$ = ar_expr_operation(MOD, $1, $3); }
    ;

boolExpr:
    ID {
        $$ = bool_expr_identifier($1); }
    |
    BOOL {
        $$ = bool_expr_bool($1); }
    |
    arExpr EQUAL arExpr {
        $$ = bool_expr_operation(EQUAL, $1, $3); }
    |
    arExpr DIFF arExpr {
        $$ = bool_expr_operation(DIFF, $1, $3); }
    |
    arExpr LESS arExpr {
        $$ = bool_expr_operation(LESS, $1, $3); }
    |
    arExpr GREATER arExpr {
        $$ = bool_expr_operation(GREATER, $1, $3); }
    |
    arExpr LESS_EQUAL arExpr {
        $$ = bool_expr_operation(LESS_EQUAL, $1, $3); }
    |
    arExpr GREATER_EQUAL arExpr {
        $$ = bool_expr_operation(GREATER_EQUAL, $1, $3); }
    ;



%%

void yyerror(const char* err) {
   printf("Line %d: %s - '%s'\n", yyline, err, yytext);
}
