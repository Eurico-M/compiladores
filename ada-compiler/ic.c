#include <stdlib.h>
#include <string.h>
#include "ic.h"
#include "ast.h"
#include "parser.h"

ic_node* ic_head = NULL;
ic_node* ic_tail = NULL;

void ic_init() {
    ic_head = NULL;
    ic_tail = NULL;
}

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

void emit(Opcode opc, Addr arg1, Addr arg2, Addr arg3) {
    Instr* node = (Instr*)malloc(sizeof(Instr));
    node->opcode = opc;
    node->arg1 = arg1;
    node->arg2 = arg2;
    node->arg3 = arg3;
    ic_insert(node);
}

void transExp(Expr expr, dest) {
    switch (expr.kind) {

    }
}

void transStm(Stm stm) {
    switch (stm.kind) {
        case STM_ASSIGNMENT:


    }
}
