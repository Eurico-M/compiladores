#ifndef PRINT_AST_V2_H
#define PRINT_AST_V2_H

void printArExpr_v2(ArExpr* arExpr, long tabs);
void printBoolExpr_v2(BoolExpr* boolExpr, long tabs);
void printExpr_v2(Expr* expr, long tabs);
void printStm_v2(Stm* stm, long tabs);

#endif
