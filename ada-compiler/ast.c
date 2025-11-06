
#include <stdlib.h>
#include "ast.h"

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

Stm* stm_if(Expr* condition, Stm* then_branch, Stm* else_branch) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_IF;
    node->attr.if_stm.condition = condition;
    node->attr.if_stm.then_branch = then_branch;
    node->attr.if_stm.else_branch = else_branch;
    return node;
}

Stm* stm_while(Expr* condition, Stm* body) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_WHILE;
    node->attr.while_stm.condition = condition;
    node->attr.while_stm.body = body;
    return node;
}

Stm* stm_with(char* with_id) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_WITH;
    node->attr.with_id = with_id;
    return node;
}

Stm* stm_use(char* use_id) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_USE;
    node->attr.use_id = use_id;
    return node;
}

Stm* stm_procedure(char* proc_id, Stm* body) {
    Stm* node = (Stm*) malloc(sizeof(Stm));
    node->kind = STM_PROCEDURE;
    node->attr.stm_proc.proc_id = proc_id;
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




Expr* expr_arithmetic(ArExpr* ar_expr) {
    Expr* node = (Expr*) malloc(sizeof(Expr));
    node->kind = EXPR_ARITHMETIC;
    node->attr.ar_expr = ar_expr;
    return node;
}

Expr* expr_boolean(BoolExpr* bool_expr) {
    Expr* node = (Expr*) malloc(sizeof(Expr));
    node->kind = EXPR_BOOLEAN;
    node->attr.bool_expr = bool_expr;
    return node;
}

// Expr* expr_function(char* func_name, Expr* arg) {
//     Expr* node = (Expr*) malloc(sizeof(Expr));
//     node->kind = EXPR_FUNCTION;
//     node->attr.func_expr.func_name = func_name;
//     node->attr.func_expr.arg = arg;
//     return node;
// }

// Expr* expr_variable(char* var_name) {
//     Expr* node = (Expr*) malloc(sizeof(Expr));
//     node->kind = EXPR_VARIABLE;
//     node->attr.var_name = var_name;
//     return node;
// }

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

// BoolExpr* bool_expr_identifier(char* id) {
//     BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
//     node->tag = ID;
//     node->attr.id = id;
//     return node;
// }

// BoolExpr* bool_expr_bool(bool boolean) {
//     BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
//     node->tag = BOOL;
//     node->attr.boolean = boolean;
//     return node;
// }

BoolExpr* bool_expr_operation(bool_op op, ArExpr* left, ArExpr* right) {
    BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
    node->tag = BOOL_OP;
    node->attr.bool_op.op = op;
    node->attr.bool_op.left = left;
    node->attr.bool_op.right = right;
    return node;
}
