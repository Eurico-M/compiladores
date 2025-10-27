

adac: lexer.l parser.y main.c
	bison -d parser.y
	flex lexer.l
	gcc -o adac parser.tab.c lex.yy.c main.c -lm
