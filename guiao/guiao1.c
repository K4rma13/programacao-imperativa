#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(){
	int stack[50],stackpointer=-1,n=0;
	char buffer[200], aux[10],*b;
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer)-1]='\0';
	b=buffer;
	while(*b!='\0'){
		sscanf(b,"%s %n",aux,&n);
		b+=n;
		if(strcmp(aux,"#")==0){
			stack[stackpointer-1]=pow(stack[stackpointer-1],stack[stackpointer]);
			stackpointer--;
		}
		else{
			stackpointer++;
			stack[stackpointer]=atoi(aux);
			
		}
	}
	for(int i=stackpointer;i>=0;i--){
		printf("+-----------+\n");
		printf("| %5d     |\n",stack[i]);
	}
	printf("+-----------+\n");
	return 0;
}
