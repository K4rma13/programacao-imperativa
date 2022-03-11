#include <stdio.h>

typedef struct posicao{
	int x,y;
} Posicao;

int vizinhos(Posicao p, Posicao* ps,int n){
	int i,viz=0;
	for(i=0;i<n;i++){
		if(p.x-ps[i].x<=1 && p.x-ps[i].x>=-1 && p.y-ps[i].y<=1 && p.y-ps[i].y>=-1){
			viz++;
		}
	}
	return viz;
}

int main(){
	Posicao pos[4],p;
	pos[0].x=5;pos[0].y=5;
	pos[1].x=2;pos[1].y=1;
	pos[2].x=1;pos[2].y=-3;
	pos[3].x=6;pos[3].y=6;
	p.x=5;p.y=6;
	printf("%d", vizinhos(p,pos,4));
	return 0;
}