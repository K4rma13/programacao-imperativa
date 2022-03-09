#include <stdio.h>
#include <string.h>


char* strconcat(char* str1, char* str2){
	int i,l=strlen(str1);
	for(i=0;str2[i]!='\0';i++){
		str1[l+i]=str2[i];
	}
	str1[l+i]='\0';
	return str1;
}

int main(){
	char first[30] ="Hello ", second[30]="World!";

	strconcat(first,second);
	printf("%s\n", first);

	return 0;
}