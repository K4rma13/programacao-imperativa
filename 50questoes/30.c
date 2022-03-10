#include <stdio.h>

int menosFreq(int* tab, int n){
	int i,men=n,imen,cur=1;			//"men" vai guardar o numero minimo de repeticoes de todo o vetor, imen vai guardar
									//o valor que se repete "men" vezes e "cur" é o numero de repeticoes do valor atual(index i)
	for(i=0; i<n;i++){
		if(tab[i]==tab[i+1]){
			cur++;					//Caso acha uma repeticao aumentamos o valor de "cur"
		}
		else{
			if(cur<men){			//Caso nao acham mais repeticoes do mesmo valor guardamos o valor e as suas repticoes,
				men=cur;			//se as suas repeticoes forem menores do que o menor lido no resto do vetor("men")
				imen=tab[i];
			}
			cur=1;					//reseta a contagem tendo em conta que o "tab[i]" nao se repete mais
		}
	}
	return imen;
}

int main(){
	int v[30]={1,1,1,3,4,4,4,5,5,6};	//Vetor a ser testado, devera retornar "3" ja que os valores que se repetem menos
										//sao "3" e "6"(ambos apenas 1 vez), mas "3" tem um indice menor
	printf("%d", menosFreq(v,11));

	return 0;
}