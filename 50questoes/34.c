#include <stdio.h>

void elimina(int* tab, int n, int l){
	int i;
	for(i=n;i<l;i++){
		tab[i]=tab[i+1];
	}
}

int eliminarep(int* tab, int n){
	int i;
	for(i=0;i<n-1;i++){
		if(tab[i]==tab[i+1]){
			elimina(tab,i--,n--);
		}
	}
	return n;
}

int main(){
	int i, a[]={1,1,1,2,3,5,7,8,8,9,10,10,33,33,33,33};
	int l = eliminarep(a,16);
	for(i=0; i<l;i++){
		printf("%d ",a[i]);
	}
	return 0;
}