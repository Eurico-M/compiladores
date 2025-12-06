#include <stdlib.h>
#include <stdio.h>
#include "mc.h"
#include "ic.h"
#include "st.h"


void mc_print_instr(Instr* instr) {
    switch (instr->opcode) {
        case MOVE:
            printf("    move $t%ld, $t%ld", instr->arg1, instr->arg2);
            break;
        case MOVEI:
            printf("    li $t%ld, %ld", instr->arg1, instr->arg2);
            break;
        case IC_ADD:
            printf("    add $t%ld, $t%ld, $t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case IC_MUL:
            printf("    mul $t%ld, $t%ld, $t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case IC_SUB:
            printf("    sub $t%ld, $t%ld, $t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case IC_DIV:
            printf("    div $t%ld, $t%ld, $t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case IC_MOD:
            printf("    rem $t%ld, $t%ld, $t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case LOAD:
            printf("    lw $t%ld, %s", instr->arg1, addr_to_var_name(instr->arg2));
            break;
        case STORE:
            printf("    sw $t%ld, %s", instr->arg1, addr_to_var_name(instr->arg2));
            break;
        case LABEL:
            printf("label%ld:", instr->arg1);
            break;
        case IC_EQ:
            printf("    beq $t%ld, $t%ld, label%ld", instr->arg1, instr->arg2, instr->arg3);
            printf("\n");
            printf("j label%ld", instr->arg4);
            break;
        case IC_NE:
            printf("    bne $t%ld, $t%ld, label%ld", instr->arg1, instr->arg2, instr->arg3);
            printf("\n");
            printf("    j label%ld", instr->arg4);
            break;
        case IC_LT:
            printf("    blt $t%ld, $t%ld, label%ld", instr->arg1, instr->arg2, instr->arg3);
            printf("\n");
            printf("    j label%ld", instr->arg4);
            break;
        case IC_GT:
            printf("    bgt $t%ld, $t%ld, label%ld", instr->arg1, instr->arg2, instr->arg3);
            printf("\n");
            printf("    j label%ld", instr->arg4);
            break;

    }
    printf("\n");
}

void mc_print_vars(char* id) {
    printf("%s: .word 0\n", id);
}

void mc_print() {
    printf(".data\n");
    st_node* kur = st_head;
    while (kur != NULL) {
        mc_print_vars(kur->id);
        kur = kur->next;
    }
    printf("\n");
    printf(".text\n");
    printf("main:\n");
    ic_node* cur = ic_head;
    while (cur != NULL) {
        mc_print_instr(cur->instr);
        cur = cur->next;
    }
}
