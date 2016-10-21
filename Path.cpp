#include "Path.h"

Path::Path(int tam){
	top = -1;
	size = 0;
	int i;	
	position = new Point[tam];
	for(i = 0; i < tam; i++){
		position[i].x = -1;
		position[i].y = -1;
	}
}

void Path::push(Point c){
	top++;
	position[top].x = c.x;
	position[top].y = c.y;
	size++;
}

Point Path::pop(){
	Point ret = (Point){-1,-1};
	if(size > 0){
		size--;
		top--;
		return position[top+1];
	}
	return ret;
}

Point Path::get(int i){
	return position[i];
}

int Path::getSize(){
	return size;
}