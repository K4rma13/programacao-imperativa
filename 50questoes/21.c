#include <stdio.h>
#include <string.h>

int vogais(char* str){
	int i,vog=0;
    for(i=0; str[i] != '\0';i++){
        if(str[i]== 'a' ||str[i]== 'e' ||str[i]== 'i' ||str[i]== 'o' ||str[i]== 'u' ||str[i]== 'A' ||str[i]== 'E' ||str[i]== 'I' ||str[i]== 'O' || str[i]== 'U' ){
            vog++;
        }
    }
	return vog;
}

int main(){
	char string[50];

	fgets(string,sizeof(string),stdin);
	string[strlen(string)-1];

	printf("Ha %d vogais", vogais(string));

	return 0;
}