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
%left SQRT EXP LOG
%token LPAREN
%token RPAREN
%token NEWLINE


%%

input:
  %empty
| input line
;

line:
  NEWLINE
| expr NEWLINE              { printf ("\t\t%.10g\n", $1); }
| error NEWLINE             { yyerrok; }
;

expr:
  NUM                            { $$ = $1; }
| expr PLUS expr                 { $$ = $1 + $3; }
| expr MINUS expr                { $$ = $1 - $3; }
| expr MULT expr                 { $$ = $1 * $3; }
| expr DIV expr                  { $$ = $1 / $3; }
| MINUS expr                     { $$ = -$2; }
| LPAREN expr RPAREN             { $$ = $2; }
| SQRT expr                      { $$ = sqrt($2); }
| expr EXP expr                  { $$ = pow($1, $3); }
| LOG expr                       { $$ = log($2) / log(2); }
;


%%

void yyerror(char const *msg) {
   printf("parse error: %s\n", msg);
}
