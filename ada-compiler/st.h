#include "ast.h"

#ifndef __st_h__
#define __st_h__

struct _st_node {
    char* id;
    st_type type;
    struct _st_node* next;
};

typedef struct _st_node st_node;

void st_print(st_node* head);
st_node* st_insert(st_node* head, char* id, st_type type);
st_type st_search(st_node* head, char* id);
void st_build_stm(Stm* program, st_node** head);

char* st_type_to_string(st_type type);

#endif
