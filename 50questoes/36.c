#include <stdio.h>

int comuns(int* a,int na,int* b,int nb){
	int i,j,com=0;
	for(i=0;i<na;i++){
		for(j=0;j<nb;j++){
			if(a[i]==b[j]){
				com++;
			}
		}
	}
	return com;
}

int main(){
	int fst[20]={4,3,7,2,2,5,32,46,13},snd[20]={5,4,2,13,5,6,8,62,1,3,63};
	printf("Ha %d em comum\n", comuns(fst,9,snd,11));
	return 0;
}
