#include <stdio.h>
#include <string.h>

int limpaEspacos(char* str){
	int i;
	for(i=0; str[i]!='\0'; i++){
		if(str[i]==' ' && str[i+1]==' '){
			memmove(&str[i],&str[i+1], strlen(str)-i); 	//Remove o char de indice i, trocando os valores de i,i+1,i+2... por i+1,i+2,i+3...
			
			i--;										//Isto faz com que a proxima volte do ciclo passe pelo mesmo i, em caso de haverem varios " " consecutivos
		}
	}
	return strlen(str);
}

int main(){
	char string[50];

	fgets(string,sizeof(string),stdin);		//Le uma string e guarda-a em "string"

	string[strlen(string)-1]='\0';			//As strings lidas podem ter um '\n' por causa do enter quando se escreve a string,
											//isto troca esse '\n' por um '\0' que termina a string
	limpaEspacos(string);
	printf("%s\n",string);
	return 0;
}