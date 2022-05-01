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

/**
 * \brief Esta funcao decide qual é a funcao que deve ser executada dependendo do valor que foi lido do input
 * @param stack A stack
 * @param token Valor a ser interpretado
 */








void handler(STCK* stack, char* token, DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='e'){
		functions[127+token[1]](stack,token);
	}
	else if(token[0]>='0'&& token[0]<='9'){
		valor_Double(stack,token) || valor(stack,token);
	}
	else if((token[0]>='A'&& token[0]<='Z')||token[0]==':'){
		variablePush(stack,token,v) || variableGet(stack,token,v);
	}
	else{
		functions[token[0]](stack,token);
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
	functions['l']=lestring;
	functions['c']=longToCHR;
	functions[';']=removeTop;
	functions['_']=duplicar;
	functions['\\']=trocar;
	functions['@']=rodar;
	functions['!']=isFalse;
	functions['&']=isEqual;
	functions['<']=isSmall;
	functions['>']=isBig;
	functions['?']=ifThenElse;
	functions[127+'&']=logicalAnd;
	functions[127+'|']=logicalOr;
	functions[127+'>']=logicalGreater;
	functions[127+'<']=logicalLess;
	functions['$']=cpyStack;
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
			handler(&stack,aux,v,functions);
		}
		printstack(stack);
		printf("\n");
	}
	return 0;
}