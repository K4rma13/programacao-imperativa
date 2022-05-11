#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "stack.h"
#include "array.h"
#include "handler.h"
#include <stdio.h>

int createBlock(STCK* stack, char* token);

int executeBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*));

int mapBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*));

int foldBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*));

#endif