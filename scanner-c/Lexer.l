/* --- Definitions --- */

%{
#include "tokens.h"
%}

%option noyywrap

alpha [_a-zA-Z]
digit [0-9]

%%
/* --- Rules --- */

[ \t\n\r]+                                  /* skip whitespace */
\{                                          { return LBRACE; }
\}                                          { return RBRACE; }
\;                                          { return SEMICOLON; }
\(                                          { return LPAREN; }
\)                                          { return RPAREN; }
\,                                          { return COMMA; }
if                                          { return IF; }
while                                       { return WHILE; }
for                                         { return FOR; }
int                                         { return INT; }
float                                       { return FLOAT; }
{alpha}({alpha}|{digit})*                   { return ID; }
{digit}+                                    { yynum = atoi(yytext); return NUM; }
{digit}+"."{digit}+                         { yyreal = atof(yytext); return REAL; }
<<EOF>>                                     { return EOF; /* end of input */ }

%%
/* --- User Code --- */
