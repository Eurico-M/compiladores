#include <stdio.h>
#include "parser.h"
#include "printAbsTree.h"




int main(int argc, char** argv) {
  --argc; ++argv;
  if (argc != 0) {
    yyin = fopen(*argv, "r");
    if (!yyin) {
      printf("'%s': could not open file\n", *argv);
      return 1;
    }
  } //  yyin = stdin
  if (yyparse() == 0) {
      //printf("Result = %d\n", eval(root));
      printExprParenthesis(program);
      printf("\n");
      //printExpr(root, 0);
      //printf("\n");
  }
  return 0;


}
