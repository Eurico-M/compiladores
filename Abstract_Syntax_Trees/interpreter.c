#include <stdio.h>
#include "parser.h"
#include "printAbsTree.h"

Expr* root = NULL;

int eval(Expr* expr) {
  int result = 0;
  if (expr == 0) {
    yyerror("Null expression!!");
  }
  else if (expr->kind == E_INTEGER) {
    result = expr->attr.value;
  }
  else if (expr->kind == E_OPERATION) {
    int vLeft = eval(expr->attr.op.left);
    int vRight = eval(expr->attr.op.right);
    switch (expr->attr.op.bin_operator) {
      case PLUS:
        result = vLeft + vRight;
        break;
      case MINUS:
        result = vLeft - vRight;
        break;
      case TIMES:
        result = vLeft * vRight;
        break;
      case DIV:
        result = vLeft / vRight;
        break;
      case MOD:
        result = vLeft % vRight;
        break;
      default: yyerror("Unknown operator!");
    }
  }
  return result;
}

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
      printExprParenthesis(root);
      printf("\n");
      printExpr(root, 0);
      printf("\n");
  }
  return 0;


}
