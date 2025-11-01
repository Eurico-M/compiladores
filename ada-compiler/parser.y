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
}

%token <int_val> INT
%token <float_val> FLOAT
%token <string_val> ID
%token <bool_val> BOOL

%token ASSIGN
%token SEMI COLON
%token IF THEN ELSE
%token WHILE LOOP

%left PLUS MINUS
%left MULT DIV MOD
%token LPAREN RPAREN
%left EQUAL DIFF LESS GREATER LESS_EQUAL GREATER_EQUAL


%%

program:
    stm_list {
        $$ = $1; }
    ;

stm_list:
    stm {
        $$ = $1; }
    |
    stm_list SEMI stm {
        $$ = stm_compound($1, $3); }
    ;

stm:
    ID ASSIGN expr {
        $$ = stm_assign($1, $3); }
    |
    IF expr THEN stm_list ELSE stm_list END IF {
        $$ = stm_if($2, $4, $6); }
    |
    WHILE expr LOOP stm_list END LOOP {
        $$ = stm_while($2, $4); }
    ;


%%

void yyerror(const char* err) {
   printf("Line %d: %s - '%s'\n", yyline, err, yytext);
}
