/**
 *@file Ficheiro que contem as funcoes das variaveis (guiao 3)
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
			v[token[1]-65].ARR.array = malloc(sizeof(DADOS)*stack->val[stack->esp].ARR.all_size);
			v[token[1]-65].ARR.size = stack->val[stack->esp].ARR.size;
			v[token[1]-65].ARR.all_size = stack->val[stack->esp].ARR.all_size;
			int i;
			for(i=0; i<v[token[1]-65].ARR.size; i++){
				v[token[1]-65].ARR.array[i] = stack->val[stack->esp].ARR.array[i];
			}
			v[token[1]-65].type=ARR;
		}
		else{
			v[token[1]-65]=stack->val[stack->esp];
		}
		return 1;
	}
	return 0;
}
 

