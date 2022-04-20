#include "stack.h"

/**
 * \brief Esta funcao adiciona valores no topo da stack
 * @returns Retorna 1
 * @param stack A stack
 * @param token Valor a ser interpretado
 */
int valor(STCK* stack, char* token){
	stack->esp++;
	stack->val[stack->esp].type=0;
	strcpy(stack->val[stack->esp].str,token); 
	return 1;
}

int toint(STCK* stack, char* token){
	if(strcmp(token,"i")==0){
		stack->val[stack->esp].type=2;
		stack->val[stack->esp].i=atoi(stack->val[stack->esp].str); 
		return 1;
	}
	return 0;
}


void printstack(STCK stack){
	for(int i=0;i<=stack.esp;i++){
		printf("%d",stack.val[stack.esp].i);
	}
	printf("\n");
}