#include <stdio.h>
#include <string.h>

void invertstring(char* s){
	int i, l=strlen(s);
	char temp[l];
	for(i=l-1; i>=0;i--){
		temp[(l-1)-i]=s[i];
	}
	temp[l]='\0';
	strcpy(s, temp);
}

void palindrome(char* s){
	char rev[strlen(s)];
	strcpy(rev,s);
	invertstring(rev);
	if(strcmp(rev,s)==0){
		printf("É palindrome\n");
	}
	else printf("Nao é palindrome\n");
}

int main(){
	char test[50];
	printf("Escreva uma palavra:\n");
	fgets(test,sizeof(test),stdin);
	test[strlen(test)-1]='\0';
	palindrome(test);
	return 0;
}
