#include <stdio.h>
#include <stdbool.h>

bool triangular(int n, int* ult, int* ult1){
	int i, t=*ult1;
	for(i= *ult;t<n;i++){
		t=i+t;
	}
	*ult=i;
	*ult1=t;
	if(t==n){
		return true;
	}
	else{
		return false;
	}
	return false;
}

bool primo(int n){
	int i;
	if(n==1){
		return 0;
	}
	for(i=2;i<= (n/2);i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int a,b,i, t=0, p=0, ult=1, ult1=0;
	if(scanf("%d %d", &a, &b) == 2){
		if(b>a){
			i=a;
			a=b;
			b=i;
		}
		for(i=b;i<=a;i++){
			if(triangular(i, &ult, &ult1)){
				t++;
			}
			if(primo(i)){
				p++;
			}
		}
		printf("%d %d\n", t, p);
	}
	return 0;
}
