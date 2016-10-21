#include <GLFW/glfw3.h>
#include "ShapeDrawer.h"
#include "LabirinthDrawer.h"

LabirinthDrawer::LabirinthDrawer(int texture, Labirinth *labirinth){
	this->texture = texture;
    this->labirinth = labirinth;
}

void LabirinthDrawer::drawCubeAt(int i, int j){
    //30x30 
	int size = 20;
	int cubeSize = 2;

	i = (i-(size/2))*cubeSize;

	j = (j-(size/2))*cubeSize;
	j +=4*cubeSize;



	glPushMatrix();
	glTranslatef(i, 0, -j);

	ShapeDrawer::cube(this->texture);

	glPopMatrix();
}
void LabirinthDrawer::drawFloorCeilAt(int i, int j, int fc){

	int size = 20;
	int faceSize = 2;

	i = (i-(size/2))*faceSize;

	j = (j-(size/2))*faceSize;
	j +=4*faceSize;


	glPushMatrix();
//    glRotatef(10, 1 , 0, 0);
	glTranslatef(i, (fc?-2:fc) , -j);

	ShapeDrawer::square(this->texture);

	glPopMatrix();

}
void LabirinthDrawer::draw(){//int **wallMatrix, int alt, int larg){
    glPushMatrix();
    glScalef(4,4,4);

//    glTranslatef(0,0,10.0f);
/*
    int labirinth[5][5] = { {1,0,1,1,1},
    {1,0,1,1,1},
    {1,0,0,1,1},
    {1,1,0,1,1},
    {1,1,0,1,1}};*/
    int i, j;
    for(i = 1; i < 21; i++){
        for(j = 1; j < 21; j++){
            if(j < 20 && i < 20 && j > 1 && i > 1 ){
                if(!this->labirinth->getBlockAt(i-1,j-1)){
                    LabirinthDrawer::drawCubeAt(i+1,j+1);
                }else{
                    LabirinthDrawer::drawFloorCeilAt(i+1,j+1,0);
                    LabirinthDrawer::drawFloorCeilAt(i+1,j+1,1);

                }

            }else{
                LabirinthDrawer::drawCubeAt(i,j);
            }
        }
    }

    glPopMatrix();
}