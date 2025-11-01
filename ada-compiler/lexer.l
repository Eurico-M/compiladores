%{
#include <stdlib.h>
#include "parser.h"

int yyline = 1;
%}

%option noyywrap

alpha                           [a-zA-Z]
digit                           [0-9]

%%

[ \t\n\r]+                                                  /* skip whitespace */
#.*\n                                                       { yyline++; }
\n                                                          { yyline++; }
\-\-.*$                                                     /* line comment */

":="                                                        { return ASSIGN; }
"+"                                                         { return PLUS; }
"-"                                                         { return MINUS; }
"*"                                                         { return MULT; }
"/"                                                         { return DIV; }
"%"                                                         { return MOD; }
"("                                                         { return LPAREN; }
")"                                                         { return RPAREN; }

"="                                                         { return EQUAL; }
"!="                                                        { return DIFF; }
"<"                                                         { return LESS; }
">"                                                         { return GREATER; }
"<="                                                        { return LESS_EQUAL; }
">="                                                        { return GREATER_EQUAL; }

";"                                                         { return SEMI; }
":"                                                         { return COLON; }
if                                                          { return IF; }
then                                                        { return THEN; }
else                                                        { return ELSE; }
while                                                       { return WHILE; }
loop                                                        { return LOOP; }
end                                                         { return END; }

True                                                        { yylval.bool_val = 1; return BOOL; }
False                                                       { yylval.bool_val = 0; return BOOL; }
{alpha}[{alpha}{digit}_]*                                   { yylval.string_val = strdup(yytext); return ID; }
{digit}+\.{digit}+|{digit}+(\.{digit}+)?[eE][+-]{digit}+    { yylval.float_val = atof(yytext); return FLOAT; }
{digit}+                                                    { yylval.int_val = atoi(yytext); return INT; }

.                                                           { yyerror("unexpected character"); }

%%
