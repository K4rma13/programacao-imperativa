#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "stack.h"
#include <stdio.h>

int enumerate(STCK* stack, char* token);

int lastArray(STCK* stack, char* token);

int initArr(STCK* stack, char* token);

int closeArr(STCK* stack, char* token);

int initString(STCK* stack, char* token);

int indexArr(STCK* stack, char* token);

#endif