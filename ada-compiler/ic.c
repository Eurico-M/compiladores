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
        case IC_DIV:
            printf("t%ld := t%ld / t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case IC_MUL:
            printf("t%ld := t%ld * t%ld", instr->arg1, instr->arg2, instr->arg3);
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
void emit(Opcode opc, Addr arg1, Addr arg2, Addr arg3) {
    Instr* node = (Instr*)malloc(sizeof(Instr));
    node->opcode = opc;
    node->arg1 = arg1;
    node->arg2 = arg2;
    node->arg3 = arg3;
    ic_insert(node);
}

void transArExp(ArExpr* ar_expr, Addr dest) {
    switch (ar_expr->kind) {
        case INT:
            emit(MOVEI, dest, ar_expr->attr.int_val, NULO);
            break;
        case ID:
            Addr temp = st_search(ar_expr->attr.id);                        
            emit(LOAD, dest, temp, NULO);                                   
            break;
        case AR_OP:
            Addr t1 = newTemp();
            Addr t2 = newTemp();
            transArExp(ar_expr->attr.ar_op.left, t1);
            transArExp(ar_expr->attr.ar_op.right, t2);
            popTemp(2);
            switch (ar_expr->attr.ar_op.op) {
                case PLUS:
                    emit(IC_ADD, dest, t1, t2);
                    break;
                case MINUS:
                    emit(IC_SUB, dest, t1, t2);
                    break;
                case TIMES:
                    emit(IC_MUL, dest, t1, t2);
                    break;
                case DIV:
                    emit(IC_DIV, dest, t1, t2);
                    break;
                case MOD:
                    emit(IC_MOD, dest, t1, t2);
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
            Addr dest = st_search(dclr->attr.dclr_assignment.id);
            transExp(dclr->attr.dclr_assignment.expr, dest);
            break;
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
            emit(LOAD, t1, t2, NULO);
            transExp(stm->attr.assign.expr, t1);
            emit(STORE, t1, t2, NULO);
            popTemp(1);
            break;
        case STM_COMPOUND:
            transStm(stm->attr.compound.first);
            transStm(stm->attr.compound.second);
            break;
    }
}
