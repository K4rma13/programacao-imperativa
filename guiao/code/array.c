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