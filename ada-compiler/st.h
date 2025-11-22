#include "ast.h"

#ifndef __st_h__
#define __st_h__

struct _st_node {
    char* id;
    char* type;
    struct _st_node* next;
};

typedef struct _st_node st_node;

void print_st(st_node* head);
st_node* st_insert(st_node* head, char* id, char* type);
char* st_search(st_node* head, char* id);
void st_build_stm(Stm* program, st_node* head);

#endif
