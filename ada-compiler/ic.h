#include <stdint.h>
#include "ast.h"

#ifndef __IC_H__
#define __IC_H__

typedef enum {
    MOVE,           // t1 := t2
    MOVEI,          // t1 := num
    OP,             // t1 := t2 op t3
    OPI,            // t1 := t2 op num
    LABEL,
    JUMP,
    COND,
    LOAD,
    STORE,
    IC_ADD,
    IC_SUB,
    IC_MUL,
    IC_DIV,
    IC_MOD,
    IC_EQ,
    IC_NE,
    IC_GT,
    IC_LT
} Opcode;

// typedef enum {
//     IC_PLUS,
//     IC_MINUS,
//     IC_MULT,
//     IC_DIV,
//     IC_MOD
// } BinOp;

typedef intptr_t Addr;

typedef struct {
    Opcode opcode;
    Addr arg1, arg2, arg3, arg4;
    // BinOp binop;
    // ar_op binop;
} Instr;

struct _ic_node {
    Instr* instr;
    struct _ic_node* next;
};

typedef struct _ic_node ic_node;

extern ic_node* ic_head;
extern ic_node* ic_tail;

void transStm(Stm* stm);
void ic_print();
char* addr_to_var_name(Addr addr);


#endif
