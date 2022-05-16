#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "stack.h"
#include <stdio.h>
#include <string.h>

int arrMUL(STCK* stack);

int arrADD(STCK* stack);

void concatArray( typearray* array1, typearray array2);

int enumerate(STCK* stack, char* token);

int lastArray(STCK* stack, char* token);

int firstArray(STCK* stack, char* token);

int initArr(STCK* stack, char* token);

int closeArr(STCK* stack, char* token);

int initString(STCK* stack, char* token);

int indexArr(STCK* stack, char* token);

int arrayToStack(STCK* stack, char* token);

int rmLastArr(STCK* stack, char* token);

int rmFirstArr(STCK* stack, char* token);

int findArr(STCK* stack, char* token);

int inputToStr(STCK* stack, char* token);

int splitStr(STCK* stack, char* token);

int splitSpace(STCK* stack, char* token);

int cmpString(STCK* stack);

int greaterString(STCK* stack);

int lesserString(STCK* stack);

int everythingToStr(STCK* stack, char* token);

int splitNL(STCK* stack, char* token);

void cpyDados(DADOS *a, DADOS *b, int n);

#endif