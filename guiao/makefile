guiao1: guiao1.o mat.o stack.o
	gcc -ggdb -Wall -Wextra -pedantic-errors -O2 guiao1.o mat.o stack.o -lm -o guiao1
guiao1.o: code/guiao1.c
	gcc code/guiao1.c -c -o guiao1.o
mat.o: code/mat.c code/mat.h
	gcc code/mat.c -c -o mat.o
stack.o: code/stack.c code/stack.h
	gcc code/stack.c -c -o stack.o