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

int main(){
	char str[50];
	fgets(str,sizeof(str),stdin);
	str[strlen(str)-1]='\0';
	invertstring(str);
	printf("%s\n",str);
	return 0;
}
