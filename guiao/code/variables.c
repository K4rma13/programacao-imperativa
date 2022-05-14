/**
 *@file Ficheiro que contem as funcoes das variaveis
 *
 */
#include "variables.h"

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
		if(hastype(stack->val[stack->esp],ARR)){
			v[token[1]-65].ARR = copyArr(stack->val[stack->esp].ARR);
			v[token[1]-65].type=ARR;
		}
		else{
			v[token[1]-65]=stack->val[stack->esp];
		}
		return 1;
	}
	return 0;
}
 

