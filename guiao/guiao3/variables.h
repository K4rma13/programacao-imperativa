#ifndef __VARIABLES_H__
#define __VARIABLES_H__

#include "stack.h"
#include <stdio.h>

int variablePush(STCK* stack, char* token, DADOS* v);

int variableGet(STCK* stack, char* token, DADOS* v);

#endif