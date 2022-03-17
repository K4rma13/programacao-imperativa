#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define NMAX 40000

typedef struct dic{
	char key[20];
	int value;
}Dic;

void btcpy(char* s1, char* s2){
	int i;
	for(i=0;s2[i]!='\0';i++){
		s1[i]=s2[i];
	}
	s1[i]='\0';
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
void ordenaDic(Dic* d, int curr){
	int i,itemp;
	bool flag=true;
	char temp[20];
	while(flag){
		flag=false;
		for(i=0;i<curr;i++){
			if(strcmp(d[i].key,d[i+1].key)>0){
				btcpy(temp,d[i].key);
				btcpy(d[i].key,d[i+1].key);
				btcpy(d[i+1].key,temp);
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
	printf("%d",l);
	char aux[3];
	for(i=0;i<l;i++){
		if(str[i]>='A' && str[i]<='Z'){
			aux[0]=str[i];
			aux[1]='\0';
			ind=keyToInd(d,aux,curr);
			if(ind==-1){
				btcpy(d[curr].key,aux);
				d[curr].value=1;
				curr++;
			}
			else{
				d[ind].value++;
			}
		}
	}
	return curr;
}

int doublesToDic(Dic* d,char* str, int c){
	int i,j,l=strlen(str),ind;
	char aux[4],temp[l];
	btcpy(temp,str);
	for(i=0;i<l;i++){
		if(temp[i]>='A' && temp[i]<='Z'){
			printf(" %c:",temp[i]);
			for(j=i+1;j<l;j++){
				if(temp[j]>='A' && temp[j]<='Z'){
					printf("%c ",temp[j]);
					aux[0]=temp[i];
					aux[1]=temp[j];
					aux[2]='\0';
					//printf("%s",aux);
					ind=keyToInd(d,aux,c);
					if(ind==-1){
						btcpy(d[c].key,aux);
						d[c].value=1;
						c++;
					}
					else{
						d[ind].value++;
					}
				}
			}
		}
	}
	printf("\n---------------------------\n");
	return c;
}

int main(){
	int j,freq,current=0,i=0;
	char produtos[NMAX][200],aux[200];
	Dic productsDic[26^2];
	if(scanf("%d",&freq)==1){
		while((getchar()) != '\n');
		while(*(fgets(produtos[i],200,stdin))!='\n'){
			produtos[i][strlen(produtos[i])-1]='\0';
			i++;
		}
		for(j=0;j<i;j++){
			printf("%s\n",produtos[j]);
		}
		for(j=0;j<i;j++){
			strcpy(aux,produtos[j]);
			ordena(produtos[j]);
			
			printf("\n%s\n\n", aux);
			current=lineToDic(productsDic,aux,current);
			//current=doublesToDic(productsDic,aux,current);
			//printf("%s\n",produtos[j]);
		}
		ordenaDic(productsDic,current);
		for(j=0;j<current;j++){
			if(productsDic[j].value>=freq){
				printf("%s = %d\n",productsDic[j].key,productsDic[j].value);
			}
		}
	}
	return 0;
}