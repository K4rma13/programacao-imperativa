#include <stdio.h>

int fatorial(int n){
	int i,r=1;
	for(i=1;i<=n;i++){
		r=r*i;
	}
	return r;
}

int main(){
	int a,b,c,temp,i;
	if(scanf("%d %d %d", &a, &b, &c) == 3){
		if(a<c){
			temp=a;
			a=c;
			c=temp;
		}
		if(b<c){
			temp=c;
			c=b;
			b=temp;
		}
		if(a<b){
			temp=b;
			b=a;
			a=temp;
		}
		for(i=1;fatorial(i)<a;i++){
		}
		if(fatorial(i)==a){
			printf("FATORIAL\n");
		}
		else{
			printf("%d %d %d\n", c, b, a);
		}
	}
	return 0;
}
