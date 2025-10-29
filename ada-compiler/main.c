
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include "parser.tab.h"

struct _stm {
    enum
        {COMPOUND, ASSIGN, INCR} tag;
    union {
        struct { // for COMPOUND
            struct _stm *fst, *snd;
        } compound;
        struct { // for ASSIGN
            char *ident;
            struct _exp *expr;
        } assign;
        char *ident; // for INCR
    };
};
typedef struct _stm *Stm;

typedef enum {PLUS, MINUS, TIMES, DIV} binop;
struct _exp {
    enum {ID, NUM, OP} tag;
    union {
        int val; // for NUM
        char *id; // for ID
        struct { // for OP
            binop op;
            struct _exp *left, *right;
        } binop;
    };
};
typedef struct _exp *Exp;

Exp mk_num(int v) {
    Exp e = (Exp) malloc(sizeof(struct _exp));
    e->tag = NUM;
    e->val = v;
    return e;
}

Exp mk_ident(char *txt) {
    Exp e = (Exp)malloc(sizeof(struct _exp));
    char *str = malloc(strlen(txt)+1);
    strcpy(str, txt); // é preferível ‘‘clonar’’ a cadeia
    e->tag = ID;
    e->id = str;
    return e;
}

Exp mk_op(binop op, Exp e1, Exp e2) {
    Exp e = (Exp) malloc(sizeof(struct _exp));
    e->tag = OP;
    e->binop.op = op;
    e->binop.left = e1;
    e->binop.right = e2;
    return e;
}

int main(void) {
  yyparse();
}
