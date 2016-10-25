#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

#include "ShapeDrawer.h"
#include "LabirinthDrawer.h"

LabirinthDrawer::LabirinthDrawer(int textureCube, int textureFc, Labirinth *labirinth){
	this->textureCube = textureCube;
    this->textureFc = textureFc;
    this->labirinth = labirinth;
    mx = 17.7; //Valores calibrados
    my = -9.3; //Valores calibrados
    mspeed = 0.245;
}

void LabirinthDrawer::drawCubeAt(int i, int j){
    float position[] = {0,0,0};

    getIndexPosition(i, j, position);


    glPushMatrix();
    glTranslatef(position[0], position[1], position[2]);

    ShapeDrawer::cube(this->textureCube);

    glPopMatrix();
}
void LabirinthDrawer::drawFloorCeilAt(int i, int j, int fc){

    float position[] = {0,0,0};

    getIndexPosition(i, j, position);


    glPushMatrix();
    glTranslatef(position[0], (fc?-2:fc), position[2]);


    ShapeDrawer::square(this->textureFc);

    glPopMatrix();

}
void LabirinthDrawer::draw(){//int **wallMatrix, int alt, int larg){
    glPushMatrix();
    glScalef(4,4,4);

   float matAmbAndDif[] = {1.0, 1.0, 1.0, 1.0};    // cor ambiente e difusa: branca

   float corInicio[] = {0.5, 0.5, 1.0, 1.0};    // cor ambiente e difusa: verde
   float corFim[] = {1.0, 0.5, 0.5, 1.0};    // cor ambiente e difusa: verde

    // Definindo as propriedades do material


   int i, j;
   for(i = 0; i <= 21; i++){
    for(j = 0; j <= 21; j++){
        if(i < 2 && j < 2){
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, corInicio);
        }else if(i > 19 && j > 19){
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, corFim);
        }else{
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
        }
        if(j <= 20 && i <= 20 && j > 0 && i > 0 ){

            if(!this->labirinth->getBlockAt(i-1,j-1)){

                LabirinthDrawer::drawCubeAt(i,j);
//                    LabirinthDrawer::drawFloorCeilAt(i,j,1);

            }else{
                LabirinthDrawer::drawFloorCeilAt(i,j,0);
                LabirinthDrawer::drawFloorCeilAt(i,j,1);

            }

        }else{
            LabirinthDrawer::drawCubeAt(i,j);
        }
    }
}

glPopMatrix();
}


void LabirinthDrawer::getIndexPosition(int i, int j, float *vec){
    int n = 20;
    int size = 2;

    vec[0] = (i-(n/2))*size;

    vec[2] = (j-(n/2))*size + 4*size;
    vec[2] = -vec[2];


}

void LabirinthDrawer::getPositionIndex(int *i, int *j, float *vec3){
    int n = 20;
    int size = 2;
    float vec[] = {vec3[0]/4.0f, vec3[1]/4.0f, vec3[2]/4.0f};

    vec[2] = -vec[2];
    *j = -((4*size - vec[2])/size)+(n/2);
    *i = (vec[0]/size)+(n/2);

}

void LabirinthDrawer::drawMinimap(float *pos){
    float size = 2;
    glPushMatrix();
    glDisable(GL_LIGHTING);

    glTranslatef(0.5,0,-2);

    glScalef(0.02,0.02,0.02);

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glRotatef(-90, 0, 1, 0);

    glTranslatef(mx,0,my);
    glTranslatef(pos[0]*mspeed,pos[1]*mspeed,pos[2]*mspeed);
    glColor3f(1,0,1);
    ShapeDrawer::circle(0,0, 0.5, 360);
    glPopMatrix();

    glRotatef(-90, 1, 0, 0);
    glRotatef(90, 0, 1, 0);


    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            glPushMatrix();
            glTranslatef(((float)i)*size, 0, ((float)j)*size);
            if(i == 0 && j == 0){
                glColor3f(0,0,1);
                ShapeDrawer::circle(0,0, 1, 360);                    
            }else if(i == 19 && j == 19){
                glColor3f(1,0,0);
                ShapeDrawer::circle(0,0, 1, 360);                                        
            }
            if(!this->labirinth->getBlockAt(i,j)){
                ShapeDrawer::square(-1);
            }
            glPopMatrix();
        }
    }
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

bool LabirinthDrawer::collidesWith(float *vec){
    float position[] = {0,0,0};
    float side = 5.5f;
    bool xColl = false, zColl = false;
//    return false;
    for(int i = 0; i <= 21; i++){
        for(int j = 0; j <= 21; j++){
            getIndexPosition(i, j, position);
            position[0] = position[0]*4;
            position[1] = position[1]*4;
            position[2] = position[2]*4;

            xColl = (position[0]-side < vec[0] && position[0]+side > vec[0]);
            zColl = (position[2]-side < vec[2] && position[2]+side > vec[2]);

            if(xColl && zColl && !this->labirinth->getBlockAt(i-1,j-1)){
                return true;
            }
        }
    }
    return false;
}

bool LabirinthDrawer::endsIn(float *vec){
    float position[] = {0,0,0};
    float side = 5.0f;
    bool xColl = false, zColl = false;
    getIndexPosition(20, 20, position);
    position[0] = position[0]*4;
    position[1] = position[1]*4;
    position[2] = position[2]*4;


    xColl = (position[0]-side < vec[0] && position[0]+side > vec[0]);
    zColl = (position[2]-side < vec[2] && position[2]+side > vec[2]);

    if(xColl && zColl){
        return true;
    }
    return false;

}

//Debug para calcular os valores do minimapa
void LabirinthDrawer::inc(float mx, float my, float mspeed){
    this->mx +=mx;
    this->my +=my;
    this->mspeed +=mspeed;

    cout << "[ " << this->mx << ", " << this->my << ", " << this->mspeed << "] " <<endl;
}
