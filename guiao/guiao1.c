#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
	int stack[50],stackpointer=0;
	char buffer[200], aux[10];
	fgets(buffer, sizeof(buffer), stdin);
	while(*buffer!='\n'){
		sscanf(buffer,"%s^\n",aux);
		if(strcmp(aux,"#")==0){
			stack[stackpointer-1]=stack[stackpointer-1]^stack[stackpointer];
			stackpointer--;
		}
		else{
			stack[stackpointer]=atoi(aux);
			stackpointer++;
		}
	}
	for(int i=stackpointer;i>=0;i--){
		printf("+----------+\n");
		printf("| %5d     |\n",stack[i]);
	}
	return 0;
}
