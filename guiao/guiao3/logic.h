#ifndef __LOGIC_H__

#define __LOGIC_H__

#include <stdio.h>
#include "stack.h"

#define OPERATION_PROTOO(_name)			\
	bool OP_##_name(DADOS b,DADOS a);	\


OPERATION_PROTOO(SMALL)

OPERATION_PROTOO(BIG)

OPERATION_PROTOO(EQUAL)

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