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

// imprimir uma instrução
void print_ic(Instr* instr) {
    switch (instr->opcode) {
        case MOVE:
            printf("t%ld := t%ld\n", instr->arg1, instr->arg2);
            break;
        case MOVEI:
            printf("t%ld := t%ld\n", instr->arg1, instr->arg2);
            break;
        case OP:
            printf("t%ld := t%ld", instr->arg1, instr->arg2);
            switch (instr->binop) {
                case PLUS:
                    printf(" + ");
                    break;
                case MINUS:
                    printf(" - ");
                    break;
                case TIMES:
                    printf(" * ");
                    break;
                case DIV:
                    printf(" / ");
                    break;
                case MOD:
                    printf(" %% ");
                    break;
            }
            printf("t%ld\n", instr->arg3);
    }
}

// imprimir lista de instruções
void print_instrs() {
    ic_node* cur = ic_head;
    while (cur != NULL) {
        print_ic(cur->instr);
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
void emit(Opcode opc, Addr arg1, Addr arg2, Addr arg3, ar_op binop) {
    Instr* node = (Instr*)malloc(sizeof(Instr));
    node->opcode = opc;
    node->arg1 = arg1;
    node->arg2 = arg2;
    node->arg3 = arg3;
    node->binop = binop;
    ic_insert(node);
}

void transArExp(ArExpr* ar_expr, int dest) {
    switch (ar_expr->kind) {
        case INT:
            emit(MOVEI, dest, ar_expr->attr.int_val, NULL, NULL);       // dest := num
            break;
        case ID:
            int temp = st_search(ar_expr->attr.id);                     // temp = lookup(id,table)
            emit(MOVE, dest, temp, NULL, NULL);                         // dest := temp
            break;
        case AR_OP:
            int t1 = newTemp();
            int t2 = newTemp();
            transArExp(ar_expr->attr.ar_op.left, t1);
            transArExp(ar_expr->attr.ar_op.right, t2);
            emit(OP, dest, t1, t2, ar_expr->attr.ar_op.op);             // dest := t1 binop t2
            break;

    }
}

void transExp(Expr* expr, int dest) {
    switch (expr->kind) {
        case EXPR_ARITHMETIC:
            transArExp(expr->attr.ar_expr, dest);
            break;
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
