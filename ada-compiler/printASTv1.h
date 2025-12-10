#include "ast.h"

#ifndef PRINT_AST_V1_H
#define PRINT_AST_V1_H

void printArExpr(ArExpr* arExpr);
void printBoolExpr(BoolExpr* boolExpr);
void printExpr(Expr* expr);
void printDclr(Dclr* dclr);
void printPckg(Pckg* pckg);
void printStm(Stm* stm);

#endif
