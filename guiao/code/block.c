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

	DADOS *array = calloc((cont+10),sizeof(DADOS));
	for(i=0;i<cont+10;i++){
		array[i].ARR=malloc(sizeof(struct ARR));
	}
	for(i=0;i<cont;i++){
		array[i].CHR=token[i];
		array[i].type=CHR;
	}
	stack->esp++;
	stack->val[stack->esp].ARR = malloc(sizeof(struct ARR));
	stack->val[stack->esp].ARR->array = array;
	stack->val[stack->esp].ARR->all_size = cont+10;
	stack->val[stack->esp].ARR->size = cont;
	stack->val[stack->esp].type = BLK;
	return 1;
}

int executeBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='~'){
		int i;
		char* buffer;
		buffer = malloc(stack->val[stack->esp].ARR->size);
		for(i=1;i<stack->val[stack->esp].ARR->size-1;i++){
			buffer[i-1]=stack->val[stack->esp].ARR->array[i].CHR;
		}
		buffer[i-1]='\0';
		free(stack->val[stack->esp].ARR->array);
		stack->esp--;
		parser(buffer,stack,v,functions);
		free(buffer);
		return 1;
	}
	return 0;
}

int mapBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='%'){
		int i;
		char* buffer;
		buffer = malloc(stack->val[stack->esp].ARR->size);
		buffer[0]=' ';
		for(i=1;i<stack->val[stack->esp].ARR->size-1;i++){
			buffer[i-1]=stack->val[stack->esp].ARR->array[i].CHR;
		}
		buffer[i-1]='\0';
		free(stack->val[stack->esp].ARR->array);
		stack->esp--;
		int s = stack->val[stack->esp].ARR->size;
		DADOS *array= stack->val[stack->esp].ARR->array;
		stack->val[stack->esp].CHR='[';
		stack->val[stack->esp].type=DOUBLE;
		stack->esp++;
		for(i=0; i<s;i++){
			stack->val[stack->esp] = array[i];
			parser(buffer,stack,v,functions);
			stack->esp++;
		}
		stack->esp--;
		free(array);
		parser(" ]",stack,v,functions);
		return 1;
	}
	return 0;
}

int foldBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='*'){
		int i;
		char* buffer;
		buffer = malloc(stack->val[stack->esp].ARR->size);
		for(i=1;i<stack->val[stack->esp].ARR->size-1;i++){
			buffer[i-1]=stack->val[stack->esp].ARR->array[i].CHR;
		}
		buffer[i-1]='\0';
		free(stack->val[stack->esp].ARR->array);
		stack->esp--;
		int s = stack->val[stack->esp].ARR->size;
		DADOS *array= stack->val[stack->esp].ARR->array;
		stack->val[stack->esp].CHR='[';
		stack->val[stack->esp].type=DOUBLE;
		stack->esp++;
		stack->val[stack->esp]= array[0];
		for(i=1; i<s;i++){
			stack->esp++;
			stack->val[stack->esp]= array[i];
			parser(buffer,stack,v,functions);
		}
		free(buffer);
		parser(" ]",stack,v,functions);
		return 1;
	}
	return 0;
}

bool smallArray(DADOS a, DADOS b){
	long int i,ret=1;
	for(i=0;b.ARR->size>i&&a.ARR->size>i&&a.ARR->array[i].CHR==b.ARR->array[i].CHR;i++){}
	if((a.ARR->size==i&&b.ARR->size>a.ARR->size)||a.ARR->array[i].CHR<=b.ARR->array[i].CHR){
		ret=0;
	}
	return ret;
}

int ordBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='$'){
		int i;
		if(stack->val[stack->esp-1].ARR->size>0){
			struct ARR *aux = copyArr(stack->val[stack->esp-1].ARR);
			mapBlock(stack,"%",v,functions);
			int flag=0;
			DADOS tmp;
			do{
				flag = 1;
				for(i=0;i<stack->val[stack->esp].ARR->size-1;i++){
					if((!(hastype(stack->val[stack->esp].ARR->array[i],ARR))&&OP_SMALL(stack->val[stack->esp].ARR->array[i],stack->val[stack->esp].ARR->array[i+1]))||(hastype(stack->val[stack->esp].ARR->array[i],ARR)&&smallArray(stack->val[stack->esp].ARR->array[i], stack->val[stack->esp].ARR->array[i+1]))){
						tmp = stack->val[stack->esp].ARR->array[i];
						stack->val[stack->esp].ARR->array[i]=stack->val[stack->esp].ARR->array[i+1];
						stack->val[stack->esp].ARR->array[i+1]=tmp;
						tmp=aux->array[i];
						aux->array[i]=aux->array[i+1];
						aux->array[i+1]=tmp;
						flag=0;
					}
				}
			}while(flag==0);
			stack->val[stack->esp].ARR=aux;
		}
		else{
			stack->esp--;
		}
		return 1;
	}
	return 0;
}

int filterBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]==','){
		int i;
		char* buffer;
		buffer = malloc(stack->val[stack->esp].ARR->size);
		buffer[0]=' ';
		for(i=1;i<stack->val[stack->esp].ARR->size-1;i++){
			buffer[i-1]=stack->val[stack->esp].ARR->array[i].CHR;
		}
		buffer[i-1]='\0';
		free(stack->val[stack->esp].ARR->array);
		stack->esp--;
		int s = stack->val[stack->esp].ARR->size;
		DADOS *array= stack->val[stack->esp].ARR->array;
		stack->val[stack->esp].CHR='[';
		stack->val[stack->esp].type=DOUBLE;
		stack->esp++;
		for(i=0; i<s;i++){
			stack->val[stack->esp] = array[i];
			parser(buffer,stack,v,functions);
			stack->esp++;
		}
		stack->esp--;
		parser(" ]",stack,v,functions);
		DADOS *aux;
		aux= malloc(sizeof(DADOS)*s);
		int cont=0;
		for(i=0;i<s;i++){
			if(stack->val[stack->esp].ARR->array[i].LNG!=0){
				aux[cont]=array[i];
				cont++;
			}
		}
		stack->val[stack->esp].ARR=malloc(sizeof(struct ARR));
		stack->val[stack->esp].ARR->array=aux;
		stack->val[stack->esp].ARR->size=cont;
		stack->val[stack->esp].ARR->all_size=s;
		return 1;
	}
	return 0;
}

int whileBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='w'){
		int i;
		char* buffer;
		buffer = malloc(stack->val[stack->esp].ARR->size);
		for(i=1;i<stack->val[stack->esp].ARR->size-1;i++){
			buffer[i-1]=stack->val[stack->esp].ARR->array[i].CHR;
		}
		buffer[i-1]='\0';
		free(stack->val[stack->esp].ARR->array);
		stack->esp--;
		parser(buffer,stack,v,functions);
		while((!OP_FALSE(stack->val[stack->esp]))&&stack->esp>=0){
			stack->esp--;
			parser(buffer,stack,v,functions);
		}
		stack->esp--;
		free(buffer);
		return 1;
	}
	return 0;
}