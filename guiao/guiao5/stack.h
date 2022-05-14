/**
 *@file Biblioteca que contem as funcoes da stack(stack.c)
 */
#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>




typedef enum{CHR = 0, LNG = 1, DOUBLE=3, ARR=4, BLK=6}TYPE;

typedef struct DADOS{
	TYPE type;
	char CHR;
	long int LNG;
	double DOUBLE;
	struct ARR{
		struct DADOS *array;
		int size;
		int all_size;
	}ARR;
}DADOS;

typedef struct ARR typearray;

typedef struct STCK{
	DADOS* val;
	int esp;
}STCK;

#define PROTO_FSTACK(_name,_type)					\
	void push_##_name(STCK* stack, _type value);	\
	_type pop_##_name(STCK* stack);					\

PROTO_FSTACK(LNG,long int)
PROTO_FSTACK(CHR,char)
PROTO_FSTACK(DOUBLE,double)

void printArr(struct ARR stack);

bool hastype(DADOS dado, TYPE tipo);

int lestring(STCK* stack, char* token);

void printstack(STCK* stack);

bool isdecimal(char* token);

int valor(STCK* stack, char* token);

int valor_Double(STCK* stack, char* token);

struct ARR copyArr(struct ARR arr);

int toLNG(STCK* stack, char* token);

int toDouble(STCK* stack, char* token);

int cpyStack(STCK* stack, char* token);

int toCHR(STCK* stack, char* token);

int rodar(STCK* stack, char* token);

int trocar(STCK* stack, char* token);

int duplicar(STCK* stack, char* token);

int removeTop(STCK* stack, char* token);

int initArr(STCK* stack, char* token);

int closeArr(STCK* stack, char* token);

int printTopo(STCK* stack, char* token);

int toString(STCK* stack, char* token);

#endif