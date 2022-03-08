#include <stdio.h>

void insere(int* tab,int n,int x){
	int i;
	for(i=n;i>0;i--){
		tab[i]=tab[i-1];
		if(tab[i]<x){
			break;			//Termina o ciclo "for" quando o indice é correto
		}
	}
	tab[i]=x;
}

int main(){
	int a=9,b,i,t[20]={1,3,4,7,9,30,35,60,73};

	printf("Introduza um numero:\n");
	scanf("%d", &b);

	insere(t,a,b);
	
	for(i=0;i<a+1;i++){
		printf("%d ", t[i]);
	}
	return 0;
}