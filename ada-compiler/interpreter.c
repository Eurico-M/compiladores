#include <stdio.h>
#include "parser.h"
#include "printAbsTree.h"

Stm* program = NULL;


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

    printStm(program);
    printf("\n");

    return 0;
}
