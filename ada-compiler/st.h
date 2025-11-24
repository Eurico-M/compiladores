#include "ast.h"

#ifndef __st_h__
#define __st_h__

struct _st_node {
    char* id;
    enum {
        ST_INTEGER,
        ST_REAL
    } type;
    union {
        int integer_value;
        float real_value;
    } value;
    struct _st_node* next;
};

typedef struct _st_node st_node;

void st_print(st_node* head);
st_node* st_insert_integer(st_node* head, char* id, int value);
st_node* st_insert_real(st_node* head, char* id, float value);
char* st_search(st_node* head, char* id);
void st_build_stm(Stm* program, st_node* head);

#endif
