/**
 *@file Biblioteca que contem as funcoes logicas(logic.c)
 */
#ifndef __LOGIC_H__

#define __LOGIC_H__

#include "array.h"
#include <stdio.h>
#include "stack.h"

#define OPERATION_PROTOO(_name)			\
	bool OP_##_name(DADOS b,DADOS a);	\


OPERATION_PROTOO(SMALL)

OPERATION_PROTOO(BIG)

OPERATION_PROTOO(EQUAL)

bool OP_FALSE(DADOS a);

int grStr(STCK* stack);

int lStr(STCK* stack);

int isFalse(STCK* stack, char* token);

int isEqual(STCK* stack, char* token);

int isSmall(STCK* stack, char* token);

int isBig(STCK* stack,char* token);

int ifThenElse(STCK* stack,char* token);

int logicalAnd(STCK* stack, char* token);

int logicalOr(STCK* stack, char* token);

int logicalGreater(STCK* stack, char* token);

int logicalLess(STCK* stack, char* token);

#endif