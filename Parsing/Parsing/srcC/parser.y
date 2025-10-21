%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int yylex (void);
void yyerror (char const *);
%}
%define api.value.type {float}
%token NUM
%left PLUS
%left MINUS
%left MULT
%left DIV
%token LPAREN
%token RPAREN
%token T_EOF

%%

top : expr                  { printf("%f\n", $1); }
    ;

expr : term                 { $$ = $1; }
     | expr '+' term        { $$ = $1 + $3; }
     | expr '-' term        { $$ = $1 - $3; }
     | expr '*' term        { $$ = $1 * $3; }
     | expr '/' term        { $$ = $1 / $3; }

term : NUM                  { $$ = $1; }
     | LPAREN expr RPAREN   { $$ = $2; }

%%

void yyerror(char const *msg) {
   printf("parse error: %s\n", msg);
   exit(-1);
}

int main(void) {
    yyparse();
}
