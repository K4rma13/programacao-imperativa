#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


#define MAXSTACK 1000


typedef enum{CHR = 0, LNG = 1, STR=2, DOUBLE=3}TYPE;

typedef struct DADOS{
	TYPE type;
	char CHR;
	char* STR;
	long int LNG;
	double DOUBLE;
}DADOS;

typedef struct STCK{
	DADOS val[MAXSTACK];
	int esp;
}STCK;

#define PROTO_FSTACK(_name,_type)					\
	void push_##_name(STCK* stack, _type value);	\
	_type pop_##_name(STCK* stack);					\

PROTO_FSTACK(LNG,long int)
PROTO_FSTACK(CHR,char)
PROTO_FSTACK(STR,char*)
PROTO_FSTACK(DOUBLE,double)

bool hastype(DADOS dado, TYPE tipo);

int lestring(STCK* stack, char* token);

void printstack(STCK stack);

bool isdecimal(char* token);

int valor(STCK* stack, char* token);

int valor_Double(STCK* stack, char* token);

int toLNG(STCK* stack, char* token);

int toDouble(STCK* stack, char* token);

int cpyStack(STCK* stack, char* token);

int longToCHR(STCK* stack, char* token);

int rodar(STCK* stack, char* token);

int trocar(STCK* stack, char* token);

int duplicar(STCK* stack, char* token);

int removeTop(STCK* stack, char* token);

#endif