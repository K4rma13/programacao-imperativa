#include "handler.h"

void parser(char* buf,STCK* stack,DADOS* v,int (*functions[])(STCK*,char*)){
	int n,i,cont;
	char aux[100];
	while(*buf!='\0'){
		while(*buf==' '){
			buf++;
		}
		n=0;
		if(*buf=='"'){
			sscanf(buf+1,"%[^\"]s",aux+1);
			aux[0]='"';
			n = strlen(aux);
			aux[n+1]='\0';
			aux[n]='"';
			n+=2;
		}
		else if(*buf=='{'){
			cont=1;
			for(i=1;cont!=0;i++){
				aux[i]=buf[i];
				if(buf[i]=='}'){
					cont--;
				}
				if(buf[i]=='{'){
					cont++;
				}
			}
			aux[0]='{';
			aux[i]='\0';
			n=i+1;
		}
		else{
			sscanf(buf,"%s %n",aux,&n);
		}
		buf+=n;
		
		handler(stack,aux,v,functions);
		printf("||  %s  -- %s  ||\n",aux, buf);
		printstack(stack);
		printf("\n----------------\n");

	}
}

int handlerBlock(STCK* stack, char* token, DADOS* v,int (*functions[])(STCK*,char*)){
	if(stack->esp>-1&&hastype(stack->val[stack->esp],BLK)){
		return (executeBlock(stack,token,v,functions)||mapBlock(stack,token,v,functions)||foldBlock(stack,token,v,functions));
	}
	return 0;
}

int handlerLetras(STCK* stack, char* token, DADOS* v){
	return (splitNL(stack,token) || splitSpace(stack,token) || variablePush(stack,token,v) || variableGet(stack,token,v));
}

int handlerValores(STCK* stack, char* token){
	if((token[0]=='-' && (token[1]>='0'&& token[1]<='9'))||(token[0]>='0'&& token[0]<='9')){
		if(!(valor_Double(stack,token) || valor(stack,token))){
			printf("erro");
		}
		return 1;
	}
	return 0;
}

/**
 * \brief Esta funcao decide qual é a funcao que deve ser executada dependendo do valor que foi lido do input
 * @param stack A stack
 * @param token Valor a ser interpretado
 */
void handler(STCK* stack, char* token, DADOS* v,int (*functions[])(STCK*,char*)){
	if(token[0]=='e'){
		functions[127+token[1]](stack,token);
	}
	else{
		if(!(handlerBlock(stack,token,v,functions)|| handlerValores(stack,token) || handlerLetras(stack,token,v))){
			functions[(int)token[0]](stack,token);
		}
	}
}

int til(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],LNG)){
		return not(stack,token);
	}
	else if(hastype(stack->val[stack->esp],ARR)){
		return arrayToStack(stack,token);
	}
	return 0;
}

int parOpen(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)){
		return rmFirstArr(stack,token);
	}
	else{
		return decr(stack,token);
	}
}

int parClose(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)){
		return rmLastArr(stack,token);
	}
	else{
		return incr(stack,token);
	}
}

int asterisco(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)||hastype(stack->val[stack->esp-1],ARR)){
		return arrMUL(stack);
	}
	else{
		return mul(stack,token);
	}
}

int slash(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)){
		splitStr(stack,token);
	}
	else{
		return divisao(stack,token);
	}
}

int plus(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)||hastype(stack->val[stack->esp-1],ARR)){
		return arrADD(stack);
	}
	else{
		return add(stack,token);
	}
}

int hastag(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)){
		return findArr(stack,token);
	}
	else{
		return potencia(stack,token);
	}
}

int equal(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp-1],ARR)&&hastype(stack->val[stack->esp],ARR)){
		return cmpString(stack);
	}
	else if(hastype(stack->val[stack->esp-1],ARR)){
		return indexArr(stack,token);
	}
	else{
		return isEqual(stack,token);
	}
}

int lessSign(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp-1],ARR)&&hastype(stack->val[stack->esp],ARR)){
		return lesserString(stack);
	}
	else if(hastype(stack->val[stack->esp-1],ARR)){
		return firstArray(stack,token);
	}
	else{
		return isSmall(stack,token);
	}
}

int greaterSign(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp-1],ARR)&&hastype(stack->val[stack->esp],ARR)){
		return greaterString(stack);
	}
	else if(hastype(stack->val[stack->esp-1],ARR)){
		return lastArray(stack,token);
	}
	else{
		return isBig(stack,token);
	}
}