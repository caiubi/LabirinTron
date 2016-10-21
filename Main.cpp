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

GLuint texture;

Camera *camera;
LabirinthDrawer *labirinthDrawer;
Labirinth *labirinth;
double currentFrame, deltaTime, lastFrame, t = 0;

void controls(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS){
        if(key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, GL_TRUE);
            
    }
}

void display( GLFWwindow* window )
{
    float ratio;
    static float angle = 0;
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

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
//        glFrustum(-ratio, ratio, -1.0f, 1.0f, 1.0f, 100.0f);
        glPerspective(45, ratio, 1.0f, 100.0f);

        glMatrixMode(GL_MODELVIEW_MATRIX);


        camera->look();

        labirinthDrawer->draw();
  //      glLookAt(  x, 1.0f, z, x+lx, 1.0f,  z+lz, 0.0f, 1.0f,  0.0f);

//        desenhaPersonagem();

        glTranslatef(0,0,-8);
//        glRotatef(90, 1, 0, 0);
//        desenhaCenario();

        camera->processKeyboardInput(window, deltaTime);   

        // Update Screen
        glfwSwapBuffers(window);

        // Check for any input, or window movement
        glfwPollEvents();
    }
}

int main(int argc, char** argv)
{
    camera = new Camera();
    GLFWwindow* window = initWindow("Labirinth", 1024, 620, controls);
    if( NULL != window )
    {
        texture = carregaTextura("bg.jpg");
        labirinth = new Labirinth(20,20);
        labirinth->generate();
        labirinthDrawer = new LabirinthDrawer(texture, labirinth);
        display( window );
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}


/*
    Labirinth *lab = new Labirinth(20,20);
    lab->generate();
    lab->print();
*/