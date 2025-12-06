#ifndef __ast_h__
#define __ast_h__


typedef struct _Pckg Pckg;
typedef struct _ArExpr ArExpr;
typedef struct _BoolExpr BoolExpr;
typedef struct _Expr Expr;
typedef struct _Dclr Dclr;
typedef struct _Stm Stm;
typedef struct _Cnd Cnd;


struct _Pckg {
    enum {
        PCKG_SIMPLE,
        PCKG_COMPOUND
    } kind;
    union {
        char* pckg_id;
        struct {
            Pckg* first;
            Pckg* second;
        } compound;
    } attr;
};


// Expressões Aritméticas

typedef enum {FALSE, TRUE} boolean;
typedef enum {PLUS, MINUS, TIMES, DIV, MOD} ar_op;
struct _ArExpr {
    enum {
        ID,
        INT,
        FLOAT,
        BOOLEAN,
        DELIMITED_AR_EXPR,
        AR_OP
    } kind;
    union {
        char* id;
        int int_val;
        float float_val;
        boolean boolean_ent;
        ArExpr* delimited_ar_expr;
        struct {
            ar_op op;
            ArExpr* left;
            ArExpr* right;
        } ar_op;
    } attr;
};

// Expressões Booleanas

typedef enum {EQUAL, DIFF, LESS, GREATER, LESS_EQUAL, GREATER_EQUAL, AND, OR, XOR, NOT} bool_op;
struct _BoolExpr {
    enum {
        // ID,
        DELIMITED_BOOL_EXPR,
        BOOL_AR_OP,
        BOOL_LG_OP
    } kind;
    union {
        // char* id;
        BoolExpr* delimited_bool_expr;
        struct {
            bool_op op;
            ArExpr* left;
            ArExpr* right;
        } bool_ar_op;
        struct {
            bool_op op;
            BoolExpr* left;
            BoolExpr* right;
        } bool_lg_op;
    } attr;
};


// Expressões

struct _Expr {
    enum {
        EXPR_ARITHMETIC,
        EXPR_BOOLEAN,
        EXPR_STRING
    } kind;
    union {
        ArExpr* ar_expr;
        BoolExpr* bool_expr;
        char* string_expr;
    } attr;
};


// Declarações

typedef enum {ST_INTEGER, ST_REAL} st_type;
struct _Dclr {
    enum {
        DCLR_COMPOUND,
        DCLR_SIMPLE,
        DCLR_ASSIGNMENT
    } kind;
    union {
        struct {
            Dclr* first;
            Dclr* second;
        } dclr_compound;
        struct {
            char* id;
            st_type type;
        } dclr_simple;          // x: Integer;
        struct {
            char* id;
            st_type type;
            Expr* expr;
        } dclr_assignment;      // x: Integer := 1+2;
    } attr;
};

// Condições
typedef enum {RL_EQ, RL_NE, RL_LT, RL_GT} rel_op;
struct _Cnd {
    enum {
        CND_RELOP
    } kind;
    union {
        struct {
            rel_op op;
            ArExpr* left;
            ArExpr* right;
        } cnd_relop;
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
            Stm* first;
            Stm* second;
        } compound;
        struct {
            char* ident;
            Expr* expr;
        } assign;
        struct {
            Cnd* condition;
            Stm* then_branch;
        } if_then;
        struct {
            Cnd* condition;
            Stm* then_branch;
            Stm* else_branch;
        } if_then_else;
        struct {
            Cnd* condition;
            Stm* body;
        } while_stm;
        Pckg* pckg_with;
        Pckg* pckg_use;
        struct {
            char* proc_id;
            Dclr* dclr;
            Stm* body;
        } stm_proc;
        struct {
            char* func_id;
            Expr* arg;
        } stm_func;
    } attr;
};



Pckg* pckg_simple(char* id);
Pckg* pckg_compound(Pckg* first, Pckg* second);

ArExpr* ar_expr_identifier(char* id);
ArExpr* ar_expr_integer(int int_val);
ArExpr* ar_expr_float(float float_val);
ArExpr* ar_expr_delimited(ArExpr* delimited_ar_expr);
ArExpr* ar_expr_operation(ar_op op, ArExpr* left, ArExpr* right);
ArExpr* ar_expr_boolean(boolean boolean_ent);

BoolExpr* bool_expr_delimited (BoolExpr* delimited_bool_expr);
BoolExpr* bool_expr_operation(bool_op op, ArExpr* left, ArExpr* right);
BoolExpr* bool_expr_operation2(bool_op op, BoolExpr* left, BoolExpr* right);

Expr* expr_arithmetic(ArExpr* ar_expr);
Expr* expr_boolean(BoolExpr* bool_expr);
Expr* expr_string(char* string_expr);

Dclr* dclr_compound(Dclr* first, Dclr* second);
Dclr* dclr_simple(char* id, char* type);
Dclr* dclr_assignment(char* id, char* type, Expr* expr);

Stm* stm_compound(Stm* first, Stm* second);
Stm* stm_assign(char* ident, Expr* expr);
Stm* stm_if_then(Cnd* condition, Stm* then_branch);
Stm* stm_if_then_else(Cnd* condition, Stm* then_branch, Stm* else_branch);
Stm* stm_while(Cnd* condition, Stm* body);
Stm* stm_with(Pckg* pckg_with);
Stm* stm_use(Pckg* pckg_use);
Stm* stm_procedure(char* proc_id, Dclr* dclr, Stm* body);
Stm* stm_function(char* func_id, Expr* arg);

Cnd* cnd_relop(rel_op op, ArExpr* left, ArExpr* right);

#endif
