#include <stdio.h>
int contaVogais (char *s) {
    int i, cont=0;
    for(i=0; s[i] != '\0';i++){
        if(s[i]== 'a' ||s[i]== 'e' ||s[i]== 'i' ||s[i]== 'o' ||s[i]== 'u' ||s[i]== 'A' ||s[i]== 'E' ||s[i]== 'I' ||s[i]== 'O' || s[i]== 'U' ){
            cont++;
        }
    }
    return cont;
}

void removechar(char* s, int n){
    int i;
    for(i=n; s[i]!='\0';i++){
        s[i]=s[i+1];
    }
}

void acrescentachar(char* s,char l, int n){
    int i,j;
    for(i=n; s[i] != '\0';i++){}
    for(j=i;j>=n;j--){
        s[j]=s[j-1];
    }
    s[n]=l;
}

int retiraVogaisRep (char *s){
    int i,cont=0;
    for(i=0; s[i]!='\0';i++){
        if(s[i]==s[i+1]){
                if(s[i]== 'a' ||s[i]== 'e' ||s[i]== 'i' ||s[i]== 'o' ||s[i]== 'u' ||s[i]== 'A' ||s[i]== 'E' ||s[i]== 'I' ||s[i]== 'O' || s[i]== 'U' ){
                    cont++;
                    removechar(s,i);
                    i--;
            }
        }
    }
    return cont;
}

int duplicaVogais (char *s){
    int i,cont=0;
    for(i=0; s[i]!='\0'; i++){
        if(s[i]== 'a' ||s[i]== 'e' ||s[i]== 'i' ||s[i]== 'o' ||s[i]== 'u' ||s[i]== 'A' ||s[i]== 'E' ||s[i]== 'I' ||s[i]== 'O' || s[i]== 'U' ){
            cont++;
            acrescentachar(s,s[i],i+1);
            i++;
        }
    }
    return cont;
}

int main()
{   char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    int x;
    
    printf ("Testes\n");
    printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));
    
    x = retiraVogaisRep (s1);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);
    
    x = duplicaVogais (s1);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);
    
    printf ("\nFim dos testes\n");

    return 0;
}