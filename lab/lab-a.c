#include <stdio.h>

int main(){
	int a, b;
	if(scanf("%d %d", &a, &b) == 2){
		if(a>b){
			printf("%d\n", a*a);
		}
		else if(a==b){
			printf("IGUAIS\n");
		}
		else{
			printf("%d\n", b*b);
		}
	}
	return 0;
}