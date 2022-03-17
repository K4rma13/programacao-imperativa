#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define NMAX 2500

typedef struct dic{
	char key[20];
	int value;
}Dic;


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
void ordenaDic(Dic* d, int curr){
	int i,itemp;
	bool flag=true;
	char temp[20];
	while(flag){
		flag=false;
		for(i=0;i<curr;i++){
			if(strcmp(d[i].key,d[i+1].key)>0){
				strcpy(temp,d[i].key);
				strcpy(d[i].key,d[i+1].key);
				strcpy(d[i+1].key,temp);
				itemp=d[i].value;
				d[i].value=d[i+1].value;
				d[i+1].value=itemp;
				flag=true;
			}
		}
	}
}


int keyToInd(Dic* d,char* k,int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(d[i].key,k)==0){
			return i;
		}
	}
	return -1;
}

int lineToDic(Dic* d,char* str,int curr){
	int i,j,ind,l=strlen(str);
	char aux[3];
	for(i=0;i<l;i++){
		if(str[i]>='A' && str[i]<='Z'){
			aux[0]=str[i];
			aux[1]='\0';
			ind=keyToInd(d,aux,curr);
			if(ind==-1){
				strcpy(d[curr].key,aux);
				d[curr].value=1;
				curr++;
			}
			else{
				d[ind].value++;
			}
			for(j=i+1;j<l;j++){
				if(str[j]>='A' && str[j]<='Z'){
					aux[1]=str[j];
					aux[2]='\0';
					ind=keyToInd(d,aux,curr);
					if(ind==-1){
						strcpy(d[curr].key,aux);
						d[curr].value=1;
						curr++;
					}
					else{
						d[ind].value++;
					}
				}
			}
		}
	}
	return curr;
}

int main(){
	int i=0,j,freq,current=0;
	char produtos[NMAX][NMAX];
	Dic productsDic[26^2];
	if(scanf("%d",&freq)==1){
		while ((getchar()) != '\n');
		while(*(fgets(produtos[i],200,stdin))!='\n'){
			fflush(stdin);
			produtos[i][strlen(produtos[i])-1]='\0';
			i++;
		}

		for(j=0;j<i;j++){
			ordena(produtos[j]);
			printf("%s",produtos[j]);
			current=lineToDic(productsDic,produtos[j],current);
		}
		ordenaDic(productsDic,current);
		for(j=0;j<current+1;j++){
			if(productsDic[j].value>=freq){
				printf("%s = %d\n",productsDic[j].key,productsDic[j].value);
			}
		}
	}
	return 0;
}