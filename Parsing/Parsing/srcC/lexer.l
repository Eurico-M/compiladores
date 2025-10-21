%{
#include "parser.tab.h"
%}
%option noyywrap

%%

[ \t\n\r]+
[0-9]+"."[0-9]+|[0-9]+          { yylval = atof(yytext); printf("NUM = %f\n", yylval); return NUM; }
\+                              { printf("PLUS\n"); return PLUS; }
\-                              { printf("MINUS\n"); return MINUS; }
\*                              { printf("MULT\n"); return MULT; }
\/                              { printf("DIV\n"); return DIV; }
\(                              { printf("LPAREN\n"); return LPAREN; }
\)                              { printf("RPAREN\n"); return RPAREN; }
<<EOF>>                         { return T_EOF; }

%%
