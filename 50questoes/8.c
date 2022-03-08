#include <stdio.h>

char* stringcpy(char* str, char* source){
	int i;
	for(i=0;source[i] != '\0';i++){
		str[i]=source[i];
	}
	str[i]='\0';
	return str;
}

int main(){
	char src[]="For fuck sake", str1[]="Hello World!";
	stringcpy(src,str1);
	printf("%s",src);
	return 0;
}