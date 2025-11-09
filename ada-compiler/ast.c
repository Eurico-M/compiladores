
#include <stdlib.h>
#include "ast.h"

// Statements

Stm* stm_compound(Stm* first, Stm* second) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_COMPOUND;
    node->attr.compound.first = first;
    node->attr.compound.second = second;
    return node;
}

Stm* stm_assign(char* ident, Expr* expr) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_ASSIGNMENT;
    node->attr.assign.ident = ident;
    node->attr.assign.expr = expr;
    return node;
}

Stm* stm_if_then(Expr* condition, Stm* then_branch) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_IF_THEN;
    node->attr.if_then.condition = condition;
    node->attr.if_then.then_branch = then_branch;
}

Stm* stm_if_then_else(Expr* condition, Stm* then_branch, Stm* else_branch) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_IF_THEN_ELSE;
    node->attr.if_then_else.condition = condition;
    node->attr.if_then_else.then_branch = then_branch;
    node->attr.if_then_else.else_branch = else_branch;
    return node;
}

Stm* stm_while(Expr* condition, Stm* body) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_WHILE;
    node->attr.while_stm.condition = condition;
    node->attr.while_stm.body = body;
    return node;
}

Stm* stm_with(Pckg* pckg_with) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_WITH;
    node->attr.pckg_with = pckg_with;
    return node;
}

Stm* stm_use(Pckg* pckg_use) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_USE;
    node->attr.pckg_use = pckg_use;
    return node;
}

Stm* stm_procedure(char* proc_id, Dclr* dclr, Stm* body) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_PROCEDURE;
    node->attr.stm_proc.proc_id = proc_id;
    node->attr.stm_proc.dclr = dclr;
    node->attr.stm_proc.body = body;
    return node;
}

Stm* stm_function(char* func_id, Expr* arg) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_FUNCTION;
    node->attr.stm_func.func_id = func_id;
    node->attr.stm_func.arg = arg;
    return node;
}

// Expressions

Expr* expr_arithmetic(ArExpr* ar_expr) {
    Expr* node = (Expr*) malloc(sizeof(Expr));
    node->kind = EXPR_ARITHMETIC;
    node->attr.ar_expr = ar_expr;
    return node;
}

Expr* expr_logic(LogExpr* log_expr) {
    Expr* node = (Expr*) malloc(sizeof(Expr));
    node->kind = EXPR_LOGIC;
    node->attr.log_expr = log_expr;
    return node;
}

Expr* expr_string(char* string_expr) {
    Expr* node = (Expr*) malloc(sizeof(Expr));
    node->kind = EXPR_STRING;
    node->attr.string_expr = string_expr;
    return node;
}

// Arithmetic Expressions

ArExpr* ar_expr_identifier(char* id) {
    ArExpr* node = (ArExpr*) malloc(sizeof(ArExpr));
    node->tag = ID;
    node->attr.id = id;
    return node;
}

ArExpr* ar_expr_integer(int int_val) {
    ArExpr* node = (ArExpr*) malloc(sizeof(ArExpr));
    node->tag = INT;
    node->attr.int_val = int_val;
    return node;
}

ArExpr* ar_expr_float(float float_val) {
    ArExpr* node = (ArExpr*) malloc(sizeof(ArExpr));
    node->tag = FLOAT;
    node->attr.float_val = float_val;
    return node;
}

ArExpr* ar_expr_operation(ar_op op, ArExpr* left, ArExpr* right) {
    ArExpr* node = (ArExpr*) malloc(sizeof(ArExpr));
    node->tag = AR_OP;
    node->attr.ar_op.op = op;
    node->attr.ar_op.left = left;
    node->attr.ar_op.right = right;
    return node;
}

// Boolean Expressions

BoolExpr* bool_expr_operation(bool_op op, ArExpr* left, ArExpr* right) {
    BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
    node->tag = BOOL_OP;
    node->attr.bool_op.op = op;
    node->attr.bool_op.left = left;
    node->attr.bool_op.right = right;
    return node;
}

// Logic Expressions

LogExpr* log_bool(BoolExpr* boolExpr) {
    LogExpr* node = (LogExpr*) malloc(sizeof(LogExpr));
    node->tag = LOG_BOOL;
    node->attr.boolExpr = boolExpr;
    return node;
}

LogExpr* log_operation(log_op op, LogExpr* left, LogExpr* right) {
    LogExpr* node = (LogExpr*) malloc(sizeof(LogExpr));
    node->tag = LOG_OP;
    node->attr.op_log.op = op;
    node->attr.op_log.left = left;
    node->attr.op_log.right = right;
    return node;
}

LogExpr* log_unary(log_un op, LogExpr* unary) {
    LogExpr* node = (LogExpr*) malloc(sizeof(LogExpr));
    node->tag = LOG_UNARY;
    node->attr.unary_op.op = op;
    node->attr.unary_op.unary = unary;
    return node;
}

// Declarations

Dclr* dclr_compound(Dclr* first, Dclr* second) {
    Dclr* node = (Dclr*) malloc(sizeof(Dclr));
    node->kind = DCLR_COMPOUND;
    node->attr.dclr_compound.first = first;
    node->attr.dclr_compound.second = second;
    return node;
}

Dclr* dclr_simple(char* id, char* type) {
    Dclr* node = (Dclr*) malloc(sizeof(Dclr));
    node->kind = DCLR_SIMPLE;
    node->attr.dclr_simple.id = id;
    node->attr.dclr_simple.type = type;
    return node;
}

Dclr* dclr_assignment(char* id, char* type, Expr* expr) {
    Dclr* node = (Dclr*) malloc(sizeof(Dclr));
    node->kind = DCLR_ASSIGNMENT;
    node->attr.dclr_assignment.id = id;
    node->attr.dclr_assignment.type = type;
    node->attr.dclr_assignment.expr = expr;
    return node;
}

// Packages

Pckg* pckg_simple(char* id) {
    Pckg* node = (Pckg*) malloc(sizeof(Pckg));
    node->kind = PCKG_SIMPLE;
    node->attr.pckg_id = id;
    return node;
}

Pckg* pckg_compound(Pckg* first, Pckg* second) {
    Pckg* node = (Pckg*) malloc(sizeof(Pckg));
    node->kind = PCKG_COMPOUND;
    node->attr.compound.first = first;
    node->attr.compound.second = second;
    return node;
}
