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
    else if (arExpr->tag == BOOLEAN) {
        if (arExpr->attr.boolean_ent) {
            printf("%strue\n", tabString);
        }
        else {
            printf("%sfalse\n", tabString);
        }
    }
    else if(arExpr->tag == DELIMITED_AR_EXPR) {
        printArExpr_v2(arExpr->attr.delimited_ar_expr, tabs);
    }
    else if (arExpr->tag == AR_OP) {
        switch (arExpr->attr.ar_op.op) {
            case PLUS:
                printf("%sPLUS(\n", tabString);
                break;
            case MINUS:
                printf("%sMINUS(\n", tabString);
                break;
            case TIMES:
                printf("%sTIMES(\n", tabString);
                break;
            case DIV:
                printf("%sDIV(\n", tabString);
                break;
            case MOD:
                printf("%sMOD(\n", tabString);
                break;
            default: yyerror("Unkown arithmetic operator");
        }
        printArExpr_v2(arExpr->attr.ar_op.left, tabs + 1);
        printArExpr_v2(arExpr->attr.ar_op.right, tabs + 1);
        printf("%s)\n", tabString);
    }
}

void printBoolExpr_v2(BoolExpr* boolExpr, long tabs) {

    char tabString[4 * tabs + 1];

    for (int i = 0; i < 4 * tabs; i++) {
        tabString[i] = ' ';
    }

    tabString[4 * tabs] = '\0';

    if (boolExpr == 0) {}
    else if (boolExpr->tag == DELIMITED_BOOL_EXPR) {
        printBoolExpr_v2(boolExpr->attr.delimited_bool_expr, tabs);
    }
    else if (boolExpr->tag == BOOL_OP) {
        switch (boolExpr->attr.bool_op.op) {
            case EQUAL:
                printf("%sEQUAL(\n", tabString);
                break;
            case DIFF:
                printf("%sDIFF(\n", tabString);
                break;
            case LESS:
                printf("%sLESS(\n", tabString);
                break;
            case GREATER:
                printf("%sGREATER(\n", tabString);
                break;
            case LESS_EQUAL:
                printf("%sLESS_EQUAL(\n", tabString);
                break;
            case GREATER_EQUAL:
                printf("%sGREATER_EQUAL(\n", tabString);
                break;
            default: yyerror("Unkown boolean operator");
        }
        printArExpr_v2(boolExpr->attr.bool_op.left, tabs + 1);
        printArExpr_v2(boolExpr->attr.bool_op.right, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (boolExpr->tag == BOOL_OP2) {
        switch (boolExpr->attr.bool_op2.op){
            case AND:
                printf("%sAND(\n", tabString);
                break;
            case OR:
                printf("%sOR(\n", tabString);
                break;
            case XOR:
                printf("%sXOR(\n", tabString);
                break;
            case NOT:
                printf("%sNOT(\n", tabString);
                break;
            default: yyerror("Unkown boolean operator");
        }
        printBoolExpr_v2(boolExpr->attr.bool_op2.left, tabs + 1);
        printBoolExpr_v2(boolExpr->attr.bool_op2.right, tabs + 1);
        printf("%s)\n", tabString);
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
    else if (expr->kind == EXPR_STRING) {
        printf("%sSTRING(\"%s\")\n)", tabString, expr->attr.string_expr);
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
        // printf("%sDCLR_COMPOUND(\n", tabString);
        // printDclr_v2(dclr->attr.dclr_compound.first, tabs + 1);
        // printDclr_v2(dclr->attr.dclr_compound.second, tabs + 1);
        // printf("%s)\n", tabString);

        printDclr_v2(dclr->attr.dclr_compound.first, tabs);
        printDclr_v2(dclr->attr.dclr_compound.second, tabs);
    }
    else if (dclr->kind == DCLR_SIMPLE) {
        printf("%sDCLR_SIMPLE(\n", tabString);
        printf("%s    %s(%s)\n", tabString, dclr->attr.dclr_simple.type, dclr->attr.dclr_simple.id);
        printf("%s)\n", tabString);
    }
    else if (dclr->kind == DCLR_ASSIGNMENT) {
        printf("%sDCLR_ASSIGN(\n", tabString);
        printf("%s    %s(%s) =\n", tabString, dclr->attr.dclr_assignment.type, dclr->attr.dclr_assignment.id);
        printExpr_v2(dclr->attr.dclr_assignment.expr, tabs + 2);
        printf("%s)\n", tabString);
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
        // printf("%sCOMPOUND_STM(\n", tabString);
        // printStm_v2(stm->attr.compound.first, tabs + 1);
        // printStm_v2(stm->attr.compound.second, tabs + 1);
        // printf("%s)\n", tabString);

        printStm_v2(stm->attr.compound.first, tabs);
        printStm_v2(stm->attr.compound.second, tabs);
    }
    else if (stm->kind == STM_ASSIGNMENT) {
        printf("%sASSIGN(\n%s    ID(%s)\n", tabString, tabString, stm->attr.assign.ident);
        printExpr_v2(stm->attr.assign.expr, tabs + 1);
        printf("%s)\n", tabString);
    }
    else if (stm->kind == STM_IF_THEN) {
        printf("%sIF(\n", tabString);
        printExpr_v2(stm->attr.if_then.condition, tabs + 1);
        printf("%s) THEN(\n", tabString);
        printStm_v2(stm->attr.if_then.then_branch, tabs + 1);
        printf("%s) END_IF\n", tabString);
    }
    else if (stm->kind == STM_IF_THEN_ELSE) {
        printf("%sIF(\n", tabString);
        printExpr_v2(stm->attr.if_then_else.condition, tabs + 1);
        printf("%s) THEN(\n", tabString);
        printStm_v2(stm->attr.if_then_else.then_branch, tabs + 1);
        printf("%s)\n", tabString);
        printf("%sELSE(\n", tabString);
        printStm_v2(stm->attr.if_then_else.else_branch, tabs + 1);
        printf("%s) END_IF\n", tabString);
    }
    else if (stm->kind == STM_WHILE) {
        printf("%sWHILE(\n", tabString);
        printExpr_v2(stm->attr.while_stm.condition, tabs + 1);
        printf("%s) LOOP(\n", tabString);
        printStm_v2(stm->attr.while_stm.body, tabs + 1);
        printf("%s) END_LOOP\n", tabString);
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
        printf("%sPROCEDURE(%s) IS(\n", tabString, stm->attr.stm_proc.proc_id);
        if (stm->attr.stm_proc.dclr != 0) {
            printDclr_v2(stm->attr.stm_proc.dclr, tabs + 1);
        }
        printf("%sBEGIN(\n", tabString);
        printStm_v2(stm->attr.stm_proc.body, tabs + 1);
        printf("%s)) END_%s\n", tabString, stm->attr.stm_proc.proc_id);
    }
    else if (stm->kind == STM_FUNCTION) {
        printf("%sFUNCTION(\n%s    %s(\n", tabString, tabString, stm->attr.stm_func.func_id);
        printExpr_v2(stm->attr.stm_func.arg, tabs + 2);
        printf("%s    )\n", tabString);
        printf("%s)\n", tabString);
    }
}
