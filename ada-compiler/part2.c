#include <stdio.h>
#include "parser.h"
#include "st.h"

Stm* program = NULL;
st_node* st_head = NULL;



int main() {

    int result = yyparse();

    if (result != 0) {
        printf("parser failed\n");
        return 1;
    }

    if (program == NULL) {
        printf("program NULL after parse\n");
        return 1;
    }

    print_st(st_head);

    return 0;
}
