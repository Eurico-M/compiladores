%{
#include <stdlib.h>
#include "parser.h"

int yyline = 1;
%}

%option noyywrap

%%

[ \t\r]+  { } /* skip whitespace */
#.*\n     { yyline++; }
\n        { yyline++; }
\-\-.*$   { } /* line comment */

":="      { return TOKEN_ASSIGN; }
"+"       { return TOKEN_PLUS; }
"-"       { return TOKEN_MINUS; }
"*"       { return TOKEN_MULT; }
"/"       { return TOKEN_DIV; }
"%"       { return TOKEN_MOD; }
"("       { return TOKEN_LPAREN; }
")"       { return TOKEN_RPAREN; }

"="       { return TOKEN_EQUAL; }
"/="      { return TOKEN_DIFF; }
"<"       { return TOKEN_LESS; }
">"       { return TOKEN_GREATER; }
"<="      { return TOKEN_LESS_EQUAL; }
">="      { return TOKEN_GREATER_EQUAL; }
"and"     { return TOKEN_AND; }
"or"      { return TOKEN_OR; }
"xor"     { return TOKEN_XOR; }
"not"     { return TOKEN_NOT; }

"False"   { return TOKEN_FALSE; }
"True"    { return TOKEN_TRUE; }

";"       { return TOKEN_SEMI; }
":"       { return TOKEN_COLON; }
"."       { return TOKEN_DOT; }
if        { return TOKEN_IF; }
then      { return TOKEN_THEN; }
else      { return TOKEN_ELSE; }
while     { return TOKEN_WHILE; }
loop      { return TOKEN_LOOP; }
end       { return TOKEN_END; }

with      { return TOKEN_WITH; }
use       { return TOKEN_USE; }
begin     { return TOKEN_BEGIN; }
procedure { return TOKEN_PROC; }
is        { return TOKEN_IS; }

\"(.*)\"  {
    // Remove the surrounding quotes
    yytext[strlen(yytext)-1] = '\0';  // Remove trailing quote
    yylval.string_val = strdup(yytext + 1);  // Skip leading quote
    return TOKEN_STRING;
}

[a-zA-Z][a-zA-Z0-9_]* { yylval.string_val = strdup(yytext); return TOKEN_ID; }

[0-9]+"."[0-9]+ { yylval.float_val = atof(yytext); return TOKEN_FLOAT; }

[0-9]+ { yylval.int_val = atoi(yytext); return TOKEN_INT; }

. { yyerror("unexpected character"); }

%%
