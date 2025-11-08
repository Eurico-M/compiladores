#include <stdio.h>
#include "ast.h"
#include "parser.h"

void printArExpr_v2(ArExpr* arExpr, long tabs) {
    
    char tabString[4 * tabs + 1]; 

    for (int i = 0; i < 4 * tabs; i++) {
        tabString[i] = ' ';
    }

    tabString[4 * tabs] = '\0';

    if (arExpr == 0) {
        yyerror("Null arithmetic expression");
    }
    else if (arExpr->tag == ID) {
        printf("%sID(%s)\n", tabString, arExpr->attr.id);
    }
    else if (arExpr->tag == INT) {
        printf("%sINT(%d)\n", tabString, arExpr->attr.int_val);
    }
    else if (arExpr->tag == FLOAT) {
        printf("%sFLOAT(%.3f)\n", tabString, arExpr->attr.float_val);
    }
    else if (arExpr->tag == AR_OP) {     
        switch (arExpr->attr.ar_op.op) {
            case PLUS:
                printf("%sPLUS(\n", tabString);
                printArExpr_v2(arExpr->attr.ar_op.left, tabs + 1);
                printArExpr_v2(arExpr->attr.ar_op.right, tabs + 1);
                printf("%s)\n", tabString);
                break;
            case MINUS:
                printf("%sMINUS(\n", tabString);
                printArExpr_v2(arExpr->attr.ar_op.left, tabs + 1);
                printArExpr_v2(arExpr->attr.ar_op.right, tabs + 1);
                printf("%s)\n", tabString);
                break;
            case TIMES:
                printf("%sTIMES(\n", tabString);
                printArExpr_v2(arExpr->attr.ar_op.left, tabs + 1);
                printArExpr_v2(arExpr->attr.ar_op.right, tabs + 1);
                printf("%s)\n", tabString);
                break;
            case DIV:
                printf("%sDIV(\n", tabString);
                printArExpr_v2(arExpr->attr.ar_op.left, tabs + 1);
                printArExpr_v2(arExpr->attr.ar_op.right, tabs + 1);
                printf("%s)\n", tabString);
                break;
            case MOD:
                printf("%sMOD(\n", tabString);
                printArExpr_v2(arExpr->attr.ar_op.left, tabs + 1);
                printArExpr_v2(arExpr->attr.ar_op.right, tabs + 1);
                printf("%s)\n", tabString);
                break;
            default: yyerror("Unkown arithmetic operator");
        }
    }
}

void printBoolExpr_v2(BoolExpr* boolExpr, long tabs) {

    char tabString[4 * tabs + 1]; 

    for (int i = 0; i < 4 * tabs; i++) {
        tabString[i] = ' ';
    }

    tabString[4 * tabs] = '\0';

    if (boolExpr == 0) {
        yyerror("Null boolean expression");
    }
    else if (boolExpr->tag == BOOL_OP) {   
        switch (boolExpr->attr.bool_op.op) {
            case EQUAL:
                printf("%sEQUALS(\n", tabString);
                printArExpr_v2(boolExpr->attr.bool_op.left, tabs + 1);
                printArExpr_v2(boolExpr->attr.bool_op.right, tabs + 1);
                printf("%s)\n", tabString);
                break;
            case DIFF:
                printf("%sDIFF(\n", tabString);
                printArExpr_v2(boolExpr->attr.bool_op.left, tabs + 1);
                printArExpr_v2(boolExpr->attr.bool_op.right, tabs + 1);
                printf("%s)\n", tabString);;
                break;
            case LESS:
                printf("%sLESS(\n", tabString);
                printArExpr_v2(boolExpr->attr.bool_op.left, tabs + 1);
                printArExpr_v2(boolExpr->attr.bool_op.right, tabs + 1);
                printf("%s)\n", tabString);
                break;
            case GREATER:
                printf("%sGREATER(\n", tabString);
                printArExpr_v2(boolExpr->attr.bool_op.left, tabs + 1);
                printArExpr_v2(boolExpr->attr.bool_op.right, tabs + 1);
                printf("%s)\n", tabString);
                break;
            case LESS_EQUAL:
                printf("%sLESS_EQUAL(\n", tabString);
                printArExpr_v2(boolExpr->attr.bool_op.left, tabs + 1);
                printArExpr_v2(boolExpr->attr.bool_op.right, tabs + 1);
                printf("%s)\n", tabString);
                break;
            case GREATER_EQUAL:
                printf("%sGREATER_EQUAL(\n", tabString);
                printArExpr_v2(boolExpr->attr.bool_op.left, tabs + 1);
                printArExpr_v2(boolExpr->attr.bool_op.right, tabs + 1);
                printf("%s)\n", tabString);
                break;
            default: yyerror("Unkown boolean operator");
        }
    }
}


void printExpr_v2(Expr* expr, long tabs) {

    char tabString[4 * tabs + 1]; 

    for (int i = 0; i < 4 * tabs; i++) {
        tabString[i] = ' ';
    }

    tabString[4 * tabs] = '\0';

    if (expr == 0) {
        yyerror("Null expression");
    }
    else if (expr->kind == EXPR_ARITHMETIC) {
        printf("%sARITHMETIC_EXPRESSION(\n", tabString);
        printArExpr_v2(expr->attr.ar_expr, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (expr->kind == EXPR_BOOLEAN) {
        printf("%sBOOLEAN_EXPRESSION(\n", tabString);
        printBoolExpr_v2(expr->attr.bool_expr, tabs + 1);
        printf("%s)\n", tabString);
    }
}

void printDclr_v2(Dclr* dclr, long tabs) {

    char tabString[4 * tabs + 1]; 

    for (int i = 0; i < 4 * tabs; i++) {
        tabString[i] = ' ';
    }

    tabString[4 * tabs] = '\0';

    if (dclr == 0) {}
    else if (dclr->kind == DCLR_COMPOUND) {
        printf("%sDCLR_COMPOUND(\n", tabString);
        printDclr_v2(dclr->attr.dclr_compound.first, tabs + 1);
        printDclr_v2(dclr->attr.dclr_compound.second, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (dclr->kind == DCLR_SIMPLE) {
        printf("%s%s(%s)\n", tabString, dclr->attr.dclr_simple.type, dclr->attr.dclr_simple.id);
    }
    else if (dclr->kind == DCLR_ASSIGNMENT) {
        printf("%s (%s) = ", dclr->attr.dclr_assignment.id, dclr->attr.dclr_assignment.type);
        printExpr_v2(dclr->attr.dclr_assignment.expr, tabs + 1);
    }
}

void printPckg_v2(Pckg* pckg, long tabs) {
    
    char tabString[4 * tabs + 1]; 

    for (int i = 0; i < 4 * tabs; i++) {
        tabString[i] = ' ';
    }

    tabString[4 * tabs] = '\0';

    if (pckg == 0) {
        yyerror("Null package");
    }
    else if (pckg->kind == PCKG_SIMPLE) {
        printf("%s", pckg->attr.pckg_id);
    }
    else if (pckg->kind == PCKG_COMPOUND) {
        printf("%s", tabString);
        printPckg_v2(pckg->attr.compound.first, tabs);
        printf(".");
        printPckg_v2(pckg->attr.compound.second, tabs);
        printf("\n");
    }
}

void printStm_v2(Stm* stm, long tabs) {
    
    char tabString[4 * tabs + 1]; 

    for (int i = 0; i < 4 * tabs; i++) {
        tabString[i] = ' ';
    }

    tabString[4 * tabs] = '\0';

    if (stm == 0) {
        yyerror("Null statement");
    }
    else if (stm->kind == STM_COMPOUND) {
        printf("%sCOMPOUND_STM(\n", tabString);
        printStm_v2(stm->attr.compound.first, tabs + 1);
        printStm_v2(stm->attr.compound.second, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (stm->kind == STM_ASSIGNMENT) {
        printf("%sASSIGN_STM(\n%s    %s\n", tabString, tabString, stm->attr.assign.ident);
        printExpr_v2(stm->attr.assign.expr, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (stm->kind == STM_IF_THEN) {
        printf("%sIF_THEN(\n", tabString);
        printExpr_v2(stm->attr.if_then.condition, tabs + 1);
        printStm_v2(stm->attr.if_then.then_branch, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (stm->kind == STM_IF_THEN_ELSE) {
        printf("%sIF(\n", tabString);
        printExpr_v2(stm->attr.if_then_else.condition, tabs + 1);
        printf("%sTHEN\n", tabString);
        printStm_v2(stm->attr.if_then_else.then_branch, tabs + 1);
        printf("%sELSE\n", tabString);
        printStm_v2(stm->attr.if_then_else.else_branch, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (stm->kind == STM_WITH) {
        printf("%sWITH(\n", tabString);
        printPckg_v2(stm->attr.pckg_with, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (stm->kind == STM_USE) {
        printf("%sUSE(\n", tabString);
        printPckg_v2(stm->attr.pckg_use, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (stm->kind == STM_PROCEDURE) {
        printf("%sPROCEDURE(%s) (\n", tabString, stm->attr.stm_proc.proc_id);
            if (stm->attr.stm_proc.dclr != 0) {
            printDclr_v2(stm->attr.stm_proc.dclr, tabs + 1);
        }
        printStm_v2(stm->attr.stm_proc.body, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (stm->kind == STM_FUNCTION) {
        printf("%sFUNCTION(\n%s    %s(\n", tabString, tabString, stm->attr.stm_func.func_id);
        printExpr_v2(stm->attr.stm_func.arg, tabs + 2);
        printf("%s    )\n", tabString);
        printf("%s)\n", tabString);
    }
}
