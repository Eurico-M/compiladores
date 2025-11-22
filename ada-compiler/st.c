#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "st.h"
#include "ast.h"

void print_st(st_node* head) {
    st_node* cursor = head;
    while (cursor != NULL) {
        printf("ID: %s -> TYPE: %s", cursor->id, cursor->type);
    }
}

st_node* st_insert(st_node* head, char* id, char* type) {
    st_node* new_node = (st_node*) malloc(sizeof(st_node));
    new_node->id = strdup(id);
    new_node->type = strdup(type);
    new_node->next = head;
    return new_node;
}

char* st_search(st_node* head, char* id) {
    st_node* cursor = head;
    while (cursor != NULL) {
        if (strcmp(cursor->id, id) == 0) {
            return cursor->type;
        }
        cursor = cursor->next;
    }
    return "invalid type";
}

void st_build_dclr(Dclr* dclr, st_node* head) {
    if (dclr->kind == DCLR_COMPOUND) {
        st_build_dclr(dclr->attr.dclr_compound.first, head);
        st_build_dclr(dclr->attr.dclr_compound.second, head);
    }
    else if (dclr->kind == DCLR_SIMPLE) {
        head = st_insert(head, dclr->attr.dclr_simple.id, dclr->attr.dclr_simple.type);
    }
    else if (dclr->kind == DCLR_ASSIGNMENT) {
        head = st_insert(head, dclr->attr.dclr_assignment.id, dclr->attr.dclr_assignment.type);
    }
}

void st_build_stm(Stm* program, st_node* head) {
    if (program->kind == STM_PROCEDURE) {
        st_build_dclr(program->attr.stm_proc.dclr, head);
        st_build_stm(program->attr.stm_proc.body, head);
    }
    else if (program->kind == STM_COMPOUND) {
        st_build_stm(program->attr.compound.first, head);
        st_build_stm(program->attr.compound.second, head);
    }
}
