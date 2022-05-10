guiao: guiao.o mat.o stack.o logic.o variables.o array.o handler.o block.o
	gcc -ggdb -Wall -Wextra -pedantic-errors -O2 guiao.o mat.o stack.o logic.o variables.o array.o handler.o block.o -lm -o guiao
guiao.o: code/guiao.c
	gcc code/guiao.c -c -o guiao.o
mat.o: code/mat.c code/mat.h
	gcc code/mat.c -c -o mat.o
logic.o: code/logic.c code/logic.h
	gcc code/logic.c -c -o logic.o
variables.o: code/variables.c code/variables.h
	gcc code/variables.c -c -o variables.o
stack.o: code/stack.c code/stack.h
	gcc code/stack.c -c -o stack.o
array.o: code/array.c code/array.h
	gcc code/array.c -c -o array.o
handler.o: code/handler.c code/handler.h
	gcc code/handler.c -c -o handler.o
block.o: code/block.c code/block.h
	gcc code/block.c -c -o block.o