#include <stdio.h>
#include "ast.h"
#include "parser.h"

void printArExpr(ArExpr* arExpr) {
    if (arExpr == 0) {
        yyerror("Null arithmetic expression");
    }
    else if (arExpr->tag == ID) {
        printf("ID(%s)", arExpr->attr.id);
    }
    else if (arExpr->tag == INT) {
        printf("INT(%d)", arExpr->attr.int_val);
    }
    else if (arExpr->tag == FLOAT) {
        printf("FLOAT(%f)", arExpr->attr.float_val);
    }
    else if (arExpr->tag == AR_OP) {
        // printf("(");
        printArExpr(arExpr->attr.ar_op.left);

        switch (arExpr->attr.ar_op.op) {
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
            default: yyerror("Unkown arithmetic operator");
        }

        printArExpr(arExpr->attr.ar_op.right);
        // printf(")");
    }
}

void printBoolExpr(BoolExpr* boolExpr) {
    if (boolExpr == 0) {
        yyerror("Null boolean expression");
    }
    else if (boolExpr->tag == BOOL_OP) {
        printf("(");
        printArExpr(boolExpr->attr.bool_op.left);

        switch (boolExpr->attr.bool_op.op) {
            case EQUAL:
                printf(" == ");
                break;
            case DIFF:
                printf(" != ");
                break;
            case LESS:
                printf(" < ");
                break;
            case GREATER:
                printf(" > ");
                break;
            case LESS_EQUAL:
                printf(" <= ");
                break;
            case GREATER_EQUAL:
                printf(" >= ");
                break;
            default: yyerror("Unkown boolean operator");
        }

        printArExpr(boolExpr->attr.bool_op.right);
        printf(")");
    }
}


void printExpr(Expr* expr) {
    if (expr == 0) {
        yyerror("Null expression");
    }
    else if (expr->kind == EXPR_ARITHMETIC) {
        printf("ARITHMETIC_EXPRESSION(");
        printArExpr(expr->attr.ar_expr);
        printf(")");
    }
    else if (expr->kind == EXPR_BOOLEAN) {
        printf("BOOLEAN_EXPRESSION(");
        printBoolExpr(expr->attr.bool_expr);
        printf(")");
    }
}

void printDclr(Dclr* dclr) {
    if (dclr == 0) {}
    else if (dclr->kind == DCLR_COMPOUND) {
        printf("DCLR_COMPOUND(");
        printDclr(dclr->attr.dclr_compound.first);
        printf(" , ");
        printDclr(dclr->attr.dclr_compound.second);
        printf(")");
    }
    else if (dclr->kind == DCLR_SIMPLE) {
        printf("%s (%s)", dclr->attr.dclr_simple.id, dclr->attr.dclr_simple.type);
    }
    else if (dclr->kind == DCLR_ASSIGNMENT) {
        printf("%s (%s) = ", dclr->attr.dclr_assignment.id, dclr->attr.dclr_assignment.type);
        printExpr(dclr->attr.dclr_assignment.expr);
    }
}


void printStm(Stm* stm) {
    if (stm == 0) {
        yyerror("Null statement");
    }
    else if (stm->kind == STM_COMPOUND) {
        printf("COMPOUND_STM(");
        printStm(stm->attr.compound.first);
        printf(", ");
        printStm(stm->attr.compound.second);
        printf(")");
    }
    else if (stm->kind == STM_ASSIGNMENT) {
        printf("ASSIGN_STM(%s", stm->attr.assign.ident);
        printf(", ");
        printExpr(stm->attr.assign.expr);
        printf(")");
    }
    else if (stm->kind == STM_IF_THEN) {
        printf("IF_THEN(");
        printExpr(stm->attr.if_then.condition);
        printf(" , ");
        printStm(stm->attr.if_then.then_branch);
        printf(")");
    }
    else if (stm->kind == STM_IF_THEN_ELSE) {
        printf("IF_THEN_ELSE(");
        printExpr(stm->attr.if_then_else.condition);
        printf(" , ");
        printStm(stm->attr.if_then_else.then_branch);
        printf(" , ");
        printStm(stm->attr.if_then_else.else_branch);
        printf(")");
    }
    else if (stm->kind == STM_WITH) {
        printf("WITH(%s)", stm->attr.with_id);
    }
    else if (stm->kind == STM_USE) {
        printf("USE(%s)", stm->attr.use_id);
    }
    else if (stm->kind == STM_PROCEDURE) {
        printf("PROCEDURE(%s", stm->attr.stm_proc.proc_id);
        if (stm->attr.stm_proc.dclr != 0) {
            printf(", ");
            printDclr(stm->attr.stm_proc.dclr);
        }
        printf(" BEGIN ");
        printStm(stm->attr.stm_proc.body);
        printf(")");
    }
    else if (stm->kind == STM_FUNCTION) {
        printf("FUNCTION_STM(%s(", stm->attr.stm_func.func_id);
        printExpr(stm->attr.stm_func.arg);
        printf(")");
    }
}
