#include <stdint.h>

#ifndef __IC_H__
#define __IC_H__

typedef enum {
    MOVE,           // t1 := t2
    MOVEI,          // t1 := num
    OP,             // t1 := t2 op t3
    OPI,            // t1 := t2 op num
    LABEL,
    JUMP,
    COND
} Opcode;

typedef intptr_t Addr;

typedef struct {
    Opcode opcode;
    Addr arg1, arg2, arg3;
} Instr;

struct _ic_node {
    Instr* instr;
    struct _ic_node* next;
};

typedef struct _ic_node ic_node;

extern ic_node* ic_head;
extern ic_node* ic_tail;




#endif
