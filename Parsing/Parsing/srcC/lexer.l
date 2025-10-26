%{
#include "parser.tab.h"
%}
%option noyywrap

%%

[ \t]+
\n                              { return NEWLINE; }
[0-9]+"."[0-9]+|[0-9]+          { yylval = atof(yytext); return NUM; }
\+                              { return PLUS; }
\-                              { return MINUS; }
\*                              { return MULT; }
\/                              { return DIV; }
\(                              { return LPAREN; }
\)                              { return RPAREN; }
sqrt                            { return SQRT; }
\^                              { return EXP; }
log                             { return LOG; }
quit                            { return EOF; }
<<EOF>>                         { return EOF; }

%%
