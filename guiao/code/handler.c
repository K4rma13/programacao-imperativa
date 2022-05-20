#include "handler.h"

/**
 * \brief Esta funcao auxiliar le uma linha que contem uma string que comeca e acaba com um '"' e separa-a
 * @param buf Linha que contem uma string
 * @param aux String interpretada
 */
int stringParser(char* buf, char* aux){
	int n;
	if(*(buf+1)=='"'){
		aux[0]='"';
		aux[1]='"';
		aux[2]='\0';
		n=3;
	}
	else{
		sscanf(buf+1,"%[^\"]s",aux+1);
		aux[0]='"';
		n = strlen(aux);
		aux[n+1]='\0';
		aux[n]='"';
		n+=2;
	}
	return n;
}

/**
 * \brief Esta funcao separa a linha do input em cada uma das operaçoes e valores a serem interpretados
 * @param buf Linha com as intrucoes a serem processadas
 * @param stack A stack
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 */
void parser(char* buf,STCK* stack,DADOS* v,int (*functions[])(STCK*,char*)){
	int n,i,cont;
	char aux[100000];
	while(*buf!='\0'){
		while(*buf==' '){
			buf++;
		}
		if(*buf!='\0'){
			n=0;
			if(*buf=='"'){
				n = stringParser(buf,aux);
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
				//printf("%s AQUI CARALHO\n",aux);
			}
			buf+=n;
			//printf("||  %s  -- %s  ||\n",aux, buf);
			handler(stack,aux,v,functions);
			
			//printstack(stack);
			//printf("\n----------------\n");
		}

	}
}

/**
 * \brief Esta funcao chama a funcao apropriada para lidar com blocos
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 * @returns 1 se o token trabalhar com blocos, se nao 0
 */
int handlerBlock(STCK* stack, char* token, DADOS* v,int (*functions[])(STCK*,char*)){
	if(stack->esp>-1&&hastype(stack->val[stack->esp],BLK)){
		return (whileBlock(stack,token,v,functions) ||filterBlock(stack,token,v,functions) || ordBlock(stack,token,v,functions) || executeBlock(stack,token,v,functions)||mapBlock(stack,token,v,functions)||foldBlock(stack,token,v,functions));
	}
	return 0;
}

/**
 * \brief Esta funcao chama a funcao apropriada se o token tiver um caracter de A-Z
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @param v Variaveis A-Z
 * @returns 1 se o token tiver um caracter de A-Z, se nao 0
 */
int handlerLetras(STCK* stack, char* token, DADOS* v){
	return (splitNL(stack,token) || splitSpace(stack,token) || variablePush(stack,token,v) || variableGet(stack,token,v));
}

/**
 * \brief Esta funcao chama a funcao apropriada para lidar com o valores numericos
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for um numero, se nao 0
 */
int handlerValores(STCK* stack, char* token){
	if((token[0]=='-' && ((token[1]>='0'&& token[1]<='9')))||(token[0]>='0'&& token[0]<='9')){
		if(!(valor_Double(stack,token) || valor(stack,token))){
			printf("erro");
		}
		return 1;
	}
	return 0;
}

/**
 * \brief Esta funcao chama a funcao apropriada para lidar com o valor que esta no token
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
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

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '~'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '~', se nao 0
 */
int til(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],LNG)){
		return not(stack,token);
	}
	else{
		return arrayToStack(stack,token);
	}
	return 0;
}

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '('
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '(', se nao 0
 */
int parOpen(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)){
		return rmFirstArr(stack,token);
	}
	else{
		return decr(stack,token);
	}
}

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é ')'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for ')', se nao 0
 */
int parClose(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)){
		return rmLastArr(stack,token);
	}
	else{
		return incr(stack,token);
	}
}

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '*'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '*', se nao 0
 */
int asterisco(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)||hastype(stack->val[stack->esp-1],ARR)){
		return arrMUL(stack);
	}
	else{
		return mul(stack,token);
	}
}

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '/'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '/', se nao 0
 */
int slash(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp-1],ARR)){
		splitStr(stack,token);
	}
	else{
		return divisao(stack,token);
	}
	return 0;
}

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '+'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '+', se nao 0
 */
int plus(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)||hastype(stack->val[stack->esp-1],ARR)){
		return arrADD(stack);
	}
	else if(hastype(stack->val[stack->esp],CHR)&&hastype(stack->val[stack->esp-1],CHR)){
		return charToArray(stack);
	}
	else{
		return add(stack,token);
	}
}

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '#'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '#', se nao 0
 */
int hastag(STCK* stack, char* token){
	if(hastype(stack->val[stack->esp],ARR)||hastype(stack->val[stack->esp],CHR)){
		return findArr(stack,token);
	}
	else{
		return potencia(stack,token);
	}
}

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '='
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '=', se nao 0
 */
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

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '<'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '<', se nao 0
 */
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

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '>'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '>', se nao 0
 */
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