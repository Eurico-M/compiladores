#include <stdio.h>
#include "ast.h"
#include "parser.h"
#include "st.h"

void printArExpr(ArExpr* arExpr) {
    if (arExpr == 0) {
        yyerror("Null arithmetic expression");
    }
    else if (arExpr->kind == ID) {
        printf("ID(%s)", arExpr->attr.id);
    }
    else if (arExpr->kind == INT) {
        printf("INT(%d)", arExpr->attr.int_val);
    }
    else if (arExpr->kind == FLOAT) {
        printf("FLOAT(%f)", arExpr->attr.float_val);
    }
    else if (arExpr->kind == BOOLEAN) {
        if (arExpr->attr.boolean_ent) {
            printf("TRUE");
        }
        else {
            printf("FALSE");
        }
    }
    else if(arExpr->kind == DELIMITED_AR_EXPR) {
        printArExpr(arExpr->attr.delimited_ar_expr);
    }
    else if (arExpr->kind == AR_OP) {

        switch (arExpr->attr.ar_op.op) {
            case PLUS:
                printf("PLUS(");
                break;
            case MINUS:
                printf("MINUS(");
                break;
            case TIMES:
                printf("TIMES(");
                break;
            case DIV:
                printf("DIV(");
                break;
            case MOD:
                printf("MOD(");
                break;
            default: yyerror("Unkown arithmetic operator(");
        }
        printArExpr(arExpr->attr.ar_op.left);
        printf(" ");
        printArExpr(arExpr->attr.ar_op.right);
        printf(")");
    }
}

void printBoolExpr(BoolExpr* boolExpr) {
    if (boolExpr == 0) {
        yyerror("Null boolean expression");
    }
    else if(boolExpr->kind == DELIMITED_BOOL_EXPR) {
        printBoolExpr(boolExpr->attr.delimited_bool_expr);
    }
    else if (boolExpr->kind == BOOL_OP) {

        switch (boolExpr->attr.bool_op.op) {
            case EQUAL:
                printf("EQUAL(");
                break;
            case DIFF:
                printf("DIFF(");
                break;
            case LESS:
                printf("LESS(");
                break;
            case GREATER:
                printf("GREATER(");
                break;
            case LESS_EQUAL:
                printf("LESS_EQUAL(");
                break;
            case GREATER_EQUAL:
                printf("GREATER_EQUAL(");
                break;
            default: yyerror("Unkown boolean operator(");
        }
            printArExpr(boolExpr->attr.bool_op.left);
            printf(" ");
            printArExpr(boolExpr->attr.bool_op.right);
            printf(")");
    }
    else if (boolExpr->kind == BOOL_OP2) {
        switch (boolExpr->attr.bool_op2.op){
            case AND:
                printf("AND(");
                break;
            case OR:
                printf("OR(");
                break;
            case XOR:
                printf("XOR(");
                break;
            case NOT:
                printf("NOT(");
                break;
            default: yyerror("Unkown boolean operator(");
        }

        if (boolExpr->attr.bool_op2.op != NOT) {
            printBoolExpr(boolExpr->attr.bool_op2.left);
        }
        printBoolExpr(boolExpr->attr.bool_op2.right);
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
    else if (expr->kind == EXPR_STRING) {
        printf("STRING(\"%s\")", expr->attr.string_expr);
    }
}

void printDclr(Dclr* dclr) {
    if (dclr == 0) {}
    else if (dclr->kind == DCLR_COMPOUND) {
        // printf("DCLR_COMPOUND(");
        printDclr(dclr->attr.dclr_compound.first);
        printf(" ");
        printDclr(dclr->attr.dclr_compound.second);
        // printf(")");
    }
    else if (dclr->kind == DCLR_SIMPLE) {
        printf("DCLR_SIMPLE(%s(%s)", st_type_to_string(dclr->attr.dclr_simple.type), dclr->attr.dclr_simple.id);
        printf(")");
    }
    else if (dclr->kind == DCLR_ASSIGNMENT) {
        printf("DCLR_ASSIGN(%s(%s) = ", st_type_to_string(dclr->attr.dclr_assignment.type), dclr->attr.dclr_assignment.id);
        printExpr(dclr->attr.dclr_assignment.expr);
        printf(")");
    }
}

void printPckg(Pckg* pckg) {
    if (pckg == 0) {
        yyerror("Null package");
    }
    else if (pckg->kind == PCKG_SIMPLE) {
        printf("%s", pckg->attr.pckg_id);
    }
    else if (pckg->kind == PCKG_COMPOUND) {
        printPckg(pckg->attr.compound.first);
        printf(".");
        printPckg(pckg->attr.compound.second);
    }
}


void printStm(Stm* stm) {
    if (stm == 0) {
        yyerror("Null statement");
    }
    else if (stm->kind == STM_COMPOUND) {
        // printf("COMPOUND_STM(");
        printStm(stm->attr.compound.first);
        printf(" ");
        printStm(stm->attr.compound.second);
        // printf(")");
    }
    else if (stm->kind == STM_ASSIGNMENT) {
        printf("ASSIGN(ID(%s)", stm->attr.assign.ident);
        printf(" ");
        printExpr(stm->attr.assign.expr);
        printf(")");
    }
    else if (stm->kind == STM_IF_THEN) {
        printf("IF(");
        printExpr(stm->attr.if_then.condition);
        printf(") THEN(");
        printStm(stm->attr.if_then.then_branch);
        printf(") END_IF");
    }
    else if (stm->kind == STM_IF_THEN_ELSE) {
        printf("IF(");
        printExpr(stm->attr.if_then_else.condition);
        printf(") THEN(");
        printStm(stm->attr.if_then_else.then_branch);
        printf(") ELSE(");
        printStm(stm->attr.if_then_else.else_branch);
        printf(") END_IF");
    }
    else if (stm->kind == STM_WHILE) {
        printf("WHILE(");
        printExpr(stm->attr.while_stm.condition);
        printf(") LOOP(");
        printStm(stm->attr.while_stm.body);
        printf(") END_LOOP");
    }
    else if (stm->kind == STM_WITH) {
        printf("WITH(");
        printPckg(stm->attr.pckg_with);
        printf(")");
    }
    else if (stm->kind == STM_USE) {
        printf("USE(");
        printPckg(stm->attr.pckg_use);
        printf(")");
    }
    else if (stm->kind == STM_PROCEDURE) {
        printf("PROCEDURE(%s) IS(", stm->attr.stm_proc.proc_id);
        if (stm->attr.stm_proc.dclr != 0) {
            printDclr(stm->attr.stm_proc.dclr);
        }
        printf(" BEGIN(");
        printStm(stm->attr.stm_proc.body);
        printf(")) END_%s", stm->attr.stm_proc.proc_id);
    }
    else if (stm->kind == STM_FUNCTION) {
        printf("FUNCTION(%s(", stm->attr.stm_func.func_id);
        printExpr(stm->attr.stm_func.arg);
        printf("))");
    }
}
