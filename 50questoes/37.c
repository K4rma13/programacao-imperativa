#include <stdio.h>

int minInd(int* v, int n){
	int i, ind=0, min=v[0];
	for(i=1;i<n;i++){
		if(v[i]<min){
			min=v[i];
			ind=i;
		}
	}
	return ind;
}

int main(){
		int i, a[]={5,4,7,2,1,-5,4};
		printf("%d ",minInd(a,7));
		return 0;
}