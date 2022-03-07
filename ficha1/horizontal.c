#include <stdio.h>

void triangulo(int n){
	int i,j,base=n*2-1;
	for(i=1;i<=base;i++){
		if(i<n){
			for(j=0;j<i;j++){
				printf("#");
			}
		}
		else{
			for(j=0;j<n*2-i;j++){
				printf("#");
			}
		}
		printf("\n");
	}
}