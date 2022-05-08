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
#include "logic.h"
#include "variables.h"
#include "array.h"

/**
 * \brief Esta funcao decide qual é a funcao que deve ser executada dependendo do valor que foi lido do input
 * @param stack A stack
 * @param token Valor a ser interpretado
 */

int handlerValores(STCK* stack, char* token){
	if((token[0]=='-' && (token[1]>='0'&& token[1]<='9'))||(token[0]>='0'&& token[0]<='9')){
		if(!(valor_Double(stack,token) || valor(stack,token))){
			printf("erro");
		}
		return 1;
	}
	return 0;
}

int handlerLetras(STCK* stack, char* token, DADOS* v){
	if((token[0]>='A'&& token[0]<='Z')||token[0]==':'){
		if(!(splitNL(stack,token) || splitSpace(stack,token) || variablePush(stack,token,v) || variableGet(stack,token,v))){
			printf("erro");
		}
		return 1;
	}
	return 0;
}


void handler(STCK* stack, char* token, DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='e'){
		functions[127+token[1]](stack,token);
	}
	else{
		if(!(handlerValores(stack,token)||handlerLetras(stack,token,v))){
			functions[(int)token[0]](stack,token);
		}
	}
}

void definefunctions(int (*functions[])(STCK*,char*)){
	functions['+']=add;
	functions['-']=sub;
	functions['*']=mul;
	functions['/']=divisao;
	functions['i']=toLNG;
	functions['f']=toDouble;
	functions['&']=and;
	functions['|']=or;
	functions['^']=xor;
	functions['%']=module;
	functions[')']=incr;
	functions['(']=decr;
	functions['~']=not;
	functions['#']=potencia;
	functions['l']=inputToStr;
	functions['c']=longToCHR;
	functions[';']=removeTop;
	functions['_']=duplicar;
	functions['\\']=trocar;
	functions['@']=rodar;
	functions['!']=isFalse;
	functions['=']=isEqual;
	functions['<']=isSmall;
	functions['>']=isBig;
	functions['?']=ifThenElse;
	functions[127+'&']=logicalAnd;
	functions[127+'|']=logicalOr;
	functions[127+'>']=logicalGreater;
	functions[127+'<']=logicalLess;
	functions['$']=cpyStack;
	functions['[']=initArr;
	functions[']']=closeArr;
	functions[',']=enumerate;
	functions['t']=everythingToStr;
	functions['"']=initString;
}

/**
 * \brief Funcao main
 * Inicia variaveis e le a linha do input para ser passada para o handler
 */

int main(){
	int (*functions[0xff])(STCK*,char*);
	definefunctions(functions);

	DADOS v[26];
	int i;
	for(i=0;i<6;i++){
		v[i].LNG=i+10;
		v[i].type = LNG;
	}
	v[13].CHR = '\n';
	v[13].type = CHR;
	v[18].CHR = ' ';
	v[18].type = CHR;
	for(i=23;i<26;i++){
		v[i].LNG=i-23;
		v[i].type = LNG;
	}
	STCK *stack;
	stack = malloc(sizeof(STCK));
	stack->val = malloc(sizeof(DADOS)*20000);
//	stack->val[0].LNG= 65;
//	stack->val[0].type= LNG;
//	stack->val[1].LNG= 5;
//	stack->val[1].type= LNG;
	stack->esp=-1;
//	stack->val[0].LNG += stack->val[1].LNG; 
	int n=0;

	char buffer[10000], aux[10],*b;
	if(fgets(buffer, sizeof(buffer), stdin)!= NULL){
		buffer[strlen(buffer)-1]='\0';
		b=buffer;
		while(*b!='\0'){
			if(*b=='"'){
				sscanf(b+1,"%[^\"]s",aux+1);
				aux[0]='"';
				n = strlen(aux);
				aux[n+1]='\0';
				aux[n]='"';
				n+=2;
			}
			else{
				sscanf(b,"%s %n",aux,&n);
				
			}
			b+=n;
			handler(stack,aux,v,functions);

		}
		printstack(stack);
		printf("\n");
	}
	return 0;
}