#include "ast.h"

#ifndef __ST_H__
#define __ST_H__

struct _st_node {
    char* id;
    st_type type;
    struct _st_node* next;
};

typedef struct _st_node st_node;

void st_init();
void st_print();
void st_insert(char* id, st_type type);
st_type st_search(char* id);
void st_build_stm(Stm* program);

char* st_type_to_string(st_type type);

extern st_node* st_head;

#endif
