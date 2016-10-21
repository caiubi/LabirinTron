#include <cmath>
#include <iostream>
#include "Labirinth.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

void Labirinth::initRandomMatrix(){
	int i, j, v;
	for(i = 0; i < alt; i++){
		for(j = 0; j < larg; j++){
			v = (rand()%10 < 6);
			if(!(i == 0 && j==0) && !(i== alt-1 && j==larg-1))
				spots[i][j] = (Spot){v,0};
			else{
				spots[i][j] = (Spot){1,0};
			}
//			printf("%d ",spots[i][j].opened);
		}
//		printf("\n");
	}
}

bool Labirinth::isSolveable(){
	Path path(larg*alt);	
	Point destino = (Point){alt-1, larg-1};
	int flag = 0, x = 0, y = 0;
	Point ret;
	while(!flag){
		spots[x][y].visited = 1;
		path.push((Point){x,y});

		if(!(x == destino.x && y == destino.y)){
			if(x-1 >= 0){
				if(!spots[x-1][y].visited && spots[x-1][y].opened){
					x--;
					continue;
				}
			}
			if(x+1 < alt){
				if(!spots[x+1][y].visited && spots[x+1][y].opened){
					x++;
					continue;
				}
			}
			if(y-1 >= 0){
				if(!spots[x][y-1].visited && spots[x][y-1].opened){
					y--;
					continue;
				}
			}
			if(y+1 < larg){
				if(!spots[x][y+1].visited && spots[x][y+1].opened){
					y++;
					continue;
				}
			}
			path.pop();
			ret = path.pop();
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
/*	if(path.size > 0) 
	printCaminho(path, spots);
else{
	printvisited(spots);
}*/
	bool res = path.getSize() > 0;
//	delete path;
	return res;
}

Labirinth::Labirinth(int larg, int alt){
	srand(time(NULL));
	this->larg = larg;
	this->alt = alt;

	spots = new Spot*[alt];
	for (int i = 0; i < alt; ++i)
		spots[i] = new Spot[larg];
}

void Labirinth::generate(){
	while(!isSolveable()){
		initRandomMatrix();
	}
}

void Labirinth::print(){
	for(int i = 0; i < alt; i++){
		for(int j = 0; j < larg; j++){
			if(spots[i][j].opened){
				cout << "  ";
			}else{
				cout << "██";
			}
//			cout << spots[i][j].opened;
		}
		cout << endl;
	}
}

int Labirinth::getBlockAt(int i, int j){
	return spots[i][j].opened;	
}
