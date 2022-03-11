#include <stdio.h>

int maisFreq(int* tab, int n){
	int i,max=0,imax,cur=1;			//"max" vai guardar o numero maximo de repeticoes de todo o vetor, imax vai guardar
									//o valor que se repete "max" vezes e "cur" é o numero de repeticoes do valor atual(index i)
	for(i=0; i<n;i++){
		if(tab[i]==tab[i+1]){
			cur++;					//Caso acha uma repeticao aumentamos o valor de "cur"
		}
		else{
			if(cur>max){			//Caso nao acham mais repeticoes do mesmo valor guardamos o valor e as suas repticoes,
				max=cur;			//se as suas repeticoes forem maiores do que o maior lido no resto do vetor("max")
				imax=tab[i];
			}
			cur=1;					//reseta a contagem tendo em conta que o "tab[i]" nao se repete mais
		}
	}
	return imax;
}

int main(){
	int v[30]={1,1,1,3,4,4,4,5,5,6};	//Vetor a ser testado, devera retornar "1" ja que os valores que se repetem mais
										//sao "1" e "4"(ambos 3 vezes), mas "1" tem um indice menor
	printf("%d", maisFreq(v,11));

	return 0;
}