#include <stdio.h>

void triangulo(int n){
	int i,j,base=n*2-1;
	for(i=0; i<n;i++){
		for(j=0;j<base/2+1+i;j++){
			if(j<base/2-i){
				printf(" ");
			}
			else{
				printf("#");
			}
		}
		printf("\n");
	}
}