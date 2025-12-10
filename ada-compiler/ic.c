#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ic.h"
#include "ast.h"
#include "st.h"

#define NULO -1
#define MAX_TEMPS 10000

// inicializar a lista ligada
ic_node* ic_head = NULL;
ic_node* ic_tail = NULL;

// inicializar contadores de temporaŕios e labels
int temp_count = 0;
int label_count = 0;

int newTemp() {
    return temp_count++;
}

void popTemp(int k) {
    temp_count -= k;
}

int newLabel() {
    return label_count++;
}

char* addr_to_var_name(Addr addr) {
    return ((st_node*)addr)->id;
}


// imprimir uma instrução
void print_instr(Instr* instr) {
    switch (instr->opcode) {
        case MOVE:
            printf("t%ld := t%ld", instr->arg1, instr->arg2);
            break;
        case MOVEI:
            printf("t%ld := %ld", instr->arg1, instr->arg2);
            break;
        case IC_ADD:
            printf("t%ld := t%ld + t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case IC_SUB:
            printf("t%ld := t%ld - t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case IC_MUL:
            printf("t%ld := t%ld * t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case IC_DIV:
            printf("t%ld := t%ld / t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case IC_MOD:
            printf("t%ld := t%ld %% t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case LOAD:
            printf("t%ld <- %s", instr->arg1, addr_to_var_name(instr->arg2));
            break;
        case STORE:
            printf("t%ld -> %s", instr->arg1, addr_to_var_name(instr->arg2));
            break;
        case IC_EQ:
            printf("COND t%ld == t%ld label%ld label%ld", instr->arg1, instr->arg2, instr->arg3, instr->arg4);
            break;
        case IC_NE:
            printf("COND t%ld != t%ld label%ld label%ld", instr->arg1, instr->arg2, instr->arg3, instr->arg4);
            break;
        case IC_GT:
            printf("COND t%ld > t%ld label%ld label%ld", instr->arg1, instr->arg2, instr->arg3, instr->arg4);
            break;
        case IC_LT:
            printf("COND t%ld < t%ld label%ld label%ld", instr->arg1, instr->arg2, instr->arg3, instr->arg4);
            break;
        case LABEL:
            printf("LABEL label%ld", instr->arg1);
            break;
        case IC_GE:
            printf("COND t%ld >= t%ld label%ld label%ld", instr->arg1, instr->arg2, instr->arg3, instr->arg4);
            break;
        case IC_LE:
            printf("COND t%ld <= t%ld label%ld label%ld", instr->arg1, instr->arg2, instr->arg3, instr->arg4);
            break;
        case JUMP:
            printf("JUMP label%ld", instr->arg1);
            break;
        case PUTI:
            printf("PUT %ld", instr->arg1);
            break;
        case PUT:
            printf("PUT t%ld", instr->arg1);
            break;
        case GET:
            printf("GET %s", addr_to_var_name(instr->arg1));
            break;
    }
    printf("\n");
}

// imprimir lista de instruções
void ic_print() {
    ic_node* cur = ic_head;
    while (cur != NULL) {
        print_instr(cur->instr);
        cur = cur->next;
    }
}

// inserir uma Instrução na lista, criando um nó para suportar lista ligada
void ic_insert(Instr* instr) {
    ic_node* node = (ic_node*)malloc(sizeof(ic_node));
    node->instr = instr;
    node->next = NULL;

    // primeiro nó adicionado
    if (ic_tail == NULL) {
        ic_head = ic_tail = node;
    }
    // adicionar ao fim da lista
    else {
        ic_tail->next = node;
        ic_tail = node;
    }
}

// criar uma Instrução em código intermédio
void emit(Opcode opc, Addr arg1, Addr arg2, Addr arg3, Addr arg4) {
    Instr* node = (Instr*)malloc(sizeof(Instr));
    node->opcode = opc;
    node->arg1 = arg1;
    node->arg2 = arg2;
    node->arg3 = arg3;
    node->arg4 = arg4;
    ic_insert(node);
}

void transArExp(ArExpr* ar_expr, Addr dest) {
    switch (ar_expr->kind) {
        case INT:
            emit(MOVEI, dest, ar_expr->attr.int_val, NULO, NULO);       // dest := num
            break;
        case ID:
            Addr temp = st_search(ar_expr->attr.id);                    // temp = lookup(id,table)
            emit(LOAD, dest, temp, NULO, NULO);                         // dest := temp
            break;
        case AR_OP:
            Addr t1 = newTemp();
            Addr t2 = newTemp();
            transArExp(ar_expr->attr.ar_op.left, t1);
            transArExp(ar_expr->attr.ar_op.right, t2);
            popTemp(2);
            switch (ar_expr->attr.ar_op.op) {
                case PLUS:
                    emit(IC_ADD, dest, t1, t2, NULO);
                    break;
                case MINUS:
                    emit(IC_SUB, dest, t1, t2, NULO);
                    break;
                case TIMES:
                    emit(IC_MUL, dest, t1, t2, NULO);
                    break;
                case DIV:
                    emit(IC_DIV, dest, t1, t2, NULO);
                    break;
                case MOD:
                    emit(IC_MOD, dest, t1, t2, NULO);
                    break;
            }
            break;

    }
}


void transExp(Expr* expr, Addr dest) {
    switch (expr->kind) {
        case EXPR_ARITHMETIC:
            transArExp(expr->attr.ar_expr, dest);
            break;
    }
}

void transDclr(Dclr* dclr) {
    switch (dclr->kind) {
        case DCLR_SIMPLE:
            break;
        case DCLR_ASSIGNMENT:
            Addr t1 = newTemp();
            Addr t2 = st_search(dclr->attr.dclr_assignment.id);
            emit(LOAD, t1, t2, NULO, NULO);
            transExp(dclr->attr.dclr_assignment.expr, t1);
            emit(STORE, t1, t2, NULO, NULO);
            popTemp(1);
            break;
        case DCLR_COMPOUND:
            transDclr(dclr->attr.dclr_compound.first);
            transDclr(dclr->attr.dclr_compound.second);
            break;
    }
}

void transCond(Cnd* cnd, Addr label_true, Addr label_false) {
    switch (cnd->kind) {
        case CND_RELOP:
            Addr t1 = newTemp();
            Addr t2 = newTemp();
            transArExp(cnd->attr.cnd_relop.left, t1);
            transArExp(cnd->attr.cnd_relop.right, t2);
            switch (cnd->attr.cnd_relop.op) {
                case RL_EQ:
                    emit(IC_EQ, t1, t2, label_true, label_false);
                    break;
                case RL_NE:
                    emit(IC_NE, t1, t2, label_true, label_false);
                    break;
                case RL_GT:
                    emit(IC_GT, t1, t2, label_true, label_false);
                    break;
                case RL_LT:
                    emit(IC_LT, t1, t2, label_true, label_false);
                    break;
                case RL_LE:
                    emit(IC_LE, t1, t2, label_true, label_false);
                    break;
                case RL_GE:
                    emit(IC_GE, t1, t2, label_true, label_false);
                    break;
            }
            popTemp(2);
            break;

        case CND_CNST:
            switch (cnd->attr.c) {
                case True:
                    emit(JUMP, label_true, NULO, NULO, NULO);
                    break;
                case False:
                    emit(JUMP, label_false, NULO, NULO, NULO);
                    break;
            }
            break;
        
        case CND_LGOP:
            switch (cnd->attr.cnd_lgop.op) {
                case LG_NOT:
                    transCond(cnd->attr.cnd_lgop.left, label_false, label_true);
                    break;
                case LG_AND:
                    Addr label_and = newLabel();
                    transCond(cnd->attr.cnd_lgop.left, label_and, label_false);
                    emit(LABEL, label_and, NULO, NULO, NULO);
                    transCond(cnd->attr.cnd_lgop.right, label_true, label_false);
                    break;
                case LG_OR:
                    Addr label_or = newLabel();
                    transCond(cnd->attr.cnd_lgop.left, label_true, label_or);
                    emit(LABEL, label_or, NULO, NULO, NULO);
                    transCond(cnd->attr.cnd_lgop.right, label_true, label_false);
                    break;
            }
            break;
    }
}

void transFnc(Stm* stm) {
    if (strcmp(stm->attr.stm_func.func_id, "Put_Line") == 0) {
        switch (stm->attr.stm_func.arg->kind) {
            case INT:
                emit(PUTI, stm->attr.stm_func.arg->attr.int_val, NULO, NULO, NULO);
                break;
            default:
                Addr t1 = newTemp();
                transArExp(stm->attr.stm_func.arg, t1);
                emit(PUT, t1, NULO, NULO, NULO);
                popTemp(1);
                break;
        }
    }
    else if (strcmp(stm->attr.stm_func.func_id, "Get_Line") == 0) {
        Addr dest = st_search(stm->attr.stm_func.arg->attr.id);
        emit(GET, dest, NULO, NULO, NULO);
    }
}

void transStm(Stm* stm) {
    switch (stm->kind) {
        case STM_PROCEDURE:
            transDclr(stm->attr.stm_proc.dclr);
            transStm(stm->attr.stm_proc.body);
            break;
        case STM_ASSIGNMENT:
            Addr t1 = newTemp();
            Addr t2 = st_search(stm->attr.assign.ident);
            emit(LOAD, t1, t2, NULO, NULO);
            transExp(stm->attr.assign.expr, t1);
            emit(STORE, t1, t2, NULO, NULO);
            popTemp(1);
            break;
        case STM_COMPOUND:
            transStm(stm->attr.compound.first);
            transStm(stm->attr.compound.second);
            break;
        case STM_IF_THEN:
            Addr label1 = newLabel();
            Addr label2 = newLabel();
            transCond(stm->attr.if_then.condition, label1, label2);
            emit(LABEL, label1, NULO, NULO, NULO);
            transStm(stm->attr.if_then.then_branch);
            emit(LABEL, label2, NULO, NULO, NULO);
            break;
        case STM_IF_THEN_ELSE:
            Addr label3 = newLabel();
            Addr label4 = newLabel();
            Addr label5 = newLabel();
            transCond(stm->attr.if_then_else.condition, label3, label4);
            emit(LABEL, label3, NULO, NULO, NULO);
            transStm(stm->attr.if_then_else.then_branch);
            emit(JUMP, label5, NULO, NULO, NULO);
            emit(LABEL, label4, NULO, NULO, NULO);
            transStm(stm->attr.if_then_else.else_branch);
            emit(LABEL, label5, NULO, NULO, NULO);
            break;
        case STM_WHILE:
            Addr label6 = newLabel();
            Addr label7 = newLabel();
            Addr label8 = newLabel();
            emit(LABEL, label6, NULO, NULO, NULO);
            transCond(stm->attr.while_stm.condition, label7, label8);
            emit(LABEL, label7, NULO, NULO, NULO);
            transStm(stm->attr.while_stm.body);
            emit(JUMP, label6, NULO, NULO, NULO);
            emit(LABEL, label8, NULO, NULO, NULO);
            break;
        case STM_FUNCTION:
            transFnc(stm);
            break;

    }
}
