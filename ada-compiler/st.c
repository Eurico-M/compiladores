#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "st.h"
#include "ast.h"
#include "parser.h"

char* st_type_to_string(st_type type) {
    switch (type) {
        case ST_INTEGER:
            return "Integer";
        case ST_REAL:
            return "Real";
    }
}

void st_print(st_node* head) {
    st_node* cursor = head;
    while (cursor != NULL) {
        printf("ID: %s, TYPE: %s", cursor->id, st_type_to_string(cursor->type));
    }
}

st_node* st_insert(st_node* head, char* id, st_type type) {
    st_node* new_node = (st_node*) malloc(sizeof(st_node));
    new_node->id = strdup(id);
    new_node->type = type;
    new_node->next = head;
    return new_node;
}

st_type st_search(st_node* head, char* id) {
    st_node* cursor = head;
    while (cursor != NULL) {
        if (strcmp(cursor->id, id) == 0) {
            return cursor->type;
        }
        cursor = cursor->next;
    }
    yyerror("undeclared variable");
    return 1;
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
