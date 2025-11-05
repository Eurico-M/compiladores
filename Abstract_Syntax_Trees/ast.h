
// AST definitions
#ifndef __ast_h__
#define __ast_h__

// AST for expressions
struct _Expr {
  enum {
    E_INTEGER,
    E_OPERATION
  } kind;
  union {
    int value; // for integer values
    struct {
      int bin_operator; // PLUS, MINUS, etc
      struct _Expr* left;
      struct _Expr* right;
    } op; // for binary expressions
  } attr;
};

// Boolean Expressions datatype
struct _BoolExpr {
    enum {
        E_BOOL_INTEGER,
        E_BOOL_OPERATION
    } kind;
    union {
        int bool_value;
        struct {
            int rel_operator;
            struct _Expr* left;
            struct _Expr* right;
        } relop;
    } attr;
};

typedef struct _Expr Expr; // Convenience typedef
typedef struct _BoolExpr BoolExpr;

// Constructor functions (see implementation in ast.c)
Expr* ast_integer(int v);
Expr* ast_operation(int bin_operator, Expr* left, Expr* right);

BoolExpr* ast_bool_integer(int v);
BoolExpr* ast_bool_operation(int rel_operator, Expr* left, Expr* right);

#endif
