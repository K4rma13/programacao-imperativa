#include <stdio.h>

int crescente(int* v, int i, int f){
	int j;
	for(j=i; j<f; j++){
		if(v[j]>v[j+1]){ 	//Devolver 0 caso o valor do indice atual seja maior do que o seguinte
			return 0; 		//Quando uma funcao devolve um valor ela termina entao "return 1;" nao acontecera
		}
	}
	return 1;
}

int main(){
		int a[]={5,4,7,2,1,-5,4,5,4};	//Vetor a ser testado
		int i,x,y;
		scanf("%d %d", &x,&y);
		printf("%d\n",crescente(a,x,y));
		return 0;
}