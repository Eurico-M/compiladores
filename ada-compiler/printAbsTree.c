
#include <stdio.h>
#include "ast.h"
#include "parser.h"


void printStm(Stm* stm) {
    if (stm == 0) {
        yyerror("Null statement");
    }
    else if (stm->kind == STM_COMPOUND) {
        printf("COMPOUND(");
        printStm(stm->attr.compound.first);
        printf(", ");
        printStm(stm->attr.compound.second);
        printf(")");
    }
    else if (stm->kind == STM_ASSIGNMENT) {
        printf("ASSIGN(%s", stm->attr.assign.ident);
        printf(", ");
        printExpr(stm->attr.assign.expr);
        printf(")");
    }
    else if (stm->kind == STM_IF) {
        printf("IF(");
        printExpr(stm->attr.if_stm.condition);
        printf(" THEN ");
        printStm(stm->attr.if_stm.then_branch);
        printf(" ELSE ");
        printStm(stm->attr.if_stm.else_branch);
        printf(")");

    }
}

void printExpr(Expr* expr, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    if (expr == 0) {
        yyerror("Null expression");
    }
    else if (expr->kind == E_INTEGER) {
        printf("%d\n", expr->attr.value);
    }
    else if (expr->kind == E_OPERATION) {
        switch (expr->attr.op.bin_operator) {
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
        printf("\n");
        printExpr(expr->attr.op.left, depth+1);
        printExpr(expr->attr.op.right, depth+1);
    }
}

void printBool(BoolExpr* b, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    if (b == 0) {
        yyerror("Null expression");
    }
    else if (b->kind == E_BOOL_INTEGER) {
        printf("%d\n", b->attr.bool_value);
    }
    else if (b->kind == E_BOOL_OPERATION) {
        switch (b->attr.relop.rel_operator) {
            case EQUAL:
                printf("==");
                break;
            case DIFF:
                printf("!=");
                break;
            case LT:
                printf("<");
                break;
            case GT:
                printf(">");
                break;
            case LEQ:
                printf("<=");
                break;
            case GEQ:
                printf(">=");
                break;
            default: yyerror("Unkown boolean operator");
        }
    }
}
