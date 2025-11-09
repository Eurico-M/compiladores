
### Ficheiros criados/incluidos no Trabalho:

- Makefile - *macro para compilar os ficheiros todos na ordem correcta e ligar o que for necessário*
- scanner.flex - *tokens de leitura*
- parser.bison - *regras da gramática*
- ast.h - *definição das estruturas da Árvore Sintática Abstracta (AST)*
- ast.c - *implementação das funções definidas em ast.h*
- printASTv1.h / printASTv2.h - *declaração das funções (para outros ficheiros poderem importar as funções de impressão)*
- printASTv1.c / printASTv2.c - *funções para imprimir a AST*
- interpreter.c - *lê o input e imprime a AST*

### Para correr basta fazer:

`$ make`

`$ make tests`

ou individualmente,

`$ ./interpreter < tests/input1.txt`

### O que está incluido:

![ast viz](./ada-compiler/flowchart.png)

Comandos (statements):
- assigment
- if then else
- while
- procedure
- function
- with, use

Expressões:
- aritméticas
- booleanas
- strings

### Notas:

#### Assignment:

Há dois tipos de assignment:
- o assignment declarativo `x : Integer := 42`
- o assignment não declarativo (no meio do código) `x := x + 1`

O assignment não declarativo é um Statement, pode aparecer em qualquer parte do código.

O assignment declarativo só aparece na parte declarativa de um Procedure, entre `is` e `begin`, por exemplo:
```
procedure Main is
  x : Integer := 42
begin
  Put_Line(x);
end Main;
```

Por isso, temos um tipo, Dclr, declarações, que pode ser vazio, ou uma lista, que aparece entre `is` e `begin` num Procedure.


#### If Then Else:

O If Then Else foi implementado como o exemplo do slide 24 da aula teórica 6.

```
Stm -> if Exp then Stm
Stm -> if Exp then Stm else Stm
```

Ou seja, com a resolução shift do dangling else.


#### With, Use:

Para as funções Put_Line() e Get_Line() temos de incluir dois comandos, `with` e `use`.

Como estes comandos podem ter como argumento um package do tipo `Package1.Package2.Package3`, temos uma estrutura Pckg para construir os Packages com separador `.` (ponto). 


#### Function:

As duas funções a implementar (Put_Line() e Get_Line()) não precisam de devolver nada, por isso são Comandos e não Expressões.

A função Put_Line(argument) faz output do argument, e a função Get_Line(argument) recebe input para o argument.


#### Strings:

As strings são simplesmente mais uma expressão, que tem como atributo um simples char*.

Requer trabalho adicional no scanner.flex para remover as aspas. Isto porque o Flex não tem capture groups nas expressões regulares, senão podiamos fazer só `\"(.*)\"` e apanhar só o que está dentro de parentesis.

Ou seja, se o scanner ler `"isto é uma string"` deve guardar no yylval.string_val `isto é uma string`.

Para podermos fazer output de strings com o Put_Line().


#### Booleans:

(A implementação dos bools é temporária e não óptima)

O tipo bool pode aparecer sozinho, mas também em expressões do tipo `x = false` ou `y /= true`.

Como os ID estão definidos nas expressões aritméticas, a única forma de obter estas expressões é colocar o tipo bool nas expressões aritméticas.


## Referências Consultadas:

https://learn.adacore.com/courses/Ada_For_The_CPP_Java_Developer/chapters/04_Statements_Declarations_and_Control_Structures.html

https://ada-lang.io/docs/arm/AA-10/AA-10.1

https://ada-lang.io/docs/learn/overview/building-blocks
