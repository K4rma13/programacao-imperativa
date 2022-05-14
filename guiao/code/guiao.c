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
#include "handler.h"
#include "block.h"

void definefunctions(int (*functions[])(STCK*,char*)){
	functions['+']=plus;
	functions['-']=sub;
	functions['*']=asterisco;
	functions['/']=slash;
	functions['i']=toLNG;
	functions['f']=toDouble;
	functions['&']=and;
	functions['|']=or;
	functions['^']=xor;
	functions['%']=module;
	functions[')']=parClose;
	functions['(']=parOpen;
	functions['~']=til;
	functions['#']=hastag;
	functions['l']=inputToStr;
	functions['c']=toCHR;
	functions[';']=removeTop;
	functions['_']=duplicar;
	functions['\\']=trocar;
	functions['@']=rodar;
	functions['!']=isFalse;
	functions['=']=equal;
	functions['<']=lessSign;
	functions['>']=greaterSign;
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
	functions['{']=createBlock;
	functions['p']=printTopo;
	functions['s']=toString;
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
	stack->val = malloc(sizeof(DADOS)*10000000);
	stack->esp=-1;

	char buffer[100000];
	if(fgets(buffer, sizeof(buffer), stdin)!= NULL){
		buffer[strlen(buffer)-1]='\0';
		parser(buffer,stack,v,functions);
		printstack(stack);
		printf("\n");
	}
	return 0;
}