#include <stdlib.h>
#include <stdio.h>
#include "mc.h"
#include "ic.h"
#include "st.h"


long addr_temp_mips(Addr a) {
    return a + 8;
}


void mc_print_instr(Instr* instr, FILE* out) {
    switch (instr->opcode) {
        case MOVE:
            fprintf(out, "    move $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2));
            break;
        case MOVEI:
            fprintf(out, "    li $%ld, %ld\n", addr_temp_mips(instr->arg1), instr->arg2);
            break;
        case IC_ADD:
            fprintf(out, "    add $%ld, $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), addr_temp_mips(instr->arg3));
            break;
        case IC_MUL:
            fprintf(out, "    mul $%ld, $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), addr_temp_mips(instr->arg3));
            break;
        case IC_SUB:
            fprintf(out, "    sub $%ld, $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), addr_temp_mips(instr->arg3));
            break;
        case IC_DIV:
            fprintf(out, "    div $%ld, $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), addr_temp_mips(instr->arg3));
            break;
        case IC_MOD:
            fprintf(out, "    rem $%ld, $%ld, $%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), addr_temp_mips(instr->arg3));
            break;
        case LOAD:
            fprintf(out, "    lw $%ld, %s\n", addr_temp_mips(instr->arg1), addr_to_var_name(instr->arg2));
            break;
        case STORE:
            fprintf(out, "    sw $%ld, %s\n", addr_temp_mips(instr->arg1), addr_to_var_name(instr->arg2));
            break;
        case LABEL:
            fprintf(out, "label%ld:\n", instr->arg1);
            break;
        case IC_EQ:
            fprintf(out, "    beq $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            fprintf(out, "    j label%ld\n", instr->arg4);
            break;
        case IC_NE:
            fprintf(out, "    bne $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            fprintf(out, "    j label%ld\n", instr->arg4);
            break;
        case IC_LT:
            fprintf(out, "    blt $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            fprintf(out, "    j label%ld\n", instr->arg4);
            break;
        case IC_GT:
            fprintf(out, "    bgt $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            fprintf(out, "    j label%ld\n", instr->arg4);
            break;
        case IC_GE:
            fprintf(out, "    bge $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            fprintf(out, "    j label%ld\n", instr->arg4);
            break;
        case IC_LE:
            fprintf(out, "    ble $%ld, $%ld, label%ld\n", addr_temp_mips(instr->arg1), addr_temp_mips(instr->arg2), instr->arg3);
            fprintf(out, "    j label%ld\n", instr->arg4);
            break;
        case JUMP:
            fprintf(out, "    j label%ld\n", instr->arg1);
            break;
        case PUTI:
            fprintf(out, "    li $v0, 1\n");
            fprintf(out, "    li $a0, %ld\n", instr->arg1);
            fprintf(out, "    syscall\n");
            break;
        case PUT:
            fprintf(out, "    li $v0, 1\n");
            fprintf(out, "    move $a0, $%ld\n", addr_temp_mips(instr->arg1));
            fprintf(out, "    syscall\n");
            break;
        case GET:
            fprintf(out, "    li $v0, 5\n");
            fprintf(out, "    syscall\n");
            fprintf(out, "    sw $v0, %s\n", addr_to_var_name(instr->arg1));
            break;

    }
}

void mc_print_vars(char* id, FILE* out) {
    fprintf(out, "%s: .word 0\n", id);
}

void mc_print(FILE* out) {
    fprintf(out, ".data\n");
    st_node* kur = st_head;
    while (kur != NULL) {
        mc_print_vars(kur->id, out);
        kur = kur->next;
    }
    fprintf(out, "\n");
    fprintf(out, ".text\n");
    fprintf(out, "main:\n");
    ic_node* cur = ic_head;
    while (cur != NULL) {
        mc_print_instr(cur->instr, out);
        cur = cur->next;
    }
}
