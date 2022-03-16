#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXSEQ 10000

char aux[MAXSEQ];

bool palindrome(char* s1,int n){
	int i;
	for(i=0;i<n+1;i++){
		if(s1[i]!=s1[n-i]){
			return false;
		}
	}
	return true;
}

int main(){
	char str[MAXSEQ];
	int i,curcont=0,maxcont=0,start=0;
	if(fgets(str,MAXSEQ,stdin)!= NULL){
		int l=strlen(str);
		str[l-1]='\0';
		for(start=0;str[start]!='\0';start++){
			for(i=l-1;i>=start;i--){
				if(i-start+1<=maxcont){
					break;
				}
				if(str[i]==str[start]){
					if(palindrome(&(str[start]),i-start)){
						curcont=i-start+1;
						break;
					}
				}
			}
			if(curcont>maxcont){
				maxcont=curcont;
			}
			if(l-start<=maxcont){
				break;
			}
		}
		printf("%d\n",maxcont);
	}
	return 0;
}
