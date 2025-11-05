// AST constructor functions

#include <stdlib.h> // for malloc
#include "ast.h" // AST header

Expr* ast_integer(int v) {
  Expr* node = (Expr*) malloc(sizeof(Expr));
  node->kind = E_INTEGER;
  node->attr.value = v;
  return node;
}

Expr* ast_operation
(int bin_operator, Expr* left, Expr* right) {
  Expr* node = (Expr*) malloc(sizeof(Expr));
  node->kind = E_OPERATION;
  node->attr.op.bin_operator = bin_operator;
  node->attr.op.left = left;
  node->attr.op.right = right;
  return node;
}

BoolExpr* ast_bool_integer(int v) {
    BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
    node->kind = E_BOOL_INTEGER;
    if ( v == 0) {
        node->attr.bool_value = 0;
    } else {
        node->attr.bool_value = 1;
    }
    return node;
}

BoolExpr* ast_bool_operation
(int rel_operator, Expr* left, Expr* right) {
    BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
    node->kind = E_BOOL_OPERATION;
    node->attr.relop.rel_operator = rel_operator;
    node->attr.relop.left = left;
    node->attr.relop.right = right;
    return node;
}
