%{
#include "parser.tab.h"
float yylval;
%}
%option noyywrap

%%

[ \t\n\r]+
[0-9]+"."[0-9]+|[0-9]+          { yylval = atof(yytext); return NUM; }
\+                              { return PLUS; }
\-                              { return MINUS; }
\*                              { return MULT; }
\/                              { return DIV; }
\(                              { return LPAREN; }
\)                              { return RPAREN; }
<<EOF>>                         { return T_EOF; }

%%

int main(void) {
    int token;
    while ((token = yylex()) != T_EOF) {
        switch (token) {
            case PLUS: printf("PLUS "); break;
            case NUM: printf("NUM(%f) ", yylval); break;
            case MINUS: printf("MINUS "); break;
        }
    }
}
