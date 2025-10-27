%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  int yylex (void);
  void yyerror (char const *);
%}

%define api.value.type {float}

%token NEWLINE
%token ASSIGN
%token ID REAL INT
%token SEMI COLON
%token IF THEN ELSE
%token WHILE

%left PLUS MINUS
%left MULT DIV
%token LPAREN RPAREN
%token EQUALS LESS GREATER


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
  INT                            { $$ = $1; }
| expr PLUS expr                 { $$ = $1 + $3; }
| expr MINUS expr                { $$ = $1 - $3; }
| expr MULT expr                 { $$ = $1 * $3; }
| expr DIV expr                  { $$ = $1 / $3; }
| MINUS expr                     { $$ = -$2; }
;


%%

void yyerror(char const *msg) {
   printf("parse error: %s\n", msg);
}
