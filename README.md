
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
- assigment*
- if then else
- while
- procedure*
- function*

Expressões:
- aritméticas
- booleanas

### Notas:

#### Assignment:

Há dois tipos de assignment:
- o assignment no meio do código `x := x + 1`
- o assignment declarativo `x : Integer := 42`

O assignment no meio do código é um Statement, pode aparecer em qualquer parte do código.

O assignment declarativo só aparece na parte declarativa de um Procedure, entre `is` e `begin`:
```
procedure Main is
  x : Integer := 42
begin
  Put(x);
end Main;
```

Por isso, temos um novo tipo, Dclr, declarações, que pode ser vazio, ou uma lista, que aparece entre `is` e `begin` num Procedure.


### O que falta:

- a function é um comando (não devolve nada) porque o prof disse que era esse tipo que queríamos para a função Put, mas a função Get tem de devolver, por isso tem de ser uma expressão(?)
- estou a tratar as declarações iniciais (`with` e `use`) como se fossem comandos (statements) adicionais. se houver tempo (e não vai haver) podiamos pensar em criar um tipo de statement chamado header ou assim, e meter lá os withs e uses todos
