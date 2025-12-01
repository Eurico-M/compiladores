#include <stdlib.h>
#include <string.h>
#include "ic.h"
#include "ast.h"
#include "parser.h"
#include "st.h"

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

void transArExp(ArExpr* ar_expr, int dest) {
    switch (ar_expr->kind) {
        case INT:

    }
}

void transExp(Expr* expr, int dest) {
    switch (expr->kind) {
        case EXPR_ARITHMETIC:

    }
}

void transStm(Stm* stm) {
    switch (stm->kind) {
        case STM_ASSIGNMENT:
            int dest = st_search(stm->attr.assign.ident);
            transExp(stm->attr.assign.expr, dest);
            break;
        case STM_COMPOUND:
            transStm(stm->attr.compound.first);
            transStm(stm->attr.compound.second);
            break;
    }
}
