%{
#include "parser.tab.h"
float yylval;
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
<<EOF>>                         { return EOF; }

%%

int main(void) {
    int token;
    while ((token = yylex()) != EOF) {
        switch (token) {
            case NUM: printf("NUM(%.10g) ", yylval); break;
            case PLUS: printf("PLUS "); break;
            case MINUS: printf("MINUS "); break;
            case MULT: printf("MULT "); break;
            case DIV: printf("DIV "); break;
            case LPAREN: printf("LPAREN "); break;
            case RPAREN: printf("RPAREN "); break;
            case NEWLINE: printf("\n"); break;
        }
    }
}
