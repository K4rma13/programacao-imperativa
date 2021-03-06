/**
 *@file Ficheiro que contem as funçoes matematicas (guiao 1-2)
 *
 */
#include "mat.h"

#define OPERATION_SGN(_name,_sinal)				\
	double double_##_name(DADOS b,DADOS a){		\
		if(hastype(a,DOUBLE)){					\
			if(hastype(b,DOUBLE)){				\
				return a.DOUBLE _sinal b.DOUBLE;\
			}									\
			else{								\
				return a.DOUBLE _sinal b.LNG;	\
			}									\
		}										\
		else{									\
			return a.LNG _sinal b.DOUBLE;		\
		}										\
	}											\
	long int long_##_name(DADOS b,DADOS a){		\
		return a.LNG _sinal b.LNG;				\
	}

OPERATION_SGN(ADD,+)
OPERATION_SGN(SUB,-)
OPERATION_SGN(MUL,*)
OPERATION_SGN(DIV,/)

void nothing(){

}

void concatArray( typearray* array1, typearray array2){
	int i;
	int s;
	s=array1->size;
	array1->array = realloc(array1->array,sizeof(DADOS)*(array1->all_size+array2.all_size));
	array1->size += array2.size;
	array1->all_size += array2.all_size;

	for(i=s; i<array1->size;i++){
		array1->array[i]=array2.array[i-s];
	}
}


void arrADD(STCK* stack){
	int i;
	if(hastype(stack->val[stack->esp],ARR)&&hastype(stack->val[stack->esp-1],ARR)){
		concatArray(&stack->val[stack->esp-1].ARR,stack->val[stack->esp].ARR);
		stack->esp--;
	}
	else if(hastype(stack->val[stack->esp],ARR)){
		if(stack->val[stack->esp].ARR.size+1>=stack->val[stack->esp].ARR.all_size){
			stack->val[stack->esp].ARR.array = realloc(stack->val[stack->esp].ARR.array, sizeof(DADOS)*(stack->val[stack->esp].ARR.all_size+10));
		}
		for(i=stack->val[stack->esp].ARR.size-1;i>=0;i--){
			stack->val[stack->esp].ARR.array[i+1] = stack->val[stack->esp].ARR.array[i];
		}
		stack->val[stack->esp].ARR.size++;
		stack->val[stack->esp].ARR.array[0] = stack->val[stack->esp-1];
		stack->val[stack->esp-1]=stack->val[stack->esp];
		stack->esp--;
	}
	else{
		if(stack->val[stack->esp-1].ARR.size+1>=stack->val[stack->esp-1].ARR.all_size){
			stack->val[stack->esp-1].ARR.array = realloc(stack->val[stack->esp-1].ARR.array, sizeof(DADOS)*(stack->val[stack->esp-1].ARR.all_size+10));
		}
		stack->val[stack->esp-1].ARR.array[stack->val[stack->esp-1].ARR.size]=stack->val[stack->esp];
		stack->val[stack->esp-1].ARR.size++;
		stack->esp--;
	}
}


void arrMUL(STCK* stack){
	int i;
	long int m;
	struct ARR arr;
	if(hastype(stack->val[stack->esp],ARR)){
		arr = stack->val[stack->esp].ARR;
		m = stack->val[stack->esp-1].LNG;
	}
	else{
		arr = stack->val[stack->esp-1].ARR;
		m = stack->val[stack->esp].LNG;
	}
	if(arr.size*m>=arr.all_size){
			arr.all_size*=m;
			arr.array = realloc(arr.array, sizeof(DADOS)*arr.all_size);
		}
		int s = arr.size;
		arr.size *= m;
		for(i=0; i<arr.size;i++){
			arr.array[i] = arr.array[i%s];
		}
		stack->val[stack->esp-1].ARR=arr;
		stack->val[stack->esp-1].type=ARR;
		stack->esp--;
}


/**
 * \brief Esta funcao exponencia o segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */


int potencia(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp],ARR)){
		findArr(stack,token);
	}
	else if(hastype(stack->val[stack->esp],DOUBLE)){
		if(hastype(stack->val[stack->esp-1],DOUBLE)){
			stack->val[stack->esp-1].DOUBLE = pow(stack->val[stack->esp-1].DOUBLE,stack->val[stack->esp].DOUBLE);
			stack->val[stack->esp-1].type = DOUBLE;
			stack->esp--;
		}
		else{
			stack->val[stack->esp-1].DOUBLE = pow(stack->val[stack->esp-1].LNG,stack->val[stack->esp].DOUBLE);
			stack->val[stack->esp-1].type = DOUBLE;
			stack->esp--;
		}
	}
	else{
		if(hastype(stack->val[stack->esp-1],DOUBLE)){
			stack->val[stack->esp-1].DOUBLE = pow(stack->val[stack->esp-1].LNG,stack->val[stack->esp].DOUBLE);
			stack->val[stack->esp-1].type = DOUBLE;
			stack->esp--;
		}
		else{
			stack->val[stack->esp-1].LNG = pow(stack->val[stack->esp-1].LNG,stack->val[stack->esp].LNG);
			stack->val[stack->esp-1].type = LNG;
			stack->esp--;
		}
	}
	//stack->val[stack->esp-1]=pow(stack->val[stack->esp-1],stack->val[stack->esp]);
	return 1;
}

/**
 * \brief Esta funcao adiciona os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int add(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		if(hastype(stack->val[stack->esp],DOUBLE)||hastype(stack->val[stack->esp-1],DOUBLE)){
			double tmp = double_ADD(stack->val[stack->esp],stack->val[stack->esp-1]);
			stack->esp-=2;
			//printf("--%lf--\n",tmp);
			push_DOUBLE(stack,tmp);
		}
		else if(hastype(stack->val[stack->esp],ARR)||hastype(stack->val[stack->esp-1],ARR)){
			arrADD(stack);
		}
		else{
			long int tmp = long_ADD(stack->val[stack->esp],stack->val[stack->esp-1]);
			stack->esp-=2;
			push_LNG(stack,tmp);
		}
		return 1;
}
/**
 * \brief Esta funcao subtrai o segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int sub(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		if(hastype(stack->val[stack->esp],DOUBLE)||hastype(stack->val[stack->esp-1],DOUBLE)){
			double tmp = double_SUB(stack->val[stack->esp],stack->val[stack->esp-1]);
			stack->esp-=2;
			push_DOUBLE(stack,tmp);
		}
		else{
			long int tmp = long_SUB(stack->val[stack->esp],stack->val[stack->esp-1]);
			stack->esp-=2;
			push_LNG(stack,tmp);
		};
		return 1;
}
/**
 * \brief Esta funcao divide o segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int divisao(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp],ARR)){
		splitStr(stack,token);
	}
	else if(hastype(stack->val[stack->esp],DOUBLE)||hastype(stack->val[stack->esp-1],DOUBLE)){
		double tmp = double_DIV(stack->val[stack->esp],stack->val[stack->esp-1]);
		stack->esp-=2;
		push_DOUBLE(stack,tmp);
	}
	else{
		long int tmp = long_DIV(stack->val[stack->esp],stack->val[stack->esp-1]);
		stack->esp-=2;
		push_LNG(stack,tmp);
	}
	return 1;
}
/**
 * \brief Esta funcao multiplica os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int mul(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		if(hastype(stack->val[stack->esp],ARR)||hastype(stack->val[stack->esp-1],ARR)){
			arrMUL(stack);
		}
		else if(hastype(stack->val[stack->esp],DOUBLE)||hastype(stack->val[stack->esp-1],DOUBLE)){
			double tmp = double_MUL(stack->val[stack->esp],stack->val[stack->esp-1]);
			stack->esp-=2;
			push_DOUBLE(stack,tmp);
		}
		else{
			long int tmp = long_MUL(stack->val[stack->esp],stack->val[stack->esp-1]);
			stack->esp-=2;
			push_LNG(stack,tmp);
		}
		return 1;
}
/**
 * \brief Esta funcao incrementa o valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int incr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp],ARR)){
		rmLastArr(stack,token);
	}
	else if(hastype(stack->val[stack->esp],DOUBLE)){
		stack->val[stack->esp].DOUBLE++;
	}
	else if(hastype(stack->val[stack->esp],LNG)){
		stack->val[stack->esp].LNG++;
	}
	else{
		stack->val[stack->esp].CHR++;
	}		
	return 1;
}

/**
 * \brief Esta funcao decrementa o valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int decr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp],ARR)){
		rmFirstArr(stack,token);
	}
	else if(hastype(stack->val[stack->esp],DOUBLE)){
		stack->val[stack->esp].DOUBLE--;
	}
	else if(hastype(stack->val[stack->esp],LNG)){
		stack->val[stack->esp].LNG--;
	}
	else{
		stack->val[stack->esp].CHR--;
	}
	return 1;
}

/**
 * \brief Esta funcao calcula o resto de uma divisao inteira do segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int module(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		if(hastype(stack->val[stack->esp],LNG)){
			long int tmp = stack->val[stack->esp-1].LNG%stack->val[stack->esp].LNG;
			stack->esp-=2;
			push_LNG(stack,tmp);
		}
		return 1;
}
/**
 * \brief Esta funcao calcula o "and(bitwise)" entre os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int and(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		if(hastype(stack->val[stack->esp],LNG)){
			long int tmp = stack->val[stack->esp].LNG&stack->val[stack->esp-1].LNG;
			stack->esp-=2;
			push_LNG(stack,tmp);
		}
		return 1;
}
/**
 * \brief Esta funcao calcula o "or(bitwise)" entre os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int or(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		if(hastype(stack->val[stack->esp],LNG)){
			long int tmp = stack->val[stack->esp].LNG|stack->val[stack->esp-1].LNG;
			stack->esp-=2;
			push_LNG(stack,tmp);
		}
		return 1;
}
/**
 * \brief Esta funcao calcula o "xor(bitwise)" entre os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int xor(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		if(hastype(stack->val[stack->esp],LNG)){
			long int tmp = stack->val[stack->esp].LNG^stack->val[stack->esp-1].LNG;
			stack->esp-=2;
			push_LNG(stack,tmp);
		}
		return 1;
}

/**
 * \brief Esta funcao calcula o "not(bitwise)" do valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int not(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		if(hastype(stack->val[stack->esp],LNG)){
			stack->val[stack->esp].LNG = ~(stack->val[stack->esp].LNG);
		}
		else if(hastype(stack->val[stack->esp],ARR)){
			arrayToStack(stack,token);
		}
		return 1;
}
