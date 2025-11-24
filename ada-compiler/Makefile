OBJS = scanner.o parser.o ast.o printAbsTree.o printASTv2.o st.o interpreter.o
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
	$(PROGRAM) example1.txt
	$(PROGRAM) example2.txt
	$(PROGRAM) example3.txt
	$(PROGRAM) example4.txt
