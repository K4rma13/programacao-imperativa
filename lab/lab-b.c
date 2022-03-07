#include <stdio.h>

int main(){
	int h,r,rmenor;
	if(scanf("%d %d %d", &r, &h, &rmenor) == 3){
		printf("%d\n", (int) (h*3.14*(r*r+r*rmenor+rmenor*rmenor)/3));
	}
	return 0;
}