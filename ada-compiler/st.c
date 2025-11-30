#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "st.h"
#include "ast.h"
#include "parser.h"

st_node* st_head = NULL;

void st_init() {
    st_head = NULL;
}

char* st_type_to_string(st_type type) {
    switch (type) {
        case ST_INTEGER:
            return "Integer";
        case ST_REAL:
            return "Real";
    }
}

void st_print() {
    st_node* cursor = st_head;
    while (cursor != NULL) {
        printf("ID: %s, TYPE: %s\n", cursor->id, st_type_to_string(cursor->type));
        cursor = cursor->next;
    }
}

void st_insert(char* id, st_type type) {
    st_node* new_node = (st_node*) malloc(sizeof(st_node));
    new_node->id = strdup(id);
    new_node->type = type;
    new_node->next = st_head;
    st_head = new_node;
}

st_type st_search(char* id) {
    st_node* cursor = st_head;
    while (cursor != NULL) {
        if (strcmp(cursor->id, id) == 0) {
            return cursor->type;
        }
        cursor = cursor->next;
    }
    yyerror("undeclared variable");
    return 1;
}

void st_build_dclr(Dclr* dclr) {
    if (dclr->kind == DCLR_COMPOUND) {
        st_build_dclr(dclr->attr.dclr_compound.first);
        st_build_dclr(dclr->attr.dclr_compound.second);
    }
    else if (dclr->kind == DCLR_SIMPLE) {
        st_insert(dclr->attr.dclr_simple.id, dclr->attr.dclr_simple.type);
    }
    else if (dclr->kind == DCLR_ASSIGNMENT) {
        st_insert(dclr->attr.dclr_assignment.id, dclr->attr.dclr_assignment.type);
    }
}

void st_build_stm(Stm* program) {
    if (program->kind == STM_PROCEDURE) {
        st_build_dclr(program->attr.stm_proc.dclr);
        st_build_stm(program->attr.stm_proc.body);
    }
    else if (program->kind == STM_COMPOUND) {
        st_build_stm(program->attr.compound.first);
        st_build_stm(program->attr.compound.second);
    }
}
