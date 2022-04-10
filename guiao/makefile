guiao1: guiao1.o math.o
	gcc -Wall -Wextra -pedantic-errors -O2 guiao1.o math.o -lm -o guiao1
guiao1.o: guiao1.c
	gcc guiao1.c -c
math.o: math.c math.h
	gcc math.c -c