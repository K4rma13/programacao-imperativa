/**
 *@file Ficheiro que contem as funcoes das variaveis
 *
 */
#include "variables.h"

/**
 * \brief Funcao faz push da variavel correspondente para a stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param DADOS Variaveis A-Z
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int variablePush(STCK* stack, char* token, DADOS* v){
	if(token[0] >= 'A' && token[0] <= 'Z'){
		stack->esp++;
		if(hastype(v[token[0]-65],ARR)){
			stack->val[stack->esp].ARR = copyArr(v[token[0]-65].ARR);
			stack->val[stack->esp].type=ARR;
		}
		else if(hastype(v[token[0]-65],BLK)){
			stack->val[stack->esp].ARR = copyArr(v[token[0]-65].ARR);
			stack->val[stack->esp].type=BLK;
		}
		else{
			stack->val[stack->esp] = v[token[0]-65];
		}

		return 1;
	}
	return 0;
}

/**
 * \brief Funcao copia o topo da stack e guarda o na variavel correspondente
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param DADOS Variaveis A-Z
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int variableGet(STCK* stack, char* token, DADOS* v){
	if(token[0] == ':'){
		if(hastype(stack->val[stack->esp],ARR)){
			v[token[1]-65].ARR = copyArr(stack->val[stack->esp].ARR);
			v[token[1]-65].type=ARR;
		}
		else if(hastype(stack->val[stack->esp],BLK)){
			v[token[1]-65].ARR = copyArr(stack->val[stack->esp].ARR);
			v[token[1]-65].type=BLK;
		}
		else{
			v[token[1]-65]=stack->val[stack->esp];
		}
		return 1;
	}
	return 0;
}
