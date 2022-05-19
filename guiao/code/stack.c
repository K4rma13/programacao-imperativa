/**
 *@file Ficheiro que contem as funçoes da stack
 *
 */
#include "stack.h"

#define OP_STACK(_name, _type)								\
/**															\
 * \brief Esta função da push a uma variavel do tipo _name \
 * @param stack A stack \
 * @param value Valor a colocado no topo da stack \
 */															\
	void push_##_name(STCK* stack, _type value){			\
		stack->esp++;										\
		stack->val[stack->esp]._name=value;					\
		stack->val[stack->esp].type = _name;				\
	}														\
/**															\
 * \brief Esta função da pop a uma variavel do tipo _name 	\
 * @param stack A stack 									\
 * @returns O valor no topo da stack 						\
 */															\
	_type pop_##_name(STCK* stack){							\
		_type value = stack->val[stack->esp]._name;			\
		stack->esp--;										\
		return value;										\
	}														\

OP_STACK(LNG,long int)
OP_STACK(CHR,char)
OP_STACK(DOUBLE,double)

/**			
 * \brief Ve se o tipo do dado é o mesmo do tipo fornecido 	
 * @param dado O Dado a ser comparado
 * @param tipo O Tipo a ser testado
 * @returns true se o dado tiver o mesmo tipo ou caso contrario false						
 */	

bool hastype(DADOS dado, TYPE tipo){
	return dado.type == tipo;
}

void printArr(struct ARR *stack){
	for(int i=0;i<stack->size;i++){
		if(hastype(stack->array[i],CHR)){
			printf("%c",stack->array[i].CHR);
		}
		else if(hastype(stack->array[i],LNG)){
			printf("%ld",stack->array[i].LNG);
		}
		else if(hastype(stack->array[i],DOUBLE)){
			printf("%g",stack->array[i].DOUBLE);
		}
		else{
			//printf("[ ");
			printArr(stack->array[i].ARR);
			//printf(" ]");
		}
		//printf(",");
	}
}


/**		
 * \brief Imprime para o stdout a stack fornecida
 * @param stack A stack
 */

void printstack(STCK* stack){
	for(int i=0;i<=stack->esp;i++){
		if(hastype(stack->val[i],CHR)){
			printf("%c",stack->val[i].CHR);
		}
		else if(hastype(stack->val[i],LNG)){
			printf("%ld",stack->val[i].LNG);
		}
		else if(hastype(stack->val[i],DOUBLE)){
			printf("%g",stack->val[i].DOUBLE);
		}
		else{
			//printf("[ ");
			printArr(stack->val[i].ARR);
			//printf(" ]");
		}
	//printf("_");
	}
}

int printTopo(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp],CHR)){
		printf("%c",stack->val[stack->esp].CHR);
	}
	else if(hastype(stack->val[stack->esp],LNG)){
		printf("%ld",stack->val[stack->esp].LNG);
	}
	else if(hastype(stack->val[stack->esp],DOUBLE)){
		printf("%g",stack->val[stack->esp].DOUBLE);
	}
	else{
		printArr(stack->val[stack->esp].ARR);
	}
	printf("\n");
	return 1;
}

/**			
 * \brief Testa se uma string tem um '.'
 * @param token String a ser testada
 * @returns true se a string possuir um '.', caso contrario false						
 */	

bool isdecimal(char* token){
	int i;
	for(i=0;token[i]!='\0';i++){
		if(token[i]=='.'){
			return true;
		}
	}
	return false;
}

/**
 * \brief Esta funcao adiciona valores no topo da stack
 * @returns Retorna 1
 * @param stack A stack
 * @param token Valor a ser interpretado
 */
int valor(STCK* stack, char* token){
	long int aux;
	sscanf(token,"%ld",&aux);
	push_LNG(stack,aux);
	return 1;
}

/**
 * \brief Esta funcao adiciona valores decimais no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int valor_Double(STCK* stack, char* token){
	if(isdecimal(token)){
		double aux;
		sscanf(token,"%lf",&aux);
		push_DOUBLE(stack,aux);
		return 1;
	}
	return 0;
}

struct ARR* copyArr(struct ARR *arr){
	struct ARR *ret;
	ret = malloc(sizeof(struct ARR));
	ret->array = malloc(sizeof(DADOS)*(arr->size));
	ret->size = arr->size;
	ret->all_size = arr->size;
	int i;
	for(i=0; i<arr->size; i++){
		if(hastype(arr->array[i],ARR)){
			ret->array[i].ARR=copyArr(arr->array[i].ARR);
			ret->array[i].type=ARR;
		}
		else{
			ret->array[i] = arr->array[i];
		}
	}
	return ret;
}

void strToDouble(STCK* stack){
	int s=stack->val[stack->esp].ARR->size,i;
	char aux[s];
	for(i=0;i<s;i++){
		aux[i]=stack->val[stack->esp].ARR->array[i].CHR;
	}
	aux[i]='\0';
	sscanf(aux,"%lf",&stack->val[stack->esp].DOUBLE);
	stack->val[stack->esp].type=DOUBLE;
}

void strToLng(STCK* stack){
	int s=stack->val[stack->esp].ARR->size,i;
	char aux[s];
	for(i=0;i<s;i++){
		aux[i]=stack->val[stack->esp].ARR->array[i].CHR;
	}
	aux[i]='\0';
	sscanf(aux,"%ld",&stack->val[stack->esp].LNG);
	stack->val[stack->esp].type=LNG;
}

/**
 * \brief Esta funcao muda o tipo da variavel no topo da stack para DOUBLE
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int toDouble(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp],ARR)){
		strToDouble(stack);
	}
	else if(hastype(stack->val[stack->esp],LNG)){
		stack->val[stack->esp].DOUBLE = (double)stack->val[stack->esp].LNG;
	}
	else if(hastype(stack->val[stack->esp],CHR)){
		stack->val[stack->esp].DOUBLE = (double)stack->val[stack->esp].CHR;
	}
	stack->val[stack->esp].type = DOUBLE;
	return 1;
}

/**
 * \brief Esta funcao muda o tipo da variavel no topo da stack para LONG
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int toLNG(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp],ARR)){
		strToLng(stack);
	}
	else if(hastype(stack->val[stack->esp],DOUBLE)){
		stack->val[stack->esp].LNG = (long int)stack->val[stack->esp].DOUBLE;
	}
	else if(hastype(stack->val[stack->esp],CHR)){
		stack->val[stack->esp].LNG = (long int)stack->val[stack->esp].CHR;
	}
	stack->val[stack->esp].type = LNG;
	return 1;
}

/**
 * \brief Esta funcao muda o tipo da variavel no topo da stack de LONG para CHAR
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int toCHR(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp],LNG)){
		stack->val[stack->esp].CHR = stack->val[stack->esp].LNG;
		stack->val[stack->esp].type = CHR;
	}
	else if(hastype(stack->val[stack->esp],DOUBLE)){
		stack->val[stack->esp].CHR = (int)stack->val[stack->esp].DOUBLE;
		stack->val[stack->esp].type = CHR;
	}
	else if(hastype(stack->val[stack->esp],ARR)){
		stack->val[stack->esp].CHR = stack->val[stack->esp].ARR->array[0].CHR;
		stack->val[stack->esp].type = CHR;
	}
	return 1;
}

/**
 * \brief Esta funcao faz push a uma copia do valor na nºesima posicao
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int cpyStack(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	long int index;
	if(hastype(stack->val[stack->esp],LNG)){
		index = pop_LNG(stack);
	}
	else{
		index = (long int) pop_DOUBLE(stack);
	}
	DADOS data;
	if(hastype(stack->val[stack->esp-index],ARR)){
		data.ARR = copyArr(stack->val[stack->esp-index].ARR);
		data.type = ARR;
	}
	else if(hastype(stack->val[stack->esp-index],BLK)){
		data.ARR = copyArr(stack->val[stack->esp-index].ARR);
		data.type = BLK;
	}
	else{
		data = stack->val[stack->esp-index];
	}
	stack->esp++;
	stack->val[stack->esp] = data;
	return 1;
}

 /**
 * \brief Esta funcao roda os 3 elementos no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int rodar(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	DADOS a = stack->val[stack->esp], b = stack->val[stack->esp-1], c = stack->val[stack->esp-2];
	stack->val[stack->esp] = c;
	stack->val[stack->esp-1] = a;
	stack->val[stack->esp-2] = b;
	return 1;
}

/**
 * \brief Esta funcao troca os 2 valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int trocar(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	DADOS a = stack->val[stack->esp], b = stack->val[stack->esp-1];
	stack->val[stack->esp] = b;
	stack->val[stack->esp-1] = a;
	return 1;
}

/**
 * \brief Esta funcao faz push a uma copia do valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int duplicar(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	DADOS a;
	if(hastype(stack->val[stack->esp],ARR)){
		a.ARR = copyArr(stack->val[stack->esp].ARR);
		a.type=ARR;
	}
	else if(hastype(stack->val[stack->esp],BLK)){
		a.ARR = copyArr(stack->val[stack->esp].ARR);
		a.type=BLK;
	}
	else{
		a = stack->val[stack->esp];
	}
	stack->esp++;
	stack->val[stack->esp] = a;
	return 1;
}

/**
 * \brief Esta funcao faz ""Pop""
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int removeTop(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	stack->esp--;
	return 1;
}

int toString(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	int i;
	char aux[200000];
	struct ARR* tmp;
	tmp = stack->val[stack->esp].ARR;
	stack->val[stack->esp].ARR=malloc(sizeof(struct ARR));
	if(hastype(stack->val[stack->esp],LNG)){
		long int n = stack->val[stack->esp].LNG;
		sprintf(aux,"%ld",n);
		int size=strlen(aux);
		stack->val[stack->esp].ARR->size=size;
		stack->val[stack->esp].ARR->all_size=size+10;
		stack->val[stack->esp].ARR->array = malloc(sizeof(DADOS)*(size+10));
		stack->val[stack->esp].type=ARR;
		for(i=0;i<size;i++){
			stack->val[stack->esp].ARR->array[i].CHR=aux[i];
			stack->val[stack->esp].ARR->array[i].type=CHR;
		}
	}
	else if(hastype(stack->val[stack->esp],DOUBLE)){
		double n = stack->val[stack->esp].DOUBLE;
		sprintf(aux,"%g",n);
		int size = strlen(aux);
		stack->val[stack->esp].ARR->size=size;
		stack->val[stack->esp].ARR->all_size=size+10;
		stack->val[stack->esp].ARR->array = malloc(sizeof(DADOS)*(size+10));
		stack->val[stack->esp].type=ARR;
		for(i=0;i<size;i++){
			stack->val[stack->esp].ARR->array[i].CHR=aux[i];
			stack->val[stack->esp].ARR->array[i].type=CHR;
		}
	}
	else if(hastype(stack->val[stack->esp],CHR)){
		char c = stack->val[stack->esp].CHR;
		stack->val[stack->esp].ARR->size=1;
		stack->val[stack->esp].ARR->all_size=1+10;
		stack->val[stack->esp].ARR->array = malloc(sizeof(DADOS)*(1+10));
		stack->val[stack->esp].type=ARR;
		stack->val[stack->esp].ARR->array[0].CHR = c;
		stack->val[stack->esp].ARR->array[0].type = CHR;
	}
	else{
		stack->val[stack->esp].ARR = tmp;
	}
	return 1;
}
