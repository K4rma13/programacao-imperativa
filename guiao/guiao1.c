#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct STCK{
	int val[50];
	int esp;
}STCK;

int potencia(STCK* stack, char* token){
	if(strcmp(token,"#")==0){
		stack->val[stack->esp-1]=pow(stack->val[stack->esp-1],stack->val[stack->esp]);
		stack->esp--;
		return 1;
	}
	return 0;
}
int add(STCK* stack, char* token){
	if(strcmp(token,"+")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]+stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
int sub(STCK* stack, char* token){
	if(strcmp(token,"-")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]-stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
int divisao(STCK* stack, char* token){
	if(strcmp(token,"/")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]/stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
int mul(STCK* stack, char* token){
	if(strcmp(token,"*")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]*stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
int incr(STCK* stack, char* token){
	if(strcmp(token,")")==0){
		stack->val[stack->esp]++;
		return 1;
	}
	return 0;
}
int decr(STCK* stack, char* token){
	if(strcmp(token,"(")==0){
		stack->val[stack->esp]--;
		return 1;
	}
	return 0;
}
int module(STCK* stack, char* token){
	if(strcmp(token,"%")==0){
		if(stack->val[stack->esp]<0){
			stack->val[stack->esp]*=-1;
		}
		return 1;
	}
	return 0;
}
int and(STCK* stack, char* token){
	if(strcmp(token,"&")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]&stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
int or(STCK* stack, char* token){
	if(strcmp(token,"|")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]|stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
int xor(STCK* stack, char* token){
	if(strcmp(token,"^")==0){
		stack->val[stack->esp-1]=stack->val[stack->esp-1]^stack->val[stack->esp];
		stack->esp--;
		return 1;
	}
	return 0;
}
int not(STCK* stack, char* token){
	if(strcmp(token,"~")==0){
		stack->val[stack->esp]= ~stack->val[stack->esp];
		return 1;
	}
	return 0;
}


int valor(STCK* stack, char* token){
	stack->esp++;
	stack->val[stack->esp]=atoi(token); 
	return 1;
}

void handler(STCK* stack, char* token){
	potencia(stack,token) || add(stack,token) || sub(stack,token) || mul(stack,token) || 
	incr(stack,token) || decr(stack,token) || divisao(stack,token) || module(stack,token)||
	and(stack,token) || or(stack,token) || xor(stack,token) || not(stack,token) || valor(stack,token);
}


int main(){
	STCK stack;
	stack.esp=-1;
	int n=0;

	char buffer[200], aux[10],*b;
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer)-1]='\0';
	b=buffer;
	while(*b!='\0'){
		sscanf(b,"%s %n",aux,&n);
		b+=n;
		handler(&stack,aux);
	}
	for(int i=stack.esp;i>=0;i--){
		printf("+-----------+\n");
		printf("| %5d     |\n",stack.val[i]);
	}
	printf("+-----------+\n");
	return 0;
}
