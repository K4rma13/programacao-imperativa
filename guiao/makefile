guiao1: guiao1.o mat.o stack.o logic.o variables.o
	gcc -ggdb -Wall -Wextra -pedantic-errors -O2 guiao1.o mat.o stack.o logic.o variables.o -lm -o guiao1
guiao1.o: code/guiao1.c
	gcc code/guiao1.c -c -o guiao1.o
mat.o: code/mat.c code/mat.h
	gcc code/mat.c -c -o mat.o
logic.o: code/logic.c code/logic.h
	gcc code/logic.c -c -o logic.o
variables.o: code/variables.c code/variables.h
	gcc code/variables.c -c -o variables.o
stack.o: code/stack.c code/stack.h
	gcc code/stack.c -c -o stack.o