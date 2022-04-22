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

/**			
 * \brief Imprime para o stdout a stack fornecida
 * @param stack A stack
 */

void printstack(STCK stack){
	for(int i=0;i<=stack.esp;i++){
		if(hastype(stack.val[i],CHR)){
			printf("%c",stack.val[i].CHR);
		}
		else if(hastype(stack.val[i],LNG)){
			printf("%ld",stack.val[i].LNG);
		}
		else if(hastype(stack.val[i],STR)){
			printf("%s",stack.val[i].STR);
		}
		else if(hastype(stack.val[i],DOUBLE)){
			printf("%g",stack.val[i].DOUBLE);
		}
	}
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
	if(strcmp(token,"l")==0){
		char tmp[999];
		if(fgets(tmp, sizeof(tmp), stdin)!=NULL){
			tmp[strlen(tmp)-1]='\0';
			push_STR(stack, tmp);
		}
		return 1;
	}
	return 0;
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

/**
 * \brief Esta funcao muda o tipo da variavel no topo da stack para DOUBLE
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int toDouble(STCK* stack, char* token){
	if(strcmp(token,"f")==0){
		if(hastype(stack->val[stack->esp],STR)){
			stack->val[stack->esp].DOUBLE = atof(stack->val[stack->esp].STR);
			free(stack->val[stack->esp].STR);
		}
		else if(hastype(stack->val[stack->esp],LNG)){
			stack->val[stack->esp].DOUBLE = (double)stack->val[stack->esp].LNG;
		}
		stack->val[stack->esp].type = DOUBLE;
		return 1;
	}
	return 0;
}

/**
 * \brief Esta funcao muda o tipo da variavel no topo da stack para LONG
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int toLNG(STCK* stack, char* token){
	if(strcmp(token,"i")==0){
		if(hastype(stack->val[stack->esp],STR)){
			stack->val[stack->esp].LNG = atoi(stack->val[stack->esp].STR);
			free(stack->val[stack->esp].STR);
		}
		else if(hastype(stack->val[stack->esp],DOUBLE)){
			stack->val[stack->esp].LNG = (long int)stack->val[stack->esp].DOUBLE;
		}
		stack->val[stack->esp].type = LNG;
		return 1;
	}
	return 0;
}

/**
 * \brief Esta funcao muda o tipo da variavel no topo da stack de LONG para CHAR
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int longToCHR(STCK* stack, char* token){
	if(strcmp(token,"c")==0){
		stack->val[stack->esp].CHR = stack->val[stack->esp].LNG;
		stack->val[stack->esp].type = CHR;
		return 1;
	}
	return 0;
}

/**
 * \brief Esta funcao faz push a uma copia do valor na nºesima posicao
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int cpyStack(STCK* stack, char* token){
	if(strcmp(token,"$")==0){
		long int index = pop_LNG(stack);
		DADOS data = stack->val[stack->esp-index];
		stack->esp++;
		stack->val[stack->esp] = data;
		return 1;
	}
	return 0;
}

 /**
 * \brief Esta funcao roda os 3 elementos no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int rodar(STCK* stack, char* token){
	if(strcmp(token,"@")==0){
		DADOS a = stack->val[stack->esp], b = stack->val[stack->esp-1], c = stack->val[stack->esp-2];
		stack->val[stack->esp] = c;
		stack->val[stack->esp-1] = a;
		stack->val[stack->esp-2] = b;
		return 1;
	}
	return 0;
}

/**
 * \brief Esta funcao troca os 2 valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int trocar(STCK* stack, char* token){
	if(strcmp(token,"\\")==0){
		DADOS a = stack->val[stack->esp], b = stack->val[stack->esp-1];
		stack->val[stack->esp] = b;
		stack->val[stack->esp-1] = a;
		return 1;
	}
	return 0;
}

/**
 * \brief Esta funcao faz push a uma copia do valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int duplicar(STCK* stack, char* token){
	if(strcmp(token,"_")==0){
		DADOS a = stack->val[stack->esp];
		stack->esp++;
		stack->val[stack->esp] = a;
		return 1;
	}
	return 0;
}

/**
 * \brief Esta funcao faz ""Pop""
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int removeTop(STCK* stack, char* token){
	if(strcmp(token,";")==0){
		stack->esp--;
		return 1;
	}
	return 0;
}
