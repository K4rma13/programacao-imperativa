#include "stack.h"

void printstack(STCK stack){
	for(int i=0;i<=stack.esp;i++){
		printf("%d",stack.val[stack.esp]);
	}
}