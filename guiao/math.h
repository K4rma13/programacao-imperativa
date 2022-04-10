#ifndef MATH_H
#define MATH_H

#define MAXSTACK 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct STCK{
	int val[MAXSTACK];
	int esp;
}STCK;

int potencia(STCK* stack, char* token);

int add(STCK* stack, char* token);

int sub(STCK* stack, char* token);

int divisao(STCK* stack, char* token);

int mul(STCK* stack, char* token);

int incr(STCK* stack, char* token);

int decr(STCK* stack, char* token);

int module(STCK* stack, char* token);

int and(STCK* stack, char* token);

int or(STCK* stack, char* token);

int xor(STCK* stack, char* token);

int not(STCK* stack, char* token);

#endif