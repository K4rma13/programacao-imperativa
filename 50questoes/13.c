#include <stdio.h>
#include <string.h>

void truncstr(char* s, int n){
	int l=strlen(s),i,x=0,j=0;
	char aux[l];
	for(i=0;i<l;i++){
		if(s[i]!=' ' && x<n){
			aux[j++]=s[i];			//Se x for menor do que o "n" guardamos o valor de "s" na string "aux"
			x++;					//"x" serve como um contador para o nº de letras de uma palavra
		}
		else if(s[i]==' '){
			aux[j++]=s[i];
			x=0;					//Caso acha um espaço resetamos "x" porque sabemos que a palavra que estava a ser contada acabou
		}
	}
	aux[j]='\0';
	strcpy(s,aux);					//Por ultimo copiamos a string "aux" para a string "s"
}

int main(){
	char string[50];
	int max;

	printf("Escreva uma frase:\n");
	fgets(string,sizeof(string),stdin);		//Le uma string e guarda-a em "string"
	printf("Nº maximo de letras por palavra: ");
	scanf("%d",&max);

	string[strlen(string)-1]='\0';			//As strings lidas podem ter um '\n' por causa do enter quando se escreve a string,
											//isto troca esse '\n' por um '\0' que termina a string
	truncstr(string,max);
	printf("%s\n",string);

	return 0;
}