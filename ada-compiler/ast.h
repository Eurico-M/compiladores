
#ifndef __ast_h__
#define __ast_h__

// Expressões Aritméticas

typedef enum {PLUS, MINUS, TIMES, DIV, MOD} ar_op;
struct _ArExpr {
    enum {
        ID,
        INT,
        FLOAT,
        AR_OP
    } tag;
    union {
        char* id;
        int int_val;
        float float_val;
        struct {
            ar_op op;
            struct _ArExpr* left;
            struct _ArExpr* right;
        } ar_op;
    } attr;
};

// Expressões Booleanas

typedef enum {EQUAL, DIFF, LESS, GREATER, LESS_EQUAL, GREATER_EQUAL} bool_op;
struct _BoolExpr {
    enum {
        // ID,
        // BOOL,
        BOOL_OP
    } tag;
    union {
        // char* id;
        // bool boolean;
        struct {
            bool_op op;
            struct _ArExpr* left;
            struct _ArExpr* right;
        } bool_op;
    } attr;
};

// Statements

struct _Stm {
    enum {
        STM_COMPOUND,
        STM_ASSIGNMENT,
        STM_IF_THEN,
        STM_IF_THEN_ELSE,
        STM_WHILE,
        STM_WITH,
        STM_USE,
        STM_PROCEDURE,
        STM_FUNCTION
    } kind;
    union {
        struct {
            struct _Stm* first;
            struct _Stm* second;
        } compound;
        struct {
            char* ident;
            struct _Expr* expr;
        } assign;
        struct {
            struct _Expr* condition;
            struct _Stm* then_branch;
        } if_then;
        struct {
            struct _Expr* condition;
            struct _Stm* then_branch;
            struct _Stm* else_branch;
        } if_then_else;
        struct {
            struct _Expr* condition;
            struct _Stm* body;
        } while_stm;
        char* with_id;
        char* use_id;
        struct {
            char* proc_id;
            struct _Dclr* dclr;
            struct _Stm* body;
        } stm_proc;
        struct {
            char* func_id;
            struct _Expr* arg;
        } stm_func;
    } attr;
};

// Declarações

struct _Dclr {
    enum {
        DCLR_COMPOUND,
        DCLR_SIMPLE,
        DCLR_ASSIGNMENT
    } kind;
    union {
        struct {
            struct _Dclr* first;
            struct _Dclr* second;
        } dclr_compound;
        struct {
            char* id;
            char* type;
        } dclr_simple;
        struct {
            char* id;
            char* type;
            struct _Expr* expr;
        } dclr_assignment;
    } attr;
};

// Expressões

struct _Expr {
    enum {
        EXPR_ARITHMETIC,
        EXPR_BOOLEAN,
        // EXPR_FUNCTION,
        // EXPR_VARIABLE
    } kind;
    union {
        struct _ArExpr* ar_expr;
        struct _BoolExpr* bool_expr;
        // struct {
        //     char* func_name;
        //     _Expr* arg;
        // } func_expr;
        // char* var_name;
    } attr;
};


typedef struct _Stm Stm;
typedef struct _Expr Expr;
typedef struct _ArExpr ArExpr;
typedef struct _BoolExpr BoolExpr;
typedef struct _Dclr Dclr;


Stm* stm_compound(Stm* first, Stm* second);
Stm* stm_assign(char* ident, Expr* expr);
Stm* stm_if_then(Expr* condition, Stm* then_branch);
Stm* stm_if_then_else(Expr* condition, Stm* then_branch, Stm* else_branch);
Stm* stm_while(Expr* condition, Stm* body);
Stm* stm_with(char* with_id);
Stm* stm_use(char* use_id);
Stm* stm_procedure(char* proc_id, Dclr* dclr, Stm* body);
Stm* stm_function(char* func_id, Expr* arg);

Expr* expr_arithmetic(ArExpr* ar_expr);
Expr* expr_boolean(BoolExpr* bool_expr);
// Expr* expr_function(char* func_name, Expr* arg);
// Expr* expr_variable(char* var_name);

ArExpr* ar_expr_identifier(char* id);
ArExpr* ar_expr_integer(int int_val);
ArExpr* ar_expr_float(float float_val);
ArExpr* ar_expr_operation(ar_op op, ArExpr* left, ArExpr* right);

// BoolExpr* bool_expr_identifier(char* id);
// BoolExpr* bool_expr_bool(bool boolean);
BoolExpr* bool_expr_operation(bool_op op, ArExpr* left, ArExpr* right);

Dclr* dclr_compound(Dclr* first, Dclr* second);
Dclr* dclr_simple(char* id, char* type);
Dclr* dclr_assignment(char* id, char* type, Expr* expr);


#endif
