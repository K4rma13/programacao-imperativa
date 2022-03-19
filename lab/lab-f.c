#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXN 700
#define MAXS 8500


typedef struct dic{
	char* key;
	int value;
}Dic;

void ordenaDic(Dic* d, int curr){
	int i,itemp;
	bool flag=true;
	char temp[20];
	while(flag){
		flag=false;
		for(i=0;i<curr-1;i++){
			if(strcmp(d[i].key,d[i+1].key)>0){
				memcpy(temp,d[i].key,3);
				memcpy(d[i].key,d[i+1].key,3);
				memcpy(d[i+1].key,temp,3);
				itemp=d[i].value;
				d[i].value=d[i+1].value;
				d[i+1].value=itemp;
				flag=true;
			}
		}
	}
}

void ordena(char* s){
	int i,l=strlen(s);
	bool flag=true;
	char temp;
	while(flag){
		flag=false;
		for(i=0;i<l-1;i++){
			if(s[i]>s[i+1]){
				temp=s[i];
				s[i]=s[i+1];
				s[i+1]=temp;
				flag=true;
			}
		}
	}
}

int keyToInd(Dic* d, char* str, int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(str,d[i].key)==0){
			return i;
		}
	}
	return -1;
}


int addLineToDic(Dic* d,int n, char* str){
	int i,j,l=strlen(str);
	char* aux;
	for(i=0;i<l;i++){
		if(str[i]>='A'&&str[i]<='Z'){
			aux=(char*)malloc(2);
			aux[0]=str[i];
			aux[1]='\0';
			int index=keyToInd(d,aux,n);
			if(index!=-1){
				
				d[index].value++;
			}
			else{
				d[n].key= (char*)malloc(2);
				memcpy(d[n].key,aux,2);
				d[n].value=1;
				n++;
			}
			free(aux);
			for(j=i+1;j<l;j++){
				if(str[j]>='A'&&str[j]<='Z'){
					aux=(char*)malloc(3);
					aux[0]=str[i];
					aux[1]=str[j];
					aux[2]='\0';
					int index=keyToInd(d,aux,n);
					if(index!=-1){
						d[index].value++;
					}

					else{
						d[n].key=(char*)malloc(3);
						memmove(d[n].key,aux,3);
						d[n].value=1;
						n++;
					}
					free(aux);

				}
			}
		}
	}
	return n;
}
int addTabToDic(Dic* d, int c,char* tab[],int m){
	int i;
	for(i=0;i<m;i++){
		c=addLineToDic(d,c,tab[i]);
	}
	return c;
}



int main(){
	int i=0,j,current=0,freq;
	char* produtos[MAXN];
	char aux[MAXS];
	Dic orgprodutos[26^2];

	if(scanf("%d",&freq)==1){
		while(getchar()!='\n');
		while(*(fgets(aux,MAXS,stdin))!='\n'){
			produtos[i]=malloc(strlen(aux)+1);
			memcpy(produtos[i],aux,strlen(aux));
			produtos[i][strlen(produtos[i])-1]='\0';
			ordena(produtos[i]);
			i++;
		}
		current=addTabToDic(orgprodutos,current,produtos,i);
		ordenaDic(orgprodutos,current);
		for(j=0;j<=current;j++){
			if(orgprodutos[j].value>=freq){
				printf("%s = %d\n", orgprodutos[j].key,orgprodutos[j].value);
			}
		}

	}
	return 0;
}