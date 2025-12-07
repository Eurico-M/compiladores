#include <stdlib.h>
#include <stdio.h>
#include "mc.h"
#include "ic.h"
#include "st.h"


long addr_temp_mips(Addr a) {
    return a + 8;
}


void mc_print_instr(Instr* instr) {
    switch (instr->opcode) {
        case MOVE:
            printf("    move $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2));
            break;
        case MOVEI:
            printf("    li $%ld, %ld\n", addr_temp_mips(instr->arg1), instr->arg2);
            break;
        case IC_ADD:
            printf("    add $%ld, $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), addr_temp_mips(instr->arg3));
            break;
        case IC_MUL:
            printf("    mul $%ld, $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), addr_temp_mips(instr->arg3));
            break;
        case IC_SUB:
            printf("    sub $%ld, $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), addr_temp_mips(instr->arg3));
            break;
        case IC_DIV:
            printf("    div $%ld, $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), addr_temp_mips(instr->arg3));
            break;
        case IC_MOD:
            printf("    rem $%ld, $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), addr_temp_mips(instr->arg3));
            break;
        case LOAD:
            printf("    lw $%ld, %s\n", addr_temp_mips(instr->arg1), addr_to_var_name(instr->arg2));
            break;
        case STORE:
            printf("    sw $%ld, %s\n", addr_temp_mips(instr->arg1), addr_to_var_name(instr->arg2));
            break;
        case LABEL:
            printf("label%ld:\n", instr->arg1);
            break;
        case IC_EQ:
            printf("    beq $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            printf("    j label%ld\n", instr->arg4);
            break;
        case IC_NE:
            printf("    bne $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            printf("    j label%ld\n", instr->arg4);
            break;
        case IC_LT:
            printf("    blt $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            printf("    j label%ld\n", instr->arg4);
            break;
        case IC_GT:
            printf("    bgt $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            printf("    j label%ld\n", instr->arg4);
            break;
        case IC_GE:
            printf("    bge $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            printf("    j label%ld\n", instr->arg4);
        case IC_LE:
            printf("    ble $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            printf("    j label%ld\n", instr->arg4);
        case JUMP:
            printf("    j label%ld\n", instr->arg1);
            break;
        case PUTI:
            printf("    li $v0, 1\n");
            printf("    li $a0, %ld\n", instr->arg1);
            printf("    syscall\n");
            break;
        case PUT:
            printf("    li $v0, 1\n");
            printf("    move $a0, $%ld\n", addr_temp_mips(instr->arg1));
            printf("    syscall\n");
            break;
        case GET:
            printf("    li $v0, 5\n");
            printf("    syscall\n");
            printf("    sw $v0, %s\n", addr_to_var_name(instr->arg1));
            break;

    }
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
