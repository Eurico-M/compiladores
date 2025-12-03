#include <stdlib.h>
#include <stdio.h>
#include "mc.h"
#include "ast.h"
#include "ic.h"


void mc_print_instr(Instr* instr) {
    switch (instr->opcode) {
        case MOVE:
            printf("move $t%d, $t%d", instr->arg1, instr->arg2);
            break;
        case MOVEI:
            printf("li $t%d, $t%d", instr->arg1, instr->arg2);
            break;
        case OP:
            switch (instr->binop) {
                case PLUS:
                    printf("add ");
                    break;
                case MINUS:
                    printf("sub ");
                    break;
                case TIMES:
                    printf("mul ");
                    break;
                case DIV:
                    printf("div ");
                    break;
                case MOD:
                    printf("rem ");
                    break;
            }
            printf("$t%d, $t%d, $t%d", instr->arg1, instr->arg2, instr->arg3);
            break;
    }
    printf("\n");
}


void mc_print() {
    ic_node* cur = ic_head;
    while (cur != NULL) {
        mc_print_instr(cur->instr);
        cur = cur->next;
    }
}
