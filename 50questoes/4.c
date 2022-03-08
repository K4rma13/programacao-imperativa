#include <stdio.h>

int bitsUm(unsigned int n){
	int i,cont=0;
	while(n){
		cont += 1&n;
		n >>= 1;
	}
	return cont;
}

int main(){
	int a;
	if(scanf("%d", &a)==1){
		printf("%d\n",bitsUm(a));
	}
	return 0;
}