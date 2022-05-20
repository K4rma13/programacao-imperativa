/**
 *@file Ficheiro que contem as funçoes logicas
 *
 */
#include "logic.h" 
/**
 * \def OPERATION_SGN(_name,_sinal)
 * Cria funcoes que aplicam comparaçoes ( \a _sinal ) entre a e b do tipo DADOS
 */

#define OPERATION_SGN(_name,_sinal)                                             \
	bool OP_##_name(DADOS b,DADOS a){                                           \
		if(hastype(a,CHR)){														\
			if(hastype(b,CHR)){													\
				return a.CHR _sinal b.CHR;										\
			}																	\
			else if(hastype(b,DOUBLE)){											\
				return a.CHR _sinal b.DOUBLE; 									\
			}																	\
			else{																\
				return a.CHR _sinal b.LNG;										\
			}																	\
		}																		\
		else if(hastype(b,CHR)){												\
			if(hastype(a,LNG)){													\
				return a.LNG _sinal b.CHR;										\
			}																	\
			else{																\
				return a.DOUBLE _sinal b.CHR;									\
			}																	\
		}																		\
		else if(hastype(a,DOUBLE)){                                             \
			if(hastype(b,DOUBLE)){                                              \
				return a.DOUBLE _sinal b.DOUBLE;                                \
			}                                                                   \
			else{                                                               \
				return a.DOUBLE _sinal b.LNG;                                   \
			}                                                                   \
		}                                                                       \
		else if(hastype(b,DOUBLE)){                                             \
			return a.LNG _sinal b.DOUBLE;                                       \
		}                                                                       \
		else{                                                                   \
			return a.LNG _sinal b.LNG;                                          \
		}                                                                       \
	}                                                                           \

OPERATION_SGN(EQUAL,==)
OPERATION_SGN(SMALL,<)
OPERATION_SGN(BIG,>)



/**
 * \brief Esta funcao faz a comparacao entre o valor do topo da stack com 0 
 * @param DADOS Recebe um valor do tipo dados
 * @returns Retorna False se o valor for igual a zero e True caso contrario
 */
bool OP_FALSE(DADOS a){   
	if(hastype(a,DOUBLE)){                  
		return a.DOUBLE == 0; 
	}
	else if(hastype(a,ARR)){
		return a.ARR->size == 0;
	}
	else if(hastype(a,CHR)){
		return a.CHR == 0;
	}
	else{       
		return a.LNG == 0;    
	}                   
}

/**
 * \brief Esta funcao faz a comparacao entre os 2 valores do topo da stack com 0 
 * @param DADOS Recebe um valor do tipo dados
 * @param DADOS Recebe um valor do tipo dados
 * @returns Retorna True se ambos os valores forem diferentes a zero caso contrario False
 */
bool OP_TRUE(DADOS b,DADOS a){    
	return (!OP_FALSE(a))&&(!OP_FALSE(b));                 
}

/**
 * \brief Esta funcao faz a comparacao entre os 2 valores do topo da stack com 0 
 * @param DADOS Recebe um valor do tipo dados
 * @param DADOS Recebe um valor do tipo dados
 * @returns Retorna True se um dos dois valores for igual a 0
 */
bool OP_veryFALSE(DADOS b,DADOS a){   
	return (!OP_FALSE(a))||(!OP_FALSE(b));
}

/**
 * \brief Esta funcao nega o valor logico do elemento do topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */

int isFalse(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	long int val = OP_FALSE(stack->val[stack->esp]) ? 1 : 0;
	stack->esp--;
	push_LNG(stack,val);
	return 1;
}

/**
 * \brief Esta funcao verifica se os dois valores do topo da stack sao iguais se sim coloca 1 no topo da stack senao coloca 0
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */

int isEqual(STCK* stack, char* token){
	if(strcmp(token,"=")==0){
		long int val;
		val = OP_EQUAL(stack->val[stack->esp],stack->val[stack->esp-1]) ? 1 : 0;
		stack->esp-=2;
		push_LNG(stack,val);
		return 1;
	}
	return 0;
}
/**
 * \brief Esta funcao verifica se o segundo valor do topo da stack e menor que o primeiro se sim coloca 1 no topo da stack senao coloca 0
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int isSmall(STCK* stack, char* token){
	if(strcmp(token,"<")==0){
		long int val;
		val = OP_SMALL(stack->val[stack->esp],stack->val[stack->esp-1]) ? 1 : 0;
		stack->esp-=2;
		push_LNG(stack,val);
		return 1;
	}
	return 0;
}

/**
 * \brief Esta funcao verifica se o segundo valor do topo da stack e maior que o primeiro se sim coloca 1 no topo da stack senao coloca 0
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */

int isBig(STCK* stack,char* token){
	if((int)token[0]==0){printf("Erro");}
	long int val;
	val = OP_BIG(stack->val[stack->esp],stack->val[stack->esp-1]) ? 1 : 0;
	stack->esp-=2;
	push_LNG(stack,val);
	return 1;
}
/**
 * \brief Esta funcao verifica se o terceiro valor do topo da stack é zero se nao for coloca no topo da stack o segundo valor, caso contrario coloca no topo da stack o primeiro valor
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */

int ifThenElse(STCK* stack,char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp-2],ARR)){
		DADOS tmp = stack->val[stack->esp-2].ARR->size ? tmp=stack->val[stack->esp-1] : stack->val[stack->esp];
		stack->esp-=2;
		stack->val[stack->esp]=tmp;
	}
	else{
		DADOS tmp = !OP_FALSE(stack->val[stack->esp-2]) ? tmp=stack->val[stack->esp-1] : stack->val[stack->esp];
		stack->esp-=2;
		stack->val[stack->esp]=tmp;
	}
	
	return 1;
}

/**
 * \brief Esta funcao faz um AND(shortcut) com os 2 valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int logicalAnd(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		DADOS zero;
		zero.type=LNG;
		zero.LNG=0;
		zero.DOUBLE=0;
		zero.CHR=0;
		zero.ARR = malloc(sizeof(struct ARR));
		zero.ARR->size=0;
		zero.ARR->all_size=0;
		zero.ARR->array=NULL;
		DADOS val;
		val=zero;
		val = OP_TRUE(stack->val[stack->esp],stack->val[stack->esp-1]) ? (OP_SMALL(stack->val[stack->esp-1],stack->val[stack->esp]) ? stack->val[stack->esp-1] : stack->val[stack->esp]) : zero;
		stack->esp--;
		stack->val[stack->esp]=val;
		return 1;
}

/**
 * \brief Esta funcao faz um OR(shortcut) com os 2 valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int logicalOr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		DADOS zero;
		zero.type=LNG;
		zero.LNG=0;
		zero.DOUBLE=0;
		zero.CHR=0;
		zero.ARR = malloc(sizeof(struct ARR));
		zero.ARR->size=0;
		zero.ARR->all_size=0;
		zero.ARR->array=NULL;
		DADOS val;
		if(OP_FALSE(stack->val[stack->esp-1])&&OP_FALSE(stack->val[stack->esp])){
			val = zero;
		}
		else if(!OP_FALSE(stack->val[stack->esp-1])){
			val = stack->val[stack->esp-1];
		}
		else{
			val = stack->val[stack->esp];
		}
		stack->esp--;
		stack->val[stack->esp]=val;
		return 1;
}

/**
 * \brief Esta funcao analisa os dois valores do topo da stack e coloca o maior deles no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int logicalGreater(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	DADOS val;
	if(hastype(stack->val[stack->esp],ARR)){
		int idk = grStr(stack);
		if(idk==0){
			trocar(stack,token);
		}
	}
	else{
		val = OP_SMALL(stack->val[stack->esp],stack->val[stack->esp-1]) ? stack->val[stack->esp] : stack->val[stack->esp-1];
		
		stack->val[stack->esp-1]=val;
	}
	stack->esp--;
	return 1;
}

/**
 * \brief Esta funcao analisa os dois valores do topo da stack e coloca o menor deles no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int logicalLess(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
		DADOS val;
		if(hastype(stack->val[stack->esp],ARR)){
			int idk = lStr(stack);
			if(idk==0){
				trocar(stack,token);
			}
		}
		else{
			val = OP_BIG(stack->val[stack->esp],stack->val[stack->esp-1]) ? stack->val[stack->esp] : stack->val[stack->esp-1];
			stack->val[stack->esp-1]=val;
		}
		stack->esp--;
		
		return 1;
}