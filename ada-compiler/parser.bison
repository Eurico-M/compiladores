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
    Dclr* dclr_val;
    Pckg* pckg_val;
}

%type <int_val> TOKEN_INT
%type <float_val> TOKEN_FLOAT
%type <string_val> TOKEN_ID TOKEN_STRING
%type <bool_val> TOKEN_BOOL

%type <stm_val> program
%type <stm_val> stm stm_list
%type <expr_val> expr
%type <arExpr_val> arExpr
%type <boolExpr_val> boolExpr
%type <dclr_val> dclr dclr_list
%type <pckg_val> pckg pckg_list


%token TOKEN_INT TOKEN_FLOAT TOKEN_BOOL
%token TOKEN_ID TOKEN_STRING
%token TOKEN_PLUS TOKEN_MINUS TOKEN_MULT TOKEN_DIV TOKEN_MOD
%token TOKEN_EQUAL TOKEN_DIFF TOKEN_LESS TOKEN_GREATER TOKEN_LESS_EQUAL TOKEN_GREATER_EQUAL TOKEN_AND TOKEN_OR TOKEN_XOR TOKEN_NOT

%token TOKEN_EOF
%token TOKEN_ASSIGN
%token TOKEN_SEMI TOKEN_COLON TOKEN_DOT
%token TOKEN_IF TOKEN_THEN TOKEN_ELSE
%token TOKEN_WHILE TOKEN_LOOP
%token TOKEN_WITH TOKEN_USE
%token TOKEN_PROC TOKEN_IS TOKEN_BEGIN TOKEN_END

%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULT TOKEN_DIV TOKEN_MOD
%token TOKEN_LPAREN TOKEN_RPAREN
%left TOKEN_OR TOKEN_XOR
%left TOKEN_AND
%nonassoc TOKEN_EQUAL TOKEN_DIFF TOKEN_LESS TOKEN_GREATER TOKEN_LESS_EQUAL TOKEN_GREATER_EQUAL
%right TOKEN_NOT


%code requires {
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int yyline;
extern char* yytext;
extern FILE* yyin;
extern void yyerror(const char* msg);
extern Stm* program;
}


%%


program:
    stm_list {
        program = $$ = $1; }
    ;


stm_list:
    stm {
        $$ = $1; }
    |
    stm_list stm {
        $$ = stm_compound($1, $2); }
    ;


stm:
    TOKEN_ID TOKEN_ASSIGN expr TOKEN_SEMI {
        $$ = stm_assign($1, $3); }
    |
    TOKEN_IF expr TOKEN_THEN stm_list TOKEN_END TOKEN_IF TOKEN_SEMI {
        $$ = stm_if_then($2, $4); }
    |
    TOKEN_IF expr TOKEN_THEN stm_list TOKEN_ELSE stm_list TOKEN_END TOKEN_IF TOKEN_SEMI {
        $$ = stm_if_then_else($2, $4, $6); }
    |
    TOKEN_WHILE expr TOKEN_LOOP stm_list TOKEN_END TOKEN_LOOP TOKEN_SEMI {
        $$ = stm_while($2, $4); }
    |
    TOKEN_WITH pckg_list TOKEN_SEMI {
        $$ = stm_with($2); }
    |
    TOKEN_USE pckg_list TOKEN_SEMI {
        $$ = stm_use($2); }
    |
    TOKEN_PROC TOKEN_ID TOKEN_IS dclr_list TOKEN_BEGIN stm_list TOKEN_END TOKEN_ID TOKEN_SEMI {
        $$ = stm_procedure($2, $4, $6); }
    |
    TOKEN_ID TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_SEMI {
        $$ = stm_function($1, $3); }
    ;


dclr_list:
    %empty {}
    |
    dclr {
        $$ = $1; }
    |
    dclr_list dclr {
        $$ = dclr_compound($1, $2); }


dclr:
    TOKEN_ID TOKEN_COLON TOKEN_ID TOKEN_SEMI {
        $$ = dclr_simple($1, $3); }
    |
    TOKEN_ID TOKEN_COLON TOKEN_ID TOKEN_ASSIGN expr TOKEN_SEMI {
        $$ = dclr_assignment($1, $3, $5); }
    ;

expr:
    arExpr {
        $$ = expr_arithmetic($1); }
    |
    boolExpr {
        $$ = expr_boolean($1); }
    |
    TOKEN_STRING {
        $$ = expr_string($1); }
    ;


arExpr:
    TOKEN_ID {
        $$ = ar_expr_identifier($1); }
    |
    TOKEN_INT {
        $$ = ar_expr_integer($1); }
    |
    TOKEN_FLOAT {
        $$ = ar_expr_float($1); }
    |
    TOKEN_BOOL {
        $$ = ar_expr_boolean($1); }
    |
    TOKEN_LPAREN arExpr TOKEN_RPAREN {
        $$ = ar_expr_delimited($2); }
    |
    arExpr TOKEN_PLUS arExpr {
        $$ = ar_expr_operation(PLUS, $1, $3); }
    |
    arExpr TOKEN_MINUS arExpr {
        $$ = ar_expr_operation(MINUS, $1, $3); }
    |
    arExpr TOKEN_MULT arExpr {
        $$ = ar_expr_operation(TIMES, $1, $3); }
    |
    arExpr TOKEN_DIV arExpr {
        $$ = ar_expr_operation(DIV, $1, $3); }
    |
    arExpr TOKEN_MOD arExpr {
        $$ = ar_expr_operation(MOD, $1, $3); }
    ;


boolExpr:
    TOKEN_LPAREN boolExpr TOKEN_RPAREN {
        $$ = bool_expr_delimited($2); }
    |
    arExpr TOKEN_EQUAL arExpr {
        $$ = bool_expr_operation(EQUAL, $1, $3); }
    |
    arExpr TOKEN_DIFF arExpr {
        $$ = bool_expr_operation(DIFF, $1, $3); }
    |
    arExpr TOKEN_LESS arExpr {
        $$ = bool_expr_operation(LESS, $1, $3); }
    |
    arExpr TOKEN_GREATER arExpr {
        $$ = bool_expr_operation(GREATER, $1, $3); }
    |
    arExpr TOKEN_LESS_EQUAL arExpr {
        $$ = bool_expr_operation(LESS_EQUAL, $1, $3); }
    |
    arExpr TOKEN_GREATER_EQUAL arExpr {
        $$ = bool_expr_operation(GREATER_EQUAL, $1, $3); }
    |
    boolExpr TOKEN_AND boolExpr {
        $$ = bool_expr_operation2(AND, $1, $3); }
    |
    boolExpr TOKEN_OR boolExpr {
        $$ = bool_expr_operation2(OR, $1, $3); }
    |
    boolExpr TOKEN_XOR boolExpr {
        $$ = bool_expr_operation2(XOR, $1, $3); }
    |
    TOKEN_NOT boolExpr {
        $$ = bool_expr_operation2(NOT, NULL, $2); }
    ;


pckg_list:
    pckg {
        $$ = $1; }
    |
    pckg_list TOKEN_DOT pckg {
        $$ = pckg_compound($1, $3); }
    ;


pckg:
    TOKEN_ID {
        $$ = pckg_simple($1); }
    ;

%%

void yyerror(const char* err) {
   printf("Line %d: %s - '%s'\n", yyline, err, yytext);
}
