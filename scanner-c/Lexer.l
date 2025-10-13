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

\/\*([^\*\/])*\*\/                                                      { printf("comentário multi-linha\n"); }
\/\/.*$                                                                 /* { printf("comentário\n"); } */
[ \t\n\r]+                                                              /* skip whitespace */
\{                                                                      { return LBRACE; }
\}                                                                      { return RBRACE; }
\;                                                                      { return SEMICOLON; }
\(                                                                      { return LPAREN; }
\)                                                                      { return RPAREN; }
\,                                                                      { return COMMA; }
while                                                                   { return WHILE; }
for                                                                     { return FOR; }
int                                                                     { return INT; }
float                                                                   { return FLOAT; }
if                                                                      { printf("oupa\n"); return IF; }
{alpha}({alpha}|{digit})*                                               { printf("ID\n"); return ID; }
{digit}+\.{digit}+|{digit}+(\.{digit}+)?[eE][+-]{digit}+                { yyreal = atof(yytext); printf("REAL = %f\n", yyreal); return REAL; }
{digit}+                                                                { yynum = atoi(yytext); printf("inteiro\n"); return NUM; }
<<EOF>>                                                                 { return EOF; /* end of input */ }

%%
/* --- User Code --- */
int main() {
    yylex();
    return 0;
}
