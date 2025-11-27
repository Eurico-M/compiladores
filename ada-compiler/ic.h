#include <stdint.h>

#ifndef __IC_H__
#define __IC_H__

typedef enum {
    MOVE,
    MOVEI
} Opcode;

typedef intptr_t Addr;

typedef struct {
    Opcode opcode;
    Addr arg1, arg2, arg3;
} Instr;

#endif
