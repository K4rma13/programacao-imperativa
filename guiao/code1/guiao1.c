/**
 *@file Ficheiro que contem as funçoes principais
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"
#include "mat.h"


/**
 * \brief Esta funcao adiciona valores no topo da stack
 * @returns Retorna 1
 * @param stack A stack
 * @param token Valor a ser interpretado
 */
int valor(STCK* stack, char* token){
	stack->esp++;
	stack->val[stack->esp]=atoi(token); 
	return 1;
}

/**
 * \brief Esta funcao decide qual é a funcao que deve ser executada dependendo do valor que foi lido do input
 * @param stack A stack
 * @param token Valor a ser interpretado
 */
void handler(STCK* stack, char* token){
	if(!(potencia(stack,token) || add(stack,token) || sub(stack,token) || mul(stack,token) || 
		incr(stack,token) || decr(stack,token) || divisao(stack,token) || module(stack,token)||
		and(stack,token) || or(stack,token) || xor(stack,token) || not(stack,token) || valor(stack,token))){
		printf("Erro\n");
	}
}

/**
 * \brief Funcao main
 * Inicia variaveis e le a linha do input para ser passada para o handler
 */

int main(){
	STCK stack;
	stack.esp=-1;
	int n=0;

	char buffer[10000], aux[10],*b;
	if(fgets(buffer, sizeof(buffer), stdin)!= NULL){
		buffer[strlen(buffer)-1]='\0';
		b=buffer;
		while(*b!='\0'){
			sscanf(b,"%s %n",aux,&n);
			b+=n;
			handler(&stack,aux);
		}
		for(int i=0;i<=stack.esp;i++){
			printf("%d",stack.val[i]);
		}
		printf("\n");
	}
	return 0;
}
