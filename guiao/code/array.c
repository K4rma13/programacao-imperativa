#include "array.h"

int enumerate(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)){
		stack->val[stack->esp].LNG=stack->val[stack->esp].ARR.size;
		stack->val[stack->esp].type=LNG;
	}
	else{
		int i;
		long int max = stack->val[stack->esp].LNG;
		struct ARR arr;
		arr.size = max;
		arr.all_size = max+10;
		arr.array = malloc(sizeof(DADOS)*arr.all_size);
		for(i=0;i < max;i++){
			arr.array[i].LNG=i;
			arr.array[i].type=LNG;
		}
		stack->val[stack->esp].ARR=arr;
		stack->val[stack->esp].type=ARR;
	}
	return 1;
}

int lastArray(STCK* stack, char* token){
	struct ARR arr;
	arr.size = stack->val[stack->esp].LNG;
	arr.all_size = arr.size+10;
	arr.array = malloc(sizeof(DADOS)*arr.all_size);
	int m = stack->val[stack->esp-1].ARR.size-arr.size;
	int i;
	for(i=0; i < arr.size;i++){
		arr.array[i]=stack->val[stack->esp-1].ARR.array[i+m];
	}
	stack->esp--;
	stack->val[stack->esp].ARR = arr;
	return 1;
}


int initArr(STCK* stack, char* token){
	stack->esp++;
	stack->val[stack->esp].type = CHR;
	stack->val[stack->esp].CHR = '[';
	return 1;
}

int closeArr(STCK* stack, char* token){
	int i,cont=0;
	for(i=stack->esp;stack->val[i].CHR!='[';i--){
		cont++;
	}
	DADOS *array = malloc(sizeof(DADOS)*(cont+10));
	for(i=0;i<cont;i++){
		array[i]=stack->val[stack->esp-cont+1+i];
	}
	stack->esp-=cont;
	stack->val[stack->esp].ARR.array = array;
	stack->val[stack->esp].ARR.all_size = cont+10;
	stack->val[stack->esp].ARR.size = cont;
	stack->val[stack->esp].type = ARR;
}

int initString(STCK* stack, char* token){
	int cont=1,i;
	for(i=1;token[i]!='"';i++){
		cont++;
	}
	DADOS *array = malloc(sizeof(DADOS)*(cont+10));
	for(i=1;token[i]!='"';i++){
		array[i].CHR=token[i];
		array[i].type=CHR;
	}
	stack->esp++;
	stack->val[stack->esp].ARR.array = array;
	stack->val[stack->esp].ARR.all_size = cont+10;
	stack->val[stack->esp].ARR.size = cont;
	stack->val[stack->esp].type = ARR;
}

int indexArr(STCK* stack, char* token){
	long int ind = stack->val[stack->esp].LNG;
	stack->esp--;
	stack->val[stack->esp]=stack->val[stack->esp].ARR.array[ind];

}