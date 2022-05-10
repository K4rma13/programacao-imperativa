#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#define MAXSTACK 1000
typedef struct STCK{
	int val[MAXSTACK];
	int esp;
}STCK;

void printstack(STCK stack);

#endif