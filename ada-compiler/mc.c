#include <stdlib.h>
#include <stdio.h>
#include "mc.h"
#include "ast.h"
#include "ic.h"
#include "st.h"


void mc_print_instr(Instr* instr) {
    switch (instr->opcode) {
        case MOVE:
            printf("move $t%ld, $t%ld", instr->arg1, instr->arg2);
            break;
        case MOVEI:
            printf("li $t%ld, %ld", instr->arg1, instr->arg2);
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
            printf("$t%ld, $t%ld, $t%ld", instr->arg1, instr->arg2, instr->arg3);
            break;
        case LOAD:
            printf("lw $t%ld, %s", instr->arg1, addr_to_var_name(instr->arg2));
            break;
        case STORE:
            printf("sw $t%ld, %s", instr->arg1, addr_to_var_name(instr->arg2));
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

    printf(".text\n");
    printf("main:\n");
    ic_node* cur = ic_head;
    while (cur != NULL) {
        mc_print_instr(cur->instr);
        cur = cur->next;
    }
}
