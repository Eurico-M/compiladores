%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  int yylex (void);
  void yyerror (char const *);
%}

%define api.value.type {float}
%token NUM
%left PLUS MINUS
%left MULT DIV
%token LPAREN
%token RPAREN


%%

input:
  %empty
| input line
;

line:
  '\n'
| exp '\n'            { printf ("\t%.10g\n", $1); }
;

exp:
  term                { $$ = $1; }
| exp PLUS term       { $$ = $1 + $3; }
| exp MINUS term      { $$ = $1 - $3; }
| exp MULT term       { $$ = $1 * $3; }
| exp DIV term        { $$ = $1 / $3; }
;

term:
  NUM                 { $$ = $1; }
| LPAREN exp RPAREN   { $$ = $2; }
;

%%

void yyerror(char const *msg) {
   printf("parse error: %s\n", msg);
   exit(-1);
}
