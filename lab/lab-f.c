#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXN 700
#define MAXS 8500


typedef struct dic{
	char key[9000];
	int value;
}Dic;

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
	char aux[10];
	for(i=0;i<l;i++){
		if(str[i]>='A'&&str[i]<='Z'){
			
			aux[0]=str[i];
			aux[1]='\0';
			int index=keyToInd(d,aux,n);
			if(index!=-1){
				
				d[index].value++;
			}
			else{
				strcpy(d[n].key,aux);
				d[n].value=1;
				n++;
			}
			for(j=i+1;j<l;j++){
				if(str[j]>='A'&&str[j]<='Z'){
					
					aux[0]=str[i];
					aux[1]=str[j];
					aux[2]='\0';
					int index=keyToInd(d,aux,n);
					if(index!=-1){
						d[index].value++;
					}

					else{
						strcpy(d[n].key,aux);
						d[n].value=1;
						n++;
					}

				}
			}
		}
	}
	return n;
}
int addTabToDic(Dic* d, int c,char tab[][MAXS],int m){
	int i;
	for(i=0;i<m;i++){
		c=addLineToDic(d,c,tab[i]);
	}
	return c;
}



int main(){
	int i=0,j,current=0,freq;
	char produtos[MAXN][MAXS];
	Dic orgprodutos[26^2];

	if(scanf("%d",&freq)==1){
		while(getchar()!='\n');
		while((fgets(produtos[i],MAXS,stdin))!=NULL){
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