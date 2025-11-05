
### Para o Trabalho Prático, usar a pasta ada-compiler.

Em ada-compiler, os ficheiros a editar são:

- scanner.flex - *tokens de leitura*

- parser.bison - *regras da gramática*
- ast.h - *definição das estruturas da Árvore Sintática Abstracta (AST)*
- ast.c - *implementação das funções definidas em ast.h*
- printAbsTree.c - *funções para imprimir a AST*
- printAbsTree.h - *declaração das funções (para outros ficheiros poderem importar as funções de impressão)*

- interpreter.c - *lê o input e imprime a AST*

- Makefile - *macro para compilar os ficheiros todos na ordem correcta e ligar o que for preciso*

### Para correr isto, é só:

`$ make`

`$ ./interpreter < test_input.txt`

### O que está feito:

Comandos:
- assigment
- if then else
- while
- procedure*
- function*

Expressões:
- aritméticas*

### O que falta:

- boolean expressions
- o procedure só aceita coisas do tipo
```
procedure Main is
begin
--code;
end Main;
```
ou seja, sem as declarações entre `is` e `begin`.
- a function é um comando (não devolve nada) porque o prof disse que era esse tipo que queríamos para a função Put, mas a função Get tem de devolver, por isso tem de ser uma expressão(?)
- as expressões aritméticas só aceitam INT
- estou a tratar as declarações iniciais (`with` e `use`) como se fossem comandos (statements) normais.

