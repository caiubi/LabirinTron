#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <SOIL.h>

using namespace std;

#include "windowConfig.h"
#include "glUtils.h"
#include "ShapeDrawer.h"
#include "LabirinthDrawer.h"
#include "Camera.h"
#include "Labirinth.h"



Camera *camera;
LabirinthDrawer *labirinthDrawer;
Labirinth *labirinth;
double currentFrame, deltaTime, lastFrame, t = 0;
bool rot = false;
bool minimap = false;
int testeura;
float spin = 0;

void configuraLuz(){
 glShadeModel (GL_SMOOTH);
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);


}

void setLuz(){    
    GLfloat position[] = { 0.0, 0.0, -3, 1.0 };

    glPushMatrix ();
//        glRotated ((GLdouble) 50*glfwGetTime(), 1.0, 0.0, 0.0);
    glTranslatef (0.0, 0.0, position[2]);

    glPushMatrix ();
    glLightfv (GL_LIGHT0, GL_POSITION, position);

    glTranslated (0.0, 0.0, position[2]);
    glDisable (GL_LIGHTING);
    glColor3f (1.0, 1.0, 1.0);

    glPushMatrix();
    glScaled(0.1,0.1,0.1);
    ShapeDrawer::cube(testeura);
    glPopMatrix();

    glEnable (GL_LIGHTING);
    glPopMatrix ();
}

void controls(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS){
        if(key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, GL_TRUE);
        if(key == GLFW_KEY_R){
            rot = !rot;
        }
        if(key == GLFW_KEY_M){
            minimap = !minimap;
        }
/*        if(key == GLFW_KEY_B){
            bp = !bp;
        }*/
    }
}

void display( GLFWwindow* window )
{
    float ratio;
    static float angle = 0;
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

    float position[] = {0,0,0};
    int pi, pj;

    configuraLuz();

    while(!glfwWindowShouldClose(window))
    {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Scale to window size
        GLint windowWidth, windowHeight;
        glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
//        printf("w %d, h %d\n", windowWidth, windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);

        ratio = windowWidth / (float) windowHeight;

//        printf("ratio: %f\n", ratio);
        // Draw stuff
        glClearColor(0.0, 0.8, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION_MATRIX);
        glLoadIdentity();

        glPerspective(45, ratio, 1.0f, 200.0f);

        glMatrixMode(GL_MODELVIEW_MATRIX);

        if(minimap){
            camera->getEye(position);
            labirinthDrawer->drawMinimap(position);
        }

        setLuz();

//        ShapeDrawer::cube(testeura);
        camera->look();
//        labirinthDrawer->draw();


/*
        glRotated ((GLdouble) -50*glfwGetTime(), 0.0, 1.0, 0.0);
        glScaled(0.5,0.5,0.5);
        glTranslatef(2,0,0);
        ShapeDrawer::cube(testeura);
        glTranslatef(-4,0,0);
        ShapeDrawer::cube(testeura);
//    glutSolidCube(1);
        glPopMatrix ();*/


//        glPushMatrix();
//        camera->look();

//       cout << position[0] << ", " << position[1] << ", " << position[2] << endl;

//       glRotatef(90, 1, 0 ,0 );
        labirinthDrawer->draw();



        camera->processKeyboardInput(window, deltaTime);   
        // Update Screen
        glfwSwapBuffers(window);
        // Check for any input, or window movement
        glfwPollEvents();
    }
}

int main(int argc, char** argv)
{
    GLuint texture, texture2;
    GLFWwindow* window = initWindow("Labirinth", 1024, 620, controls);
    if( NULL != window )
    {
        glfwWindowHint(GLFW_REFRESH_RATE, 60);
        texture = testeura = carregaTextura("bg3.png");
        texture2 = carregaTextura("bg.png");
//        texture = testeura = carregaTextura("bg3.png");
//        texture2 = carregaTextura("bg2.jpg");
        labirinth = new Labirinth(20,20);
        labirinth->generate();
        labirinth->print();
        labirinthDrawer = new LabirinthDrawer(texture, texture2, labirinth);
        camera = new Camera(-72, 40, labirinthDrawer);
//        configuraLuz();
        display( window );
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}