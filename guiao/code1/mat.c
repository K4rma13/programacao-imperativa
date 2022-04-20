#include "mat.h"

/**
 * \brief Esta funcao exponencia o segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int potencia(STCK* stack, char* token){
	if(strcmp(token,"#")==0){
		stack->val[stack->esp-1]=pow(stack->val[stack->esp-1],stack->val[stack->esp]);
		stack->esp--;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao adiciona os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int add(STCK* stack, char* token){
	if(strcmp(token,"+")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]+stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao subtrai o segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int sub(STCK* stack, char* token){
	if(strcmp(token,"-")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]-stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao divide o segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int divisao(STCK* stack, char* token){
	if(strcmp(token,"/")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]/stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao multiplica os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int mul(STCK* stack, char* token){
	if(strcmp(token,"*")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]*stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao incrementa o valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int incr(STCK* stack, char* token){
	if(strcmp(token,")")==0){
		stack->val[stack->esp]++;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao decrementa o valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int decr(STCK* stack, char* token){
	if(strcmp(token,"(")==0){
		stack->val[stack->esp]--;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao calcula o resto de uma divisao inteira do segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int module(STCK* stack, char* token){
	if(strcmp(token,"%")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]%stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao calcula o "and(bitwise)" entre os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int and(STCK* stack, char* token){
	if(strcmp(token,"&")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]&stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao calcula o "or(bitwise)" entre os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int or(STCK* stack, char* token){
	if(strcmp(token,"|")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]|stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao calcula o "xor(bitwise)" entre os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int xor(STCK* stack, char* token){
	if(strcmp(token,"^")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]^stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao calcula o "not(bitwise)" do valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int not(STCK* stack, char* token){
	if(strcmp(token,"~")==0){
		stack->val[stack->esp]= ~stack->val[stack->esp];
		return 1;
	}
	return 0;
}