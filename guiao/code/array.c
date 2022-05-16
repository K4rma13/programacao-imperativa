#include "array.h"

int arrMUL(STCK* stack){
	int i;
	long int m;
	struct ARR *arr;
	if(hastype(stack->val[stack->esp],ARR)){
		arr = stack->val[stack->esp].ARR;
		if(hastype(stack->val[stack->esp-1],LNG)){
			m = stack->val[stack->esp-1].LNG;
		}
		else{
			m = (long int)stack->val[stack->esp-1].DOUBLE;
		}
	}
	else{
		arr = stack->val[stack->esp-1].ARR;
		if(hastype(stack->val[stack->esp],LNG)){
			m = stack->val[stack->esp].LNG;
		}
		else{
			m = (long int)stack->val[stack->esp].DOUBLE;
		}
	}
	if(arr->size*m>=arr->all_size){
		arr->all_size*=m;
		arr->array = realloc(arr->array, sizeof(DADOS)*arr->all_size);
	}
	int s = arr->size;
	arr->size *= m;
	for(i=0; i<arr->size;i++){
		arr->array[i] = arr->array[i%s];
	}
	stack->val[stack->esp-1].ARR=arr;
	stack->val[stack->esp-1].type=ARR;
	stack->esp--;
	return 1;
}

int arrADD(STCK* stack){
	int i;
	if(hastype(stack->val[stack->esp],ARR)&&hastype(stack->val[stack->esp-1],ARR)){
		concatArray(stack->val[stack->esp-1].ARR,stack->val[stack->esp].ARR);
		stack->esp--;
	}
	else if(hastype(stack->val[stack->esp],ARR)){
		if(stack->val[stack->esp].ARR->size+1>=stack->val[stack->esp].ARR->all_size){
			stack->val[stack->esp].ARR->array = realloc(stack->val[stack->esp].ARR->array, sizeof(DADOS)*(stack->val[stack->esp].ARR->size+10));
			stack->val[stack->esp-1].ARR->all_size=stack->val[stack->esp-1].ARR->size+10;
		}
		for(i=stack->val[stack->esp].ARR->size-1;i>=0;i--){
			stack->val[stack->esp].ARR->array[i+1] = stack->val[stack->esp].ARR->array[i];
		}
		stack->val[stack->esp].ARR->size++;
		stack->val[stack->esp].ARR->array[0] = stack->val[stack->esp-1];
		stack->val[stack->esp-1]=stack->val[stack->esp];
		stack->esp--;
	}
	else{
		if(stack->val[stack->esp-1].ARR->size+1>=stack->val[stack->esp-1].ARR->all_size){
			stack->val[stack->esp-1].ARR->array = realloc(stack->val[stack->esp-1].ARR->array, sizeof(DADOS)*(stack->val[stack->esp-1].ARR->size+10));
			stack->val[stack->esp-1].ARR->all_size=stack->val[stack->esp-1].ARR->size+10;
		}
		stack->val[stack->esp-1].ARR->array[stack->val[stack->esp-1].ARR->size]=stack->val[stack->esp];
		stack->val[stack->esp-1].ARR->size++;
		stack->esp--;
	}
	return 1;
}

void concatArray( struct ARR* array1, struct ARR* array2){
	int i;
	int s;
	s=array1->size;
	array1->array = realloc(array1->array,sizeof(DADOS)*(array1->size+array2->size+100));
	array1->size += array2->size;
	array1->all_size =array1->size+array2->size+100;

	for(i=s; i<array1->size;i++){
		array1->array[i]=array2->array[i-s];
	}
	if(array2->array!=NULL){
		free(array2->array);
	}
}


int enumerate(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(hastype(stack->val[stack->esp],ARR)){
		stack->val[stack->esp].LNG=stack->val[stack->esp].ARR->size;
		//free(stack->val[stack->esp].ARR->array);
		stack->val[stack->esp].type=LNG;
	}
	else{
		int i;
		long int max = stack->val[stack->esp].LNG;
		struct ARR *arr;
		arr = malloc(sizeof(struct ARR));
		arr->size = max;
		arr->all_size = max+10;
		arr->array = malloc(sizeof(DADOS)*arr->all_size);
		for(i=0;i < max;i++){
			arr->array[i].LNG=i;
			arr->array[i].type=LNG;
		}
		stack->val[stack->esp].ARR=arr;
		stack->val[stack->esp].type=ARR;
	}
	return 1;
}

int lastArray(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	struct ARR *arr;
	arr = malloc(sizeof(struct ARR));
	arr->size = stack->val[stack->esp].LNG;
	arr->all_size = arr->size+10;
	arr->array = malloc(sizeof(DADOS)*arr->all_size);
	int m = stack->val[stack->esp-1].ARR->size-arr->size;
	int i;
	for(i=0; i < arr->size;i++){
		arr->array[i]=stack->val[stack->esp-1].ARR->array[i+m];
	}
	stack->esp--;
	stack->val[stack->esp].ARR = arr;
	return 1;
}

int firstArray(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	struct ARR *arr;
	arr = malloc(sizeof(struct ARR));
	arr->size = stack->val[stack->esp].LNG;
	arr->all_size = arr->size+10;
	arr->array = malloc(sizeof(DADOS)*arr->all_size);
	int i;
	for(i=0; i < arr->size;i++){
		arr->array[i]=stack->val[stack->esp-1].ARR->array[i];
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
	DADOS *array = calloc((cont+10),sizeof(DADOS));
	for(i=0;i<cont;i++){
		array[i]=stack->val[stack->esp-cont+1+i];
	}
	stack->esp-=cont;
	stack->val[stack->esp].ARR = malloc(sizeof(struct ARR));
	stack->val[stack->esp].ARR->array = array;
	stack->val[stack->esp].ARR->all_size = cont+10;
	stack->val[stack->esp].ARR->size = cont;
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
	stack->val[stack->esp].ARR = malloc(sizeof(struct ARR));
	stack->val[stack->esp].ARR->array = array;
	stack->val[stack->esp].ARR->all_size = cont+10;
	stack->val[stack->esp].ARR->size = cont-1;
	stack->val[stack->esp].type = ARR;
	return 1;
}

int indexArr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	long int ind = stack->val[stack->esp].LNG;
	stack->esp--;
	DADOS *teste = stack->val[stack->esp].ARR->array;
	stack->val[stack->esp]=stack->val[stack->esp].ARR->array[ind];
	
	free(teste);
	return 1;
}

int arrayToStack(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	int i;
	int s = stack->val[stack->esp].ARR->size;
	DADOS *array= stack->val[stack->esp].ARR->array;
	for(i=0; i<s;i++){
		stack->val[stack->esp] = array[i];
		stack->esp++;
	}
	stack->esp--;
	free(array);
	return 1;
}

int rmLastArr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	stack->val[stack->esp].ARR->size--;
	DADOS last = stack->val[stack->esp].ARR->array[stack->val[stack->esp].ARR->size];
	stack->esp++;
	stack->val[stack->esp] = last;
	return 1;
}
int rmFirstArr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	DADOS first = stack->val[stack->esp].ARR->array[0];
	int i;
	for(i=0;i<stack->val[stack->esp].ARR->size;i++){
		stack->val[stack->esp].ARR->array[i]=stack->val[stack->esp].ARR->array[i+1];
	}
	stack->val[stack->esp].ARR->size--;
	stack->esp++;
	stack->val[stack->esp] = first;
	return 1;
}

int findArr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	struct ARR *string = stack->val[stack->esp-1].ARR;
	struct ARR *substr;
	if(hastype(stack->val[stack->esp],ARR)){
		substr = stack->val[stack->esp].ARR;
	}
	else{
		substr = malloc(sizeof(struct ARR));
		substr->size=1;
		substr->all_size=1;
		substr->array = malloc(sizeof(DADOS));
		substr->array[0].CHR=stack->val[stack->esp].CHR;
		substr->array[0].type=CHR;
	}
	int i, cont = 0, first=0;
	long int r=-1;
	for(i=0; i<string->size;i++){
		if(string->array[i].CHR==substr->array[cont].CHR){
			cont++;
			if(substr->size==cont&&first==0){
				r= i-cont+1;
				first=1;
			}
		}
		else{
			cont=0;
		}
	}
	free(string->array);
	free(substr->array);
	stack->esp--;
	stack->val[stack->esp].LNG = r;
	stack->val[stack->esp].type = LNG;


	return 1;
}

int inputToStr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	char* aux;
	aux = malloc(100000);
	if(fgets(aux,100000,stdin)==NULL){
		return 0;
	}
	int s = strlen(aux), i;
	aux[s-1]='\0';
	DADOS *arr = calloc((s+10),sizeof(DADOS));
	for(i=0; i<s;i++){
		arr[i].CHR = aux[i];
		arr[i].type=CHR;
	}
	free(aux);
	stack->esp++;
	stack->val[stack->esp].ARR = malloc(sizeof(struct ARR));
	stack->val[stack->esp].ARR->array = arr;
	stack->val[stack->esp].ARR->size = s-1;
	stack->val[stack->esp].ARR->all_size = s+10;
	stack->val[stack->esp].type = ARR;
	return 1;
}

int charToArray(STCK* stack){
	char a = stack->val[stack->esp].CHR;
	stack->esp--;
	char b = stack->val[stack->esp].CHR;
	stack->val[stack->esp].ARR = malloc(sizeof(struct ARR));
	stack->val[stack->esp].ARR->array = malloc(sizeof(DADOS)*2);
	stack->val[stack->esp].ARR->size = 2;
	stack->val[stack->esp].ARR->all_size = 2;
	stack->val[stack->esp].ARR->array[0].CHR=b;
	stack->val[stack->esp].ARR->array[0].type=CHR;
	stack->val[stack->esp].ARR->array[1].CHR=a;
	stack->val[stack->esp].ARR->array[1].type=CHR;
	stack->val[stack->esp].type=ARR;
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
	struct ARR *string = stack->val[stack->esp-1].ARR;
	struct ARR *substr = stack->val[stack->esp].ARR;
		DADOS *resultado=(DADOS *)malloc(sizeof(DADOS)*stack->val[stack->esp-1].ARR->size);
		int i,cont=0,bs=0,start=0;
		for(i=0; i<string->size;i++){
			if(string->array[i].CHR==substr->array[cont].CHR){
				cont++;
				if(i-cont+1-start==0&&substr->size==cont){
					start=i+1;
					cont=0;
				}
				else if(substr->size==cont){
					resultado[bs].ARR = malloc(sizeof(struct ARR));
					resultado[bs].ARR->array=(DADOS *)malloc(sizeof(DADOS)*(i-cont+10));
					cpyDados(resultado[bs].ARR->array,&(string->array[start]),i-cont+1-start);
					resultado[bs].type=ARR;
					resultado[bs].ARR->size=i-cont+1-start;
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
			resultado[bs].ARR = malloc(sizeof(struct ARR));
			resultado[bs].ARR->array=(DADOS *)malloc(sizeof(DADOS)*(i-start));
			cpyDados(resultado[bs].ARR->array,&(string->array[start]),i-start);
			resultado[bs].type=ARR;
			resultado[bs].ARR->size=i-start;
			bs++;
		}
		stack->esp--;
		stack->val[stack->esp].ARR->array=resultado;
		stack->val[stack->esp].ARR->size=bs;
		stack->val[stack->esp].type=ARR;
	return 1;
}

int splitSpace(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	if(token[0]=='S'&&token[1]=='/'){
		struct ARR *string = stack->val[stack->esp].ARR;
		DADOS *resultado=(DADOS *)malloc(sizeof(DADOS)*string->size);
		int i,bs=0,start=0;
		for(i=0; i<string->size;i++){
			if(isspace(string->array[i].CHR)){

				if(i-start==0){
					start=i+1;
				}
				else{
					resultado[bs].ARR = malloc(sizeof(struct ARR));
					resultado[bs].ARR->array=(DADOS *)malloc(sizeof(DADOS)*(i-start+10));
					cpyDados(resultado[bs].ARR->array,&(string->array[start]),i-start);
					resultado[bs].type=ARR;
					resultado[bs].ARR->size=i-start;
					start=i+1;
					
					bs++;
				}
			}
		}
		if(i!=start){
			resultado[bs].ARR = malloc(sizeof(struct ARR));
			resultado[bs].ARR->array=(DADOS *)malloc(sizeof(DADOS)*(i-start));
			cpyDados(resultado[bs].ARR->array,&(string->array[start]),i-start);
			resultado[bs].type=ARR;
			resultado[bs].ARR->size=i-start;
			stack->val[stack->esp].ARR->array=resultado;
			stack->val[stack->esp].ARR->size=bs+1;
			stack->val[stack->esp].type=ARR;
		}
		else{
			stack->val[stack->esp].ARR->array=resultado;
			stack->val[stack->esp].ARR->size=bs;
			stack->val[stack->esp].type=ARR;
		}
		return 1;
	}
	return 0;
}

int cmpString(STCK* stack){
	if(stack->val[stack->esp].ARR->size!=stack->val[stack->esp-1].ARR->size){
		stack->esp-=2;
		push_LNG(stack,0);
	}
	else{
		long int i,equal=1;
		for(i=0;i<stack->val[stack->esp].ARR->size;i++){
			if(stack->val[stack->esp].ARR->array[i].CHR!=stack->val[stack->esp-1].ARR->array[i].CHR){
				equal=0;
			}
		}
		stack->esp-=2;
		push_LNG(stack,equal);
	}
	return 1;
}

int lStr(STCK* stack){
	DADOS a = stack->val[stack->esp];
	DADOS b = stack->val[stack->esp-1];
	long int i,ret=1;
	for(i=0;b.ARR->size>i&&a.ARR->size>i&&a.ARR->array[i].CHR==b.ARR->array[i].CHR;i++){}
	if((a.ARR->size==i&&b.ARR->size>a.ARR->size)||a.ARR->array[i].CHR<=b.ARR->array[i].CHR){
		ret=0;
	}
	return ret;
}

int grStr(STCK* stack){
	DADOS a = stack->val[stack->esp];
	DADOS b = stack->val[stack->esp-1];
	long int i,ret=1;
	for(i=0;b.ARR->size>i&&a.ARR->size>i&&a.ARR->array[i].CHR==b.ARR->array[i].CHR;i++){}
	if((a.ARR->size==i&&b.ARR->size<a.ARR->size)||a.ARR->array[i].CHR>=b.ARR->array[i].CHR){
		ret=0;
	}
	return ret;
}


int greaterString(STCK* stack){
	long int equal = grStr(stack);
	stack->esp-=2;
	push_LNG(stack,equal);
	return 1;
}

int lesserString(STCK* stack){
	long int equal = lStr(stack);
	stack->esp-=2;
	push_LNG(stack,equal);
	return 1;
}

int everythingToStr(STCK* stack, char* token){
	if((int)token[0]==0){printf("Erro");}
	char* aux;
	aux = malloc(1000000);
	if(scanf("%[\x1-\xff]",aux)!=1){
		return 0;
	}
	int s = strlen(aux), i;
	DADOS *arr = malloc(sizeof(DADOS)*(s+10));
	for(i=0; i<s;i++){
		arr[i].CHR = aux[i];
		arr[i].type=CHR;
	}
	free(aux);
	stack->esp++;
	stack->val[stack->esp].ARR = malloc(sizeof(struct ARR));
	stack->val[stack->esp].ARR->array = arr;
	stack->val[stack->esp].ARR->size = s;
	stack->val[stack->esp].ARR->all_size = s+10;
	stack->val[stack->esp].type = ARR;
	return 1;
}

int splitNL(STCK* stack, char* token){
	if(token[0]=='N'&&token[1]=='/'){
		stack->esp++;
		stack->val[stack->esp].ARR = malloc(sizeof(struct ARR));
		stack->val[stack->esp].ARR->array = malloc(sizeof(DADOS));
		stack->val[stack->esp].ARR->array[0].CHR = '\n';
		stack->val[stack->esp].ARR->array[0].type = CHR;
		stack->val[stack->esp].ARR->size = 1;
		stack->val[stack->esp].type = ARR;
		splitStr(stack,token);
		return 1;
	}
	return 0;
}