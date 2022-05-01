#include "variables.h"
/*
A Valor por omissão: 10
B Valor por omissão: 11
C Valor por omissão: 12
D Valor por omissão: 13
E Valor por omissão: 14
F Valor por omissão: 15
N Valor por omissão: '\n'
S Valor por omissão: ' '
X Valor por omissão: 0
Y Valor por omissão: 1
Z Valor por omissão: 2
*/


int variablePush(STCK* stack, char* token, DADOS* v){
	if(token[0] >= 'A' && token[0] <= 'Z'){
		stack->esp++;
		stack->val[stack->esp] = v[token[0]-65];
		return 1;
	}
	return 0;
}

int variableGet(STCK* stack, char* token, DADOS* v){
	if(token[0] == ':'){
		v[token[1]-65]=stack->val[stack->esp];
		return 1;
	}
	return 0;
}