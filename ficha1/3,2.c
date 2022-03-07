#include <stdio.h>

void xadrez(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j%2==0 && i%2==0){
				printf("#");
			}
			else if(j%2==0){
				printf("_");
			}
			else if(i%2==0){
				printf("_");
			}
			else{
				printf("#");
			}
		}
		printf("\n");
	}
}

int main(){
	int a;
	if(scanf("%d", &a)==1){
		xadrez(a);
	}
	return 0;
}