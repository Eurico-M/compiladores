/* --- Definitions --- */

%{
#include "tokens.h"
#include <math.h>
#include <stdio.h>

int yynum;
float yyreal;
%}

%option noyywrap

alpha           [_a-zA-Z]
digit           [0-9]

/* --- Rules --- */
%%

[ \t\n\r]+                      /* skip whitespace */
\{                              { return LBRACE; }
\}                              { return RBRACE; }
\;                              { return SEMICOLON; }
\(                              { return LPAREN; }
\)                              { return RPAREN; }
\,                              { return COMMA; }
while                           { return WHILE; }
for                             { return FOR; }
int                             { return INT; }
float                           { return FLOAT; }
if                              { printf("oupa\n"); return IF; }
{alpha}({alpha}|{digit})*       { return ID; }
{digit}+                        { yynum = atoi(yytext); return NUM; }
{digit}+"."{digit}+             { yyreal = atof(yytext); return REAL; }
<<EOF>>                         { return EOF; /* end of input */ }

%%
/* --- User Code --- */
int main() {
    yylex();
    return 0;
}
