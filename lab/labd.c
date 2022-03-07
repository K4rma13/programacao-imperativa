#include <stdio.h>
#include <stdbool.h>
#define L 33554433


bool triangular(unsigned int n, unsigned int* ult, unsigned int* ult1){
	unsigned int i, t=*ult1;
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

void prime(bool* tab, unsigned int n){
	unsigned int i, j;
	for(i=2; i*i<=n; i++){
		if(tab[i]){
			for(j= i*i; j<=n; j+=i){
				tab[j]= false;
			}
		}
	}
}

int main(){
	unsigned int t=0,a,i,b,p=0,ult=1,ult1=0;
	if(scanf("%u %u", &a, &b)== 2){
		static bool tab[L];
		for(i=2; i<=b; i++){
			tab[i] = true;
		}
		tab[0]=false;
		tab[1]=false;
		prime(tab,b);
		for(i=a;i<=b;i++){
			if(tab[i]){
				p++;
			}
			if(triangular(i,&ult,&ult1)){
				t++;
			}
		}
		printf("%u %u\n", t, p);
	}
	return 0;
}