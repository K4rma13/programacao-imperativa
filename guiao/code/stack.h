#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTACK 1000
#define MAXSTRSIZE 999

typedef struct DATA{
	int type;
	char str[MAXSTRSIZE];
	char c;
	long int i;
	double f;
}DATA;

typedef struct STCK{
	DATA val[MAXSTACK];
	int esp;
}STCK;


int valor(STCK* stack, char* token);

void printstack(STCK stack);

#endif