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
 * \brief Esta função da push a uma variavel do tipo string
 * @param stack A stack
 * @param value Valor a colocado no topo da stack
 */

void push_STR(STCK* stack, char* value){
	stack->esp++;
	stack->val[stack->esp].STR = malloc(500);
	strcpy(stack->val[stack->esp].STR,value);		
	stack->val[stack->esp].type = STR;
}
/**			
 * \brief Esta função da pop a uma variavel do tipo string 	
 * @param stack A stack 									
 * @returns O valor no topo da stack 						
 */	

char* pop_STR(STCK* stack){					
	char* value = stack->val[stack->esp].STR;	
	stack->esp--;								
	return value;
}

/**			
 * \brief Ve se o tipo do dado é o mesmo do tipo fornecido 	
 * @param dado O Dado a ser comparado
 * @param tipo O Tipo a ser testado
 * @returns true se o dado tiver o mesmo tipo ou caso contrario false						
 */	

bool hastype(DADOS dado, TYPE tipo){
	return dado.type == tipo;
}

void printArr(struct ARR stack){
	for(int i=0;i<stack.size;i++){
		if(hastype(stack.array[i],CHR)){
			printf("%c",stack.array[i].CHR);
		}
		else if(hastype(stack.array[i],LNG)){
			printf("%ld",stack.array[i].LNG);
		}
		else if(hastype(stack.array[i],STR)){
			printf("%s",stack.array[i].STR);
		}
		else if(hastype(stack.array[i],DOUBLE)){
			printf("%g",stack.array[i].DOUBLE);
		}
		else{
			printArr(stack.array[i].ARR);
		}
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
		else if(hastype(stack->val[i],STR)){
			printf("%s",stack->val[i].STR);
		}
		else if(hastype(stack->val[i],DOUBLE)){
			printf("%g",stack->val[i].DOUBLE);
		}
		else{
			printArr(stack->val[i].ARR);
		}
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
	else if(hastype(stack->val[stack->esp],STR)){
		printf("%s",stack->val[stack->esp].STR);
	}
	else if(hastype(stack->val[stack->esp],DOUBLE)){
		printf("%g",stack->val[stack->esp].DOUBLE);
	}
	else{
		printArr(stack->val[stack->esp].ARR);
	}
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
 * \brief Esta funcao le uma string do stdin e faz push
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int lestring(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		char tmp[999];
		if(fgets(tmp, sizeof(tmp), stdin)!=NULL){
			tmp[strlen(tmp)-1]='\0';
			push_STR(stack, tmp);
		}
		return 1;
}


/**
 * \brief Esta funcao adiciona valores no topo da stack
 * @returns Retorna 1
 * @param stack A stack
 * @param token Valor a ser interpretado
 */
int valor(STCK* stack, char* token){
	push_LNG(stack,atoi(token));
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
		push_DOUBLE(stack,atof(token));
		return 1;
	}
	return 0;
}

void strToDouble(STCK* stack){
	int s=stack->val[stack->esp].ARR.size,i;
	char aux[s];
	for(i=0;i<s;i++){
		aux[i]=stack->val[stack->esp].ARR.array[i].CHR;
	}
	stack->val[stack->esp].DOUBLE=atof(aux);
	stack->val[stack->esp].type=DOUBLE;
}

void strToLng(STCK* stack){
	int s=stack->val[stack->esp].ARR.size,i;
	char aux[s];
	for(i=0;i<s;i++){
		aux[i]=stack->val[stack->esp].ARR.array[i].CHR;
	}
	aux[i]='\0';
	stack->val[stack->esp].LNG=atoi(aux);
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

int longToCHR(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		stack->val[stack->esp].CHR = stack->val[stack->esp].LNG;
		stack->val[stack->esp].type = CHR;
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
		long int index = pop_LNG(stack);
		DADOS data = stack->val[stack->esp-index];
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
		DADOS a = stack->val[stack->esp];
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
	long int n = stack->val[stack->esp].LNG;
	char aux[200];
	for(i=0;n!=0;i++){
		aux[i]= (char) (n % 10)+48;
		n = n / 10;
	}
	aux[i]='\0';
	stack->val[stack->esp].ARR.size=i;
	stack->val[stack->esp].ARR.all_size=i+10;
	stack->val[stack->esp].ARR.array = malloc(sizeof(DADOS)*(i+10));
	stack->val[stack->esp].type=ARR;
	i--;
	int size = i;
	for(;i>=0;i--){
		stack->val[stack->esp].ARR.array[size-i].CHR=aux[i];
		stack->val[stack->esp].ARR.array[size-i].type=CHR;
	}
	return 1;
}
