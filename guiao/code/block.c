#include "block.h"

int createBlock(STCK* stack, char* token){
	int cont=1,i, x=1;
	for(i=1;x!=0;i++){
		if(token[i]=='}'){
			x--;
		}
		else if(token[i]=='{'){
			x++;
		}
		cont++;
	}

	DADOS *array = malloc(sizeof(DADOS)*(cont+10));
	for(i=0;i<cont;i++){
		array[i].CHR=token[i];
		array[i].type=CHR;
	}
	stack->esp++;
	stack->val[stack->esp].ARR.array = array;
	stack->val[stack->esp].ARR.all_size = cont+10;
	stack->val[stack->esp].ARR.size = cont;
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
		buffer[i-1]='\0';
		stack->esp--;
		parser(buffer,stack,v,functions);
		return 1;
	}
	return 0;
}

int mapBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='%'){
		int i;
		char buffer[400];
		for(i=1;i<stack->val[stack->esp].ARR.size-1;i++){
			buffer[i-1]=stack->val[stack->esp].ARR.array[i].CHR;
		}
		buffer[i-1]='\0';
		stack->esp--;
		int s = stack->val[stack->esp].ARR.size;
		DADOS *array= stack->val[stack->esp].ARR.array;
		stack->val[stack->esp].CHR='[';
		stack->val[stack->esp].type=CHR;
		stack->esp++;
		for(i=0; i<s;i++){
			stack->val[stack->esp] = array[i];
			
			parser(buffer,stack,v,functions);
			stack->esp++;
		}
		stack->esp--;
		parser(" ]",stack,v,functions);
		return 1;
	}
	return 0;
}

int foldBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='*'){
		int i;
		char buffer[400];
		for(i=1;i<stack->val[stack->esp].ARR.size-1;i++){
			buffer[i-1]=stack->val[stack->esp].ARR.array[i].CHR;
		}
		buffer[i-1]='\0';
		stack->esp--;
		int s = stack->val[stack->esp].ARR.size;
		DADOS *array= stack->val[stack->esp].ARR.array;
		stack->val[stack->esp]= array[0];
		for(i=0; i<s-1;i++){
			stack->esp++;
			stack->val[stack->esp]= array[i];
			parser(buffer,stack,v,functions);
		}
		return 1;
	}
	return 0;
}