#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "stack.h"
#include "array.h"
#include "mat.h"
#include "logic.h"
#include "variables.h"
#include "block.h"
#include <stdio.h>

void parser(char* buf,STCK* stack,DADOS* v,int (*functions[])(STCK*,char*));

int handlerBlock(STCK* stack, char* token, DADOS* v,int (*functions[])(STCK*,char*));

int handlerLetras(STCK* stack, char* token, DADOS* v);

int handlerValores(STCK* stack, char* token);

void handler(STCK* stack, char* token, DADOS* v,int (*functions[])(STCK*,char*));

int til(STCK* stack, char* token);

int parOpen(STCK* stack, char* token);

int parClose(STCK* stack, char* token);

int asterisco(STCK* stack, char* token);

int slash(STCK* stack, char* token);

int plus(STCK* stack, char* token);

int hastag(STCK* stack, char* token);

int equal(STCK* stack, char* token);

int lessSign(STCK* stack, char* token);

int lessSign(STCK* stack, char* token);

int greaterSign(STCK* stack, char* token);

#endif