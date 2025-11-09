OBJS = scanner.o parser.o ast.o interpreter.o printASTv1.o printASTv2.o
INTERM = scanner.c parser.c parser.h
PROGRAM = ./interpreter
CC = gcc

all: $(PROGRAM)

parser.c parser.h: parser.bison
	bison --defines=parser.h -o parser.c parser.bison

scanner.c: scanner.flex parser.h
	flex -o scanner.c scanner.flex

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS)

clean:
	rm -f $(PROGRAM) $(OBJS) $(INTERM)

test: $(PROGRAM)
	$(PROGRAM) tests/input1.txt
	$(PROGRAM) tests/input2.txt
	$(PROGRAM) tests/input3.txt
	