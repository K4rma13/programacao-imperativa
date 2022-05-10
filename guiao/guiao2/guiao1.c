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
 * \brief Esta funcao decide qual é a funcao que deve ser executada dependendo do valor que foi lido do input
 * @param stack A stack
 * @param token Valor a ser interpretado
 */
void handler(STCK* stack, char* token){
	if(!(add(stack,token) || sub(stack,token) || mul(stack,token)| divisao(stack,token) || toLNG(stack,token) || toDouble(stack,token) ||
	 and(stack,token) || or(stack,token) || xor(stack,token) || module(stack,token) || incr(stack,token) || decr(stack,token) || not(stack,token) ||
	  potencia(stack,token) || lestring(stack,token) || longToCHR(stack,token) || removeTop(stack,token) || duplicar(stack,token) || trocar(stack,token)||
	  rodar(stack,token) || cpyStack(stack,token) || valor_Double(stack,token) || valor(stack,token))){
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
		printstack(stack);
		printf("\n");
	}
	return 0;
}
