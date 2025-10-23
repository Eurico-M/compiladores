

calc : parser.y lexer.l main.c
	bison -d parser.y
	flex lexer.l
	gcc -o calc parser.tab.c lex.yy.c main.c -lm
