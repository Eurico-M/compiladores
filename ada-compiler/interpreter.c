#include <stdio.h>
#include "parser.h"
#include "printASTv1.h"
#include "printASTv2.h"
#include "st.h"

Stm* program = NULL;
long tabs = 0;

int main(int argc, char** argv) {
    --argc; ++argv;
    if (argc != 0) {
        yyin = fopen(*argv, "r");
        if (!yyin) {
            printf("'%s': could not open file\n", *argv);
            return 1;
        }
    } //  yyin = stdin

    int result = yyparse();

    if (result != 0) {
        printf("parser failed\n");
        return 1;
    }

    if (program == NULL) {
        printf("program NULL after parse\n");
        return 1;
    }

    printf("\n");
    printf("+ Abstract Syntax Tree v1 +\n\n");
    printStm(program);
    printf("\n\n\n");
    printf("+ Abstract Syntax Tree v2 +\n\n");
    printStm_v2(program, tabs);
    printf("\n");

    st_build_stm(program);
    if (st_head == NULL) {
        printf("st_build failed\n");
    }
    printf("Symbol Table:\n");
    st_print();

    return 0;
}
