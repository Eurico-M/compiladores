
#include <stdio.h>
#include "ast.h"
#include "parser.h"


void printExpr(Expr* expr) {
    if (expr == 0) {
        yyerror("Null expression");
    }
    else if (expr->kind == E_INTEGER) {
        printf("%d", expr->attr.value);
    }
    else if (expr->kind == E_OPERATION) {
        printf("(");
        printExpr(expr->attr.op.left);
        switch (expr->attr.op.operator) {
            case PLUS:
                printf("+");
                break;
            case MINUS:
                printf("-");
                break;
            case TIMES:
                printf("*");
                break;
            case DIV:
                printf("/");
                break;
            case MOD:
                printf("%%");
                break;
            default: yyerror("Unknown operator");
        }
        printExpr(expr->attr.op.right);
        printf(")");
    }
}
