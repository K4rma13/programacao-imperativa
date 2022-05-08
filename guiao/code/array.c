#include "array.h"

int enumerate(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp],ARR)){
		stack->val[stack->esp].LNG=stack->val[stack->esp].ARR.size;
		stack->val[stack->esp].type=LNG;
	}
	else{
		int i;
		long int max = stack->val[stack->esp].LNG;
		struct ARR arr;
		arr.size = max;
		arr.all_size = max+10;
		arr.array = malloc(sizeof(DADOS)*arr.all_size);
		for(i=0;i < max;i++){
			arr.array[i].LNG=i;
			arr.array[i].type=LNG;
		}
		stack->val[stack->esp].ARR=arr;
		stack->val[stack->esp].type=ARR;
	}
	return 1;
}

int lastArray(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	struct ARR arr;
	arr.size = stack->val[stack->esp].LNG;
	arr.all_size = arr.size+10;
	arr.array = malloc(sizeof(DADOS)*arr.all_size);
	int m = stack->val[stack->esp-1].ARR.size-arr.size;
	int i;
	for(i=0; i < arr.size;i++){
		arr.array[i]=stack->val[stack->esp-1].ARR.array[i+m];
	}
	stack->esp--;
	stack->val[stack->esp].ARR = arr;
	return 1;
}

int firstArray(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	struct ARR arr;
	arr.size = stack->val[stack->esp].LNG;
	arr.all_size = arr.size+10;
	arr.array = malloc(sizeof(DADOS)*arr.all_size);
	int i;
	for(i=0; i < arr.size;i++){
		arr.array[i]=stack->val[stack->esp-1].ARR.array[i];
	}
	stack->esp--;
	stack->val[stack->esp].ARR = arr;
	return 1;
}


int initArr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	stack->esp++;
	stack->val[stack->esp].type = CHR;
	stack->val[stack->esp].CHR = '[';
	return 1;
}

int closeArr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	int i,cont=0;
	for(i=stack->esp;stack->val[i].CHR!='[';i--){
		cont++;
	}
	stack->val[i].CHR=0;
	DADOS *array = malloc(sizeof(DADOS)*(cont+10));
	for(i=0;i<cont;i++){
		array[i]=stack->val[stack->esp-cont+1+i];
	}
	stack->esp-=cont;
	stack->val[stack->esp].ARR.array = array;
	stack->val[stack->esp].ARR.all_size = cont+10;
	stack->val[stack->esp].ARR.size = cont;
	stack->val[stack->esp].type = ARR;
	return 1;
}

int initString(STCK* stack, char* token){
	int cont=1,i;
	for(i=1;token[i]!='"';i++){
		cont++;
	}
	DADOS *array = malloc(sizeof(DADOS)*(cont+10));
	for(i=1;token[i]!='"';i++){
		array[i-1].CHR=token[i];
		array[i-1].type=CHR;
	}
	stack->esp++;
	stack->val[stack->esp].ARR.array = array;
	stack->val[stack->esp].ARR.all_size = cont+10;
	stack->val[stack->esp].ARR.size = cont-1;
	stack->val[stack->esp].type = ARR;
	return 1;
}

int indexArr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	long int ind = stack->val[stack->esp].LNG;
	stack->esp--;
	stack->val[stack->esp]=stack->val[stack->esp].ARR.array[ind];
	return 1;
}

int arrayToStack(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	int i;
	int s = stack->val[stack->esp].ARR.size;
	DADOS *array= stack->val[stack->esp].ARR.array;
	for(i=0; i<s;i++){
		stack->val[stack->esp] = array[i];
		stack->esp++;
	}
	stack->esp--;
	return 1;
}

int rmLastArr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	stack->val[stack->esp].ARR.size--;
	DADOS last = stack->val[stack->esp].ARR.array[stack->val[stack->esp].ARR.size];
	stack->esp++;
	stack->val[stack->esp] = last;
	return 1;
}
int rmFirstArr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	DADOS first = stack->val[stack->esp].ARR.array[0];
	int i;
	for(i=0;i<stack->val[stack->esp].ARR.size;i++){
		stack->val[stack->esp].ARR.array[i]=stack->val[stack->esp].ARR.array[i+1];
	}
	stack->val[stack->esp].ARR.size--;
	stack->esp++;
	stack->val[stack->esp] = first;
	return 1;
}

int findArr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	struct ARR string = stack->val[stack->esp-1].ARR;
	struct ARR substr = stack->val[stack->esp].ARR;
	int i, cont = 0, first=0;
	long int r=-1;
	for(i=0; i<string.size;i++){
		if(string.array[i].CHR==substr.array[cont].CHR){
			cont++;
			if(substr.size==cont&&first==0){
				r= i-cont+1;
				first=1;
			}
		}
		else{
			cont=0;
		}
	}
	stack->esp--;
	stack->val[stack->esp].LNG = r;
	stack->val[stack->esp].type = LNG;


	return 1;
}

int inputToStr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	char aux[1000];
	if(fgets(aux,1000,stdin)==NULL){
		return 0;
	}
	int s = strlen(aux), i;
	aux[s-1]='\0';
	DADOS *arr = malloc(sizeof(DADOS)*(s+10));
	for(i=0; i<s;i++){
		arr[i].CHR = aux[i];
		arr[i].type=CHR;
	}

	stack->esp++;
	stack->val[stack->esp].ARR.array = arr;
	stack->val[stack->esp].ARR.size = s;
	stack->val[stack->esp].ARR.all_size = s+10;
	stack->val[stack->esp].type = ARR;
	return 1;
}

void cpyDados(DADOS *a, DADOS *b, int n){
	int i;
	for(i=0;i<n;i++){
		a[i].CHR=b[i].CHR;
		a[i].type=CHR;
	}
}

int splitStr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	struct ARR string = stack->val[stack->esp-1].ARR;
	struct ARR substr = stack->val[stack->esp].ARR;
	DADOS *resultado=(DADOS *)malloc(sizeof(DADOS)*100000);
	int i,cont=0,bs=0,start=0;
	for(i=0; i<string.size;i++){
		if(string.array[i].CHR==substr.array[cont].CHR){
			cont++;
			if(i-cont+1-start==0&&substr.size==cont){
				start=i+1;
				cont=0;
			}
			else if(substr.size==cont){
				resultado[bs].ARR.array=(DADOS *)malloc(sizeof(DADOS)*(i-cont+10));
				cpyDados(resultado[bs].ARR.array,&(string.array[start]),i-cont+1-start);
				resultado[bs].type=ARR;
				resultado[bs].ARR.size=i-cont+1-start;
				start=i+1;
				
				bs++;
				cont=0;
			}
		}

		else{
			cont=0;
		}
	}
	if(i!=start){
		resultado[bs].ARR.array=(DADOS *)malloc(sizeof(DADOS)*(i-start));
		cpyDados(resultado[bs].ARR.array,&(string.array[start]),i-start);
		resultado[bs].type=ARR;
		resultado[bs].ARR.size=i-start;
		stack->esp--;
		stack->val[stack->esp].ARR.array=resultado;
		stack->val[stack->esp].ARR.size=bs+1;
		stack->val[stack->esp].type=ARR;
	}
	else{
		stack->esp--;
		stack->val[stack->esp].ARR.array=resultado;
		stack->val[stack->esp].ARR.size=bs;
		stack->val[stack->esp].type=ARR;
	}
	return 1;
}

int splitSpace(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(token[0]=='S'&&token[1]=='/'){
		struct ARR string = stack->val[stack->esp].ARR;
		DADOS *resultado=(DADOS *)malloc(sizeof(DADOS)*100000);
		int i,bs=0,start=0;
		for(i=0; i<string.size;i++){
			if(string.array[i].CHR==' ' || string.array[i].CHR=='\n'){

				if(i-start==0){
					start=i+1;
				}
				else{
					resultado[bs].ARR.array=(DADOS *)malloc(sizeof(DADOS)*(i-start+10));
					cpyDados(resultado[bs].ARR.array,&(string.array[start]),i-start);
					resultado[bs].type=ARR;
					resultado[bs].ARR.size=i-start;
					start=i+1;
					
					bs++;
				}
			}
		}
		if(i!=start){
			resultado[bs].ARR.array=(DADOS *)malloc(sizeof(DADOS)*(i-start));
			cpyDados(resultado[bs].ARR.array,&(string.array[start]),i-start);
			resultado[bs].type=ARR;
			resultado[bs].ARR.size=i-start;
			stack->val[stack->esp].ARR.array=resultado;
			stack->val[stack->esp].ARR.size=bs+1;
			stack->val[stack->esp].type=ARR;
		}
		else{
			stack->val[stack->esp].ARR.array=resultado;
			stack->val[stack->esp].ARR.size=bs;
			stack->val[stack->esp].type=ARR;
		}
		return 1;
	}
	return 0;
}

void cmpString(STCK* stack){
	if(stack->val[stack->esp].ARR.size!=stack->val[stack->esp-1].ARR.size){
		stack->esp-=2;
		push_LNG(stack,0);
	}
	else{
		long int i,equal=1;
		for(i=0;i<stack->val[stack->esp].ARR.size;i++){
			if(stack->val[stack->esp].ARR.array[i].CHR!=stack->val[stack->esp-1].ARR.array[i].CHR){
				equal=0;
			}
		}
		stack->esp-=2;
		push_LNG(stack,equal);
	}
}

void greaterString(STCK* stack){
	if(stack->val[stack->esp].ARR.size>stack->val[stack->esp-1].ARR.size){
		stack->esp-=2;
		push_LNG(stack,0);
	}
	else if(stack->val[stack->esp].ARR.size<stack->val[stack->esp-1].ARR.size){
		stack->esp-=2;
		push_LNG(stack,1);
	}
	else{
		long int i,equal=1;
		for(i=0;stack->val[stack->esp].ARR.size>i&&stack->val[stack->esp].ARR.array[i].CHR==stack->val[stack->esp-1].ARR.array[i].CHR;i++){}
		if(stack->val[stack->esp].ARR.size==i||stack->val[stack->esp].ARR.array[i].CHR>stack->val[stack->esp-1].ARR.array[i].CHR){
			equal=0;
		}
		stack->esp-=2;
		push_LNG(stack,equal);
	}
}

void lesserString(STCK* stack){
	if(stack->val[stack->esp].ARR.size<stack->val[stack->esp-1].ARR.size){
		stack->esp-=2;
		push_LNG(stack,0);
	}
	else if(stack->val[stack->esp].ARR.size>stack->val[stack->esp-1].ARR.size){
		stack->esp-=2;
		push_LNG(stack,1);
	}
	else{
		long int i,equal=1;
		for(i=0;stack->val[stack->esp].ARR.size>i&&stack->val[stack->esp].ARR.array[i].CHR==stack->val[stack->esp-1].ARR.array[i].CHR;i++){}

		if(stack->val[stack->esp].ARR.size==i||stack->val[stack->esp].ARR.array[i].CHR<stack->val[stack->esp-1].ARR.array[i].CHR){
			equal=0;
		}
		stack->esp-=2;
		push_LNG(stack,equal);
	}
}

int everythingToStr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	char aux[50000];
	if(scanf("%[ -~\n—]s",aux)!=1){
		return 0;
	}
	int s = strlen(aux), i;
	DADOS *arr = malloc(sizeof(DADOS)*(s+10));
	for(i=0; i<s;i++){
		arr[i].CHR = aux[i];
		arr[i].type=CHR;
	}

	stack->esp++;
	stack->val[stack->esp].ARR.array = arr;
	stack->val[stack->esp].ARR.size = s;
	stack->val[stack->esp].ARR.all_size = s+10;
	stack->val[stack->esp].type = ARR;
	return 1;
}

int splitNL(STCK* stack, char* token){
	if(token[0]=='N'&&token[1]=='/'){
		stack->esp++;
		stack->val[stack->esp].ARR.array = malloc(sizeof(DADOS));
		stack->val[stack->esp].ARR.array[0].CHR = '\n';
		stack->val[stack->esp].ARR.array[0].type = CHR;
		stack->val[stack->esp].ARR.size = 1;
		stack->val[stack->esp].type = ARR;
		splitStr(stack,token);
		return 1;
	}
	return 0;
}