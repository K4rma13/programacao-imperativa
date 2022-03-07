#include <stdio.h>

void quadrado(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("#");
		}
		printf("\n");
	}
}

int main(){
	int a;
	if(scanf("%d", &a)==1){
		quadrado(a);
	}
	return 0;
}