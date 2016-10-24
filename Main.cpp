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

GLfloat  lightPos[] = { 0.0f, 0.0f, 75.0f, 1.0f };
GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat  ambientLight[] = { 0.5f, 0.5f, 0.5f, 1.0f};
GLfloat  spotDir[] = { 0.0f, 0.0f, -1.0f };

void configuraLuz(){
        glFrontFace(GL_CCW);       // Counterclockwise polygons face out
//        glEnable(GL_CULL_FACE);    // Do not try to display the back sides

        // Enable lighting
        glEnable(GL_LIGHTING);

        // Set up and enable light 0
        // Supply a slight ambient light so the objects can be seen
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

        // The light is composed of just diffuse and specular components
        glLightfv(GL_LIGHT0,GL_DIFFUSE,ambientLight);
        glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
        glLightfv(GL_LIGHT0,GL_POSITION,lightPos);

        // Specific spot effects
        // Cut off angle is 60 degrees
        glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,30.0f);

        // Fairly shiny spot
        glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,100.0f);

        // Enable this light in particular
        glEnable(GL_LIGHT0);

        // Enable color tracking
        glEnable(GL_COLOR_MATERIAL);

        // Set Material properties to follow glColor values
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

        // All materials hereafter have full specular reflectivity
        // with a high shine
        glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
        glMateriali(GL_FRONT, GL_SHININESS,128);
}

void setLuz(){    
/*

   GLfloat light_position[] = {0, 0, 0, 1};//1, 0.217664, 1.0 };
//   camera->getEye(light_position);
//   cout << light_position[0] << ", " << light_position[1] << ", " << light_position[2] << endl;

//   glTranslatef(10,-10,-10);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);*/

/*    camera->getEye(lightPos);
    camera->getDirection(spotDir);*/

    GLfloat light_position[] = {0, 0, 0, 1};
    GLfloat spot_dir[] = {0, 0, -1};
            glLightfv(GL_LIGHT0,GL_POSITION,light_position);//lightPos);
        glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spot_dir);

        // Draw a red cone to enclose the light source
//        glRGB(255,0,0);

        // Translate origin to move the cone out to where the light
        // is positioned.
        glPushMatrix();
        
        glDisable(GL_LIGHTING);
//        glTranslatef(lightPos[0],lightPos[1],lightPos[2]);
        glScaled(0.5, 0.5, 0.5);
        ShapeDrawer::cube(testeura);

//   cout << lightPos[0] << ", " << lightPos[1] << ", " << lightPos[2] << endl;
        
        
        glEnable(GL_LIGHTING);

        glPopMatrix();

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

//    configuraLuz();

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

//        glPushMatrix();
        if(minimap){
            camera->getEye(position);
            labirinthDrawer->drawMinimap(position);
        }
        camera->look();
//        glTranslatef(0, 0, -5);
//        ShapeDrawer::cube(testeura);
//        setLuz();
//        glTranslatef(0, 0, 5);
//        glPopMatrix();
//        texture = carregaTextura("bg3.png");
//        texture2 = carregaTextura("bg.png");

//        cout << labirinthDrawer->collidesWith(position) << endl;
//        cout << pi << ", " << pj << endl;

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
        texture = carregaTextura("bg3.png");
        texture2 = carregaTextura("bg.png");
//        texture = testeura = carregaTextura("bg.jpg");
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