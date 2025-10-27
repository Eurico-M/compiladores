%{
#include "parser.tab.h"
%}

%option noyywrap

alpha                           [a-zA-Z]
digit                           [0-9]

%%

[ \t]+                                                      /* skip whitespace */
\n                                                          { return NEWLINE; }
\-\-.*$                                                     /* line comment */
\:\=                                                        { return ASSIGN; }
\+                                                          { return PLUS; }
\-                                                          { return MINUS; }
\*                                                          { return MULT; }
\/                                                          { return DIV; }
\(                                                          { return LPAREN; }
\)                                                          { return RPAREN; }
\=                                                          { return EQUALS; }
\<                                                          { return LESS; }
\>                                                          { return GREATER; }
\;                                                          { return SEMI; }
\:                                                          { return COLON; }
if                                                          { return IF; }
then                                                        { return THEN; }
else                                                        { return ELSE; }
while                                                       { return WHILE; }
{alpha}[{alpha}{digit}_]*                                   { return ID; }
{digit}+\.{digit}+|{digit}+(\.{digit}+)?[eE][+-]{digit}+    { yylval = atof(yytext); return REAL; }
{digit}+                                                    { yylval = atof(yytext); return INT; }
<<EOF>>                                                     { return EOF; }

%%
