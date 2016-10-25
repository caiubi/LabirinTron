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
#include "Character.h"



Camera *camera;
LabirinthDrawer *labirinthDrawer;
Labirinth *labirinth;
Character *character;
double currentFrame, deltaTime, lastFrame, t = 0;
bool thirdPerson = false;
bool minimap = false;

int aim;
float spin = 0;


void configuraLuz(){
 glShadeModel (GL_SMOOTH);
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}

void setLuz(){    
    GLfloat position[] = { 0.0, 0.0, -3, 1.0 };

    glPushMatrix ();
    glTranslatef (0.0, 0.0, position[2]);

    glPushMatrix ();
    glLightfv (GL_LIGHT0, GL_POSITION, position);

    glTranslated (0.0, 0.0, position[2]);
    glDisable (GL_LIGHTING);
    glColor3f (1.0, 1.0, 1.0);

    glPushMatrix();
    glScaled(0.1,0.1,0.1);
    ShapeDrawer::cube(aim);
    glPopMatrix();

    glEnable (GL_LIGHTING);
    glPopMatrix ();
}

void controls(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS){
        if(key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, GL_TRUE);
        if(key == GLFW_KEY_3){
            thirdPerson = !thirdPerson;
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

        if(thirdPerson){
            character->draw();
        }

        camera->look();

        labirinthDrawer->draw();



        camera->processKeyboardInput(window, deltaTime);   

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}

int main(int argc, char** argv)
{
    GLuint texture, texture2, texturePlayer;
    GLFWwindow* window = initWindow("Labirinth", 1024, 620, controls);
    if( NULL != window )
    {
        glfwWindowHint(GLFW_REFRESH_RATE, 60);
        texture = aim = carregaTextura("bg3.png");
        texture2 = carregaTextura("bg.png");
        texturePlayer = carregaTextura("bgPLayer.png");

        labirinth = new Labirinth(20,20);
        labirinth->generate();
        labirinth->print();
        character = new Character(texturePlayer);
        labirinthDrawer = new LabirinthDrawer(texture, texture2, labirinth);
        camera = new Camera(-72, 40, labirinthDrawer, character);
        display( window );
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}