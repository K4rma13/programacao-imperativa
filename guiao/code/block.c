#include "block.h"

int createBlock(STCK* stack, char* token){
	int cont=1,i;
	for(i=0;token[i-1]!='}';i++){
		cont++;
	}
	DADOS *array = malloc(sizeof(DADOS)*(cont+10));
	for(i=0;token[i-1]!='}';i++){
		array[i].CHR=token[i];
		array[i].type=CHR;
	}
	stack->esp++;
	stack->val[stack->esp].ARR.array = array;
	stack->val[stack->esp].ARR.all_size = cont+10;
	stack->val[stack->esp].ARR.size = cont-1;
	stack->val[stack->esp].type = BLK;
	return 1;
}

int executeBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='~'){
		int i;
		char buffer[400];
		for(i=1;i<stack->val[stack->esp].ARR.size-1;i++){
			buffer[i-1]=stack->val[stack->esp].ARR.array[i].CHR;
		}
		stack->esp--;
		parser(buffer,stack,v,functions);
		return 1;
	}
	return 0;
}