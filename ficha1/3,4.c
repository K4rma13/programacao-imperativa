#include <stdio.h>

int circulo(int n){
	int i,j,cont=0;
	for(i=-n;i<=n;i++){
		for(j=-n;j<=n;j++){
			if(i*i+j*j<=n*n){
				printf("#");
				cont++;
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return cont;
}

int main(){
	int a,c;
	if(scanf("%d", &a)==1){
		c=circulo(a);
		printf("Foram imprimidos: %d\nA area de raio %d é: %f\n",c,a,3.14*a*a);
	}
	return 0;
}