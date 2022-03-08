#include <stdio.h>
#include <string.h>

int maiorPrefixo(char* str1,char* str2){
	int i, nprefixo=0;
	for(i=0; str1[i]==str2[i] && str1[i]!='\0';i++){
		nprefixo++;
	}
	return nprefixo;
}

int main(){
	char s1[50],s2[50];
	printf("Escreva 2 frases:\n");
	fgets(s1,sizeof(s1),stdin);
	fgets(s2,sizeof(s2),stdin);
	s1[strlen(s1)-1]='\0';
	s2[strlen(s2)-1]='\0';
	printf("O maior prefixo comum entre as 2 strings é: %d\n",maiorPrefixo(s1,s2));
	return 0;
}