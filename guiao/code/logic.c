#include "logic.h"

#define OPERATION_SGN(_name,_sinal)				\
	bool OP_##_name(DADOS b,DADOS a){		\
		if(hastype(a,DOUBLE)){					\
			if(hastype(b,DOUBLE)){				\
				return a.DOUBLE _sinal b.DOUBLE;\
			}									\
			else{								\
				return a.DOUBLE _sinal b.LNG;	\
			}									\
		}										\
		else if(hastype(b,DOUBLE)){				\
			return a.LNG _sinal b.DOUBLE;		\
		}										\
		else{									\
			return a.LNG _sinal b.LNG;			\
		}										\
	}											\

OPERATION_SGN(EQUAL,==)
OPERATION_SGN(SMALL,<)
OPERATION_SGN(BIG,>)
bool OP_FALSE(DADOS a){		
	if(hastype(a,DOUBLE)){									
		return a.DOUBLE == 0;	
	}									
	else{				
		return a.LNG == 0;		
	}										
}

bool OP_TRUE(DADOS b,DADOS a){		
	if(hastype(a,DOUBLE)){					
		if(hastype(b,DOUBLE)){				
			return a.DOUBLE !=0 && b.DOUBLE !=0;
		}									
		else{								
			return a.DOUBLE !=0 && b.LNG != 0;	
		}									
	}										
	else if(hastype(b,DOUBLE)){				
		return a.LNG !=0 && b.DOUBLE != 0;		
	}										
	else{									
		return a.LNG !=0 && b.LNG != 0;			
	}										
}

bool OP_veryFALSE(DADOS b,DADOS a){		
	if(hastype(a,DOUBLE)){					
		if(hastype(b,DOUBLE)){				
			return a.DOUBLE !=0 || b.DOUBLE !=0;
		}									
		else{								
			return a.DOUBLE !=0 || b.LNG != 0;	
		}									
	}										
	else if(hastype(b,DOUBLE)){				
		return a.LNG !=0 || b.DOUBLE != 0;		
	}										
	else{									
		return a.LNG !=0 || b.LNG != 0;			
	}										
}



int isFalse(STCK* stack, char* token){
	if(strcmp(token,"!")==0){
		if(hastype(stack->val[stack->esp],LNG)){
			long int val = OP_FALSE(stack->val[stack->esp]) ? 1 : 0;
			stack->esp--;
			push_LNG(stack,val);
		}
		else if(hastype(stack->val[stack->esp],DOUBLE)){
			long int val = OP_FALSE(stack->val[stack->esp]) ? 1 : 0;
			stack->esp--;
			push_LNG(stack,val);
		}
		else{
			long int val = OP_FALSE(stack->val[stack->esp]) ? 1 : 0;
			stack->esp--;
			push_LNG(stack,val);
		}
		return 1;
	}
	return 0;
}

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


int isBig(STCK* stack,char* token){
	if(strcmp(token,">")==0){
		long int val;
		val = OP_BIG(stack->val[stack->esp],stack->val[stack->esp-1]) ? 1 : 0;
		stack->esp-=2;
		push_LNG(stack,val);
		return 1;
	}
	return 0;
}

int ifThenElse(STCK* stack,char* token){
	if(strcmp(token,"?")==0){
		DADOS tmp = !OP_FALSE(stack->val[stack->esp-2]) ? tmp=stack->val[stack->esp-1] : stack->val[stack->esp];
		stack->esp-=2;
		stack->val[stack->esp]=tmp;
		return 1;
	}
	return 0;
}

int logicalAnd(STCK* stack, char* token){
	if(strcmp(token,"e&")==0){
		DADOS zero;
		zero.type=LNG;
		zero.LNG=0;
		zero.DOUBLE=0;
		zero.CHR=0;
		zero.STR=NULL;
		DADOS val;
		val = OP_TRUE(stack->val[stack->esp],stack->val[stack->esp-1]) ? (OP_SMALL(stack->val[stack->esp-1],stack->val[stack->esp]) ? stack->val[stack->esp-1] : stack->val[stack->esp]) : zero;
		stack->esp--;
		stack->val[stack->esp]=val;
		return 1;
	}
	return 0;
}

int logicalOr(STCK* stack, char* token){
	if(strcmp(token,"e|")==0){
		DADOS zero;
		zero.type=LNG;
		zero.LNG=0;
		zero.DOUBLE=0;
		zero.CHR=0;
		zero.STR=NULL;
		DADOS val;
		val = OP_veryFALSE(stack->val[stack->esp],stack->val[stack->esp-1]) ? (OP_SMALL(stack->val[stack->esp-1],stack->val[stack->esp]) ? stack->val[stack->esp-1] : stack->val[stack->esp]) : zero;
		stack->esp--;
		stack->val[stack->esp]=val;
		return 1;
	}
	return 0;
}

int logicalGreater(STCK* stack, char* token){
	if(strcmp(token,"e>")==0){
		DADOS val;
		val = OP_SMALL(stack->val[stack->esp],stack->val[stack->esp-1]) ? stack->val[stack->esp] : stack->val[stack->esp-1];
		stack->esp--;
		stack->val[stack->esp]=val;
		return 1;
	}
	return 0;
}

int logicalLess(STCK* stack, char* token){
	if(strcmp(token,"e<")==0){
		DADOS val;
		val = OP_BIG(stack->val[stack->esp],stack->val[stack->esp-1]) ? stack->val[stack->esp] : stack->val[stack->esp-1];
		stack->esp--;
		stack->val[stack->esp]=val;
		return 1;
	}
	return 0;
}
