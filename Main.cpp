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

static bool light0Ligada = 1;   // Luz branca ligada?

void configuraLuz(){
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };

   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
}

void setLuz(){    

   glPushMatrix();
   GLfloat light_position[] = {0, 1, 0.217664, 1.0 };
/*   camera->getEye(light_position);
   cout << light_position[0] << ", " << light_position[1] << ", " << light_position[2] << endl;
*/
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glPopMatrix();

}

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
        glPerspective(45, ratio, 1.0f, 200.0f);

        glMatrixMode(GL_MODELVIEW_MATRIX);

        setLuz();


        camera->look();

//        glRotatef(90, 1, 0, 0);
       glTranslatef(72,0,-36);
       labirinthDrawer->draw();
  //      glLookAt(  x, 1.0f, z, x+lx, 1.0f,  z+lz, 0.0f, 1.0f,  0.0f);

//        desenhaPersonagem();
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
    GLuint texture, texture2;
    camera = new Camera();
    GLFWwindow* window = initWindow("Labirinth", 1024, 620, controls);
    if( NULL != window )
    {
        texture = carregaTextura("bg.jpg");
        texture2 = carregaTextura("bg2.jpg");
        labirinth = new Labirinth(20,20);
        labirinth->generate();
        labirinth->print();
        labirinthDrawer = new LabirinthDrawer(texture, texture2, labirinth);
        configuraLuz();
        display( window );
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}