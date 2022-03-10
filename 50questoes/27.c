#include <stdio.h>

void merge(int* r, int* a, int* b,int na,int nb){
	int x=0,y=0,i;
	for(i=0;i<na+nb-1;i++){
		if(a[x]>b[y] || x>=na){
			r[i]=b[y++];
		}
		else{
			r[i]=a[x++];
		}
	}
}

int main(){
	int t1[30]={1,3,5,7,7,8}, t2[30]={3,4,9,15,19};
	int r[30];
	merge(r,t1,t2,6,5);
	for(int i=0; i<10;i++){
		printf("%d ",r[i]);
	}
	printf("\n");
	return 0;
}
