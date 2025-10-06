#ifndef TOKENS_H
#define TOKENS_H

typedef enum {
    LBRACE = 256,  // Start above ASCII range
    RBRACE,
    SEMICOLON,
    LPAREN,
    RPAREN,
    COMMA,
    IF,
    WHILE,
    FOR,
    INT,
    FLOAT,
    ID,
    NUM,
    REAL,
    TOK_EOF  // Use TOK_EOF to avoid conflict with stdio.h's EOF
} token_t;


#endif
