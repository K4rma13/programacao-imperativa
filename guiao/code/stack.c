#include "stack.h"

#define OP_STACK(_name, _type)						\
	void push_##_name(STCK* stack, _type value){	\
		stack->esp++;								\
		stack->val[stack->esp]._name=value;			\
		stack->val[stack->esp].type = _name;		\
	}												\
	_type pop_##_name(STCK* stack){					\
		_type value = stack->val[stack->esp]._name;	\
		stack->esp--;								\
		return value;								\
	}												\

/*
#define PACK_DATA(_name,_type)			\
	DADOS pack_##_name(_type val){		\
		DADOS dado;						\
		dado.type = _name;				\
		dado._name = val;				\
		return dado;					\
	}									\
*/

OP_STACK(LNG,long int);
OP_STACK(CHR,char);
OP_STACK(DOUBLE,double);

void push_STR(STCK* stack, char* value){
	stack->esp++;
	stack->val[stack->esp].STR = malloc(500);
	strcpy(stack->val[stack->esp].STR,value);		
	stack->val[stack->esp].type = STR;
}												
char* pop_STR(STCK* stack){					
	char* value = stack->val[stack->esp].STR;	
	stack->esp--;								
	return value;
}

//PACK_DATA(LNG, long int);
//PACK_DATA(DOUBLE, double);

bool hastype(DADOS dado, TYPE tipo){
	return dado.type == tipo;
}

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
			printf("%f",stack.val[i].DOUBLE);
		}
	}
}

bool isdecimal(char* token){
	int i;
	for(i=0;token[i]!='\0';i++){
		if(token[i]=='.'){
			return true;
		}
	}
	return false;
}

int lestring(STCK* stack, char* token){
	if(strcmp(token,"l")==0){
		char tmp[999];
		fgets(tmp, sizeof(tmp), stdin);
		tmp[strlen(tmp)-1]='\0';
		push_STR(stack, tmp);
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

int valor_Double(STCK* stack, char* token){
	if(isdecimal(token)){
		push_DOUBLE(stack,atof(token));
		return 1;
	}
	return 0;
}


int stringToDouble(STCK* stack, char* token){
	if(strcmp(token,"f")==0){
		stack->val[stack->esp].DOUBLE = atof(stack->val[stack->esp].STR);
		stack->val[stack->esp].type = DOUBLE;
		free(stack->val[stack->esp].STR);
		return 1;
	}
	return 0;
}
int stringToLNG(STCK* stack, char* token){
	if(strcmp(token,"i")==0){
		stack->val[stack->esp].LNG = atoi(stack->val[stack->esp].STR);
		stack->val[stack->esp].type = LNG;
		free(stack->val[stack->esp].STR);
		return 1;
	}
	return 0;
}
int longToCHR(STCK* stack, char* token){
	if(strcmp(token,"c")==0){
		stack->val[stack->esp].CHR = stack->val[stack->esp].LNG;
		stack->val[stack->esp].type = CHR;
		return 1;
	}
	return 0;
}


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

int trocar(STCK* stack, char* token){
	if(strcmp(token,"\\")==0){
		DADOS a = stack->val[stack->esp], b = stack->val[stack->esp-1];
		stack->val[stack->esp] = b;
		stack->val[stack->esp-1] = a;
		return 1;
	}
	return 0;
}

int duplicar(STCK* stack, char* token){
	if(strcmp(token,"_")==0){
		DADOS a = stack->val[stack->esp];
		stack->esp++;
		stack->val[stack->esp] = a;
		return 1;
	}
	return 0;
}

int removeTop(STCK* stack, char* token){
	if(strcmp(token,";")==0){
		stack->esp--;
		return 1;
	}
	return 0;
}
