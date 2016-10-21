#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define larg 30
#define alt 30

typedef struct{
	int x, y;
}Point;

typedef struct{
	Point passagem[alt*larg];
	int topo;
	int tamanho;
}Pilha;

typedef struct{
	int aberto;
	int visitado;
}Casa;

void initPilha(Pilha *pilha){
	pilha->topo = -1;
	pilha->tamanho = 0;
	int i;	
	for(i = 0; i < alt*larg; i++){
		pilha->passagem[i].x = -1;
		pilha->passagem[i].y = -1;
	}
}

void pushPilha(Pilha *p, Point c){
	p->topo++;
	p->passagem[p->topo].x = c.x;
	p->passagem[p->topo].y = c.y;
	p->tamanho++;
}

Point popPilha(Pilha *p){
	Point ret = (Point){-1,-1};
	if(p->tamanho > 0){
		p->tamanho--;
		p->topo--;
		return p->passagem[p->topo+1];
	}
	return ret;
}

void initCasas(Casa matriz[alt][larg]){
	int i, j, v;
	for(i = 0; i < alt; i++){
		for(j = 0; j < larg; j++){
			v = (rand()%10 < 7);
			if(!(i == 0 && j==0) && !(i== alt-1 && j==larg-1))
				matriz[i][j] = (Casa){v,0};
			else{
				matriz[i][j] = (Casa){1,0};
			}
			printf("%d ",matriz[i][j].aberto);
		}
		printf("\n");
	}
}

void printCaminho(Pilha caminho, Casa matriz[alt][larg]){
	int i;
	for(i = 0; i < caminho.tamanho; i++){
		matriz[caminho.passagem[i].x][caminho.passagem[i].y].aberto = 2;
	}
	int j;
	printf("\n");
	for(i = 0; i < alt; i++){
		for(j = 0; j < larg; j++){
			if(matriz[i][j].aberto == 2){
				printf("  ");
			}else
				printf("%d ",matriz[i][j].aberto);
		}
		printf("\n");
	}
}

void printVisitado(Casa matriz[alt][larg]){
		int i;
	int j;
	printf("\n");
	for(i = 0; i < alt; i++){
		for(j = 0; j < larg; j++){
			if(matriz[i][j].visitado == 1){
				printf("  ");
			}else
				printf("%d ",matriz[i][j].aberto);
		}
		printf("\n");
	}
}

int labirinto(Casa matriz[alt][larg], Point destino){
	Pilha caminho;	
	int flag = 0, x=0, y=0;
	Point ret;
	initPilha(&caminho);
	while(!flag){
			matriz[x][y].visitado = 1;
			pushPilha(&caminho, (Point){x,y});
			if(!(x == destino.x && y == destino.y)){
				if(x-1 >= 0){
					if(!matriz[x-1][y].visitado && matriz[x-1][y].aberto){
						x--;
						continue;
					}
				}
				if(x+1 < alt){
					if(!matriz[x+1][y].visitado && matriz[x+1][y].aberto){
						x++;
						continue;
					}
				}
				if(y-1 >= 0){
					if(!matriz[x][y-1].visitado && matriz[x][y-1].aberto){
						y--;
						continue;
					}
				}
				if(y+1 < larg){
					if(!matriz[x][y+1].visitado && matriz[x][y+1].aberto){
						y++;
						continue;
					}
				}
				popPilha(&caminho);
				ret = popPilha(&caminho);
				if(ret.x != -1){
					x = ret.x;
					y = ret.y;
					continue;
				}else{
					flag = 1;
				}
				
			}else{
				flag = 1;
			}
	}
/*	if(caminho.tamanho > 0) 
		printCaminho(caminho, matriz);
	else{
		printVisitado(matriz);
	}*/
	
	return caminho.tamanho > 0;
}



int main(){
	Casa matriz[alt][larg];
	srand(time(NULL));
	initCasas(matriz);
	int res = labirinto(matriz, (Point){alt-1, larg-1});
	if(res){
		printf("\nresolvido\n");
	}else{
		printf("\nnao resolvido\n");
	}

	
	return 0;
}