
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
    else if (arExpr->tag == OP) {
        printf("(");
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
            default: yyerror("unkown arithmetic operator");
        }
        printArExpr(arExpr->attr.ar_op.right);
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
    // else if (expr->kind == EXPR_BOOLEAN) {
    //     printf("BOOLEAN_EXPRESSION(");
    //     printBoolExpr(expr->attr.bool_expr);
    //     printf(")");
    // }
}


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
    else if (stm->kind == STM_WITH) {
        printf("WITH(%s)", stm->attr.with_id);
    }
    else if (stm->kind == STM_USE) {
        printf("USE(%s)", stm->attr.use_id);
    }
    else if (stm->kind == STM_PROCEDURE) {
        printf("PROCEDURE(%s, ", stm->attr.stm_proc.proc_id);
        printStm(stm->attr.stm_proc.body);
        printf(")");
    }
    else if (stm->kind == STM_FUNCTION) {
        printf("FUNCTION(%s(", stm->attr.stm_func.func_id);
        printExpr(stm->attr.stm_func.arg);
        printf(")");
    }
}

// void printExpr(Expr* expr) {
//     if (expr == 0) {
//         yyerror("Null expression");
//     }
//     else if (expr->kind == E_INTEGER) {
//         printf("%d", expr->attr.value);
//     }
//     else if (expr->kind == E_OPERATION) {
//         switch (expr->attr.op.bin_operator) {
//             case PLUS:
//                 printf("+");
//                 break;
//             case MINUS:
//                 printf("-");
//                 break;
//             case TIMES:
//                 printf("*");
//                 break;
//             case DIV:
//                 printf("/");
//                 break;
//             case MOD:
//                 printf("%%");
//                 break;
//             default: yyerror("Unknown operator");
//         }
//         printf("\n");
//         printExpr(expr->attr.op.left);
//         printExpr(expr->attr.op.right);
//     }
// }

// void printBool(BoolExpr* b, int depth) {
//     for (int i = 0; i < depth; i++) {
//         printf("  ");
//     }

//     if (b == 0) {
//         yyerror("Null expression");
//     }
//     else if (b->kind == E_BOOL_INTEGER) {
//         printf("%d\n", b->attr.bool_value);
//     }
//     else if (b->kind == E_BOOL_OPERATION) {
//         switch (b->attr.relop.rel_operator) {
//             case EQUAL:
//                 printf("==");
//                 break;
//             case DIFF:
//                 printf("!=");
//                 break;
//             case LT:
//                 printf("<");
//                 break;
//             case GT:
//                 printf(">");
//                 break;
//             case LEQ:
//                 printf("<=");
//                 break;
//             case GEQ:
//                 printf(">=");
//                 break;
//             default: yyerror("Unkown boolean operator");
//         }
//     }
// }
