#include <GLFW/glfw3.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <SOIL.h>

GLuint texture;

float incZ = 0;
float rotY = 0;

// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z=5.0f;

void glPerspective(float fov, float aspectRatio, float znear, float zfar) {
    float ymax = znear * tanf(fov * M_PI / 360.0);
    float xmax = ymax * aspectRatio;

    glFrustum(-xmax, xmax, -ymax, ymax, znear, zfar);
}

void normalize( float p[3] )
{
    float w = sqrt( p[0] * p[0] + p[1] * p[1] + p[2] * p[2] );
    p[0] /= w;
    p[1] /= w;
    p[2] /= w;
}

void cross(float a[3], float b[3], float c[3]){
    c[0] = a[1]*b[2] - a[2]*b[1];
    c[1] = a[2]*b[0] - a[0]*b[2];
    c[2] = a[0]*b[1] - a[1]*b[0];
}

void glLookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx,
     GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy,
     GLdouble upz)
{
    int i;
    float forward[3], side[3], up[3];
    GLfloat m[4][4] = {{1, 0, 0 ,0},
         {0, 1, 0 ,0},
         {0, 0, 1 ,0},
         {0, 0, 0 ,1}}; 
 
    forward[0] = centerx - eyex;
    forward[1] = centery - eyey;
    forward[2] = centerz - eyez;
 
    up[0] = upx;
    up[1] = upy;
    up[2] = upz;
 
    normalize(forward);
 
    // Side = forward x up 
    cross(forward, up, side);
    normalize(side);
 
    // Recompute up as: up = side x forward 
    cross(side, forward, up);
 
    m[0][0] = side[0];
    m[1][0] = side[1];
    m[2][0] = side[2];
 
    m[0][1] = up[0];
    m[1][1] = up[1];
    m[2][1] = up[2];
 
    m[0][2] = -forward[0];
    m[1][2] = -forward[1];
    m[2][2] = -forward[2];
 
    glMultMatrixf(&m[0][0]);
    glTranslated(-eyex, -eyey, -eyez);
}
void controls(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    float sp = 1.0f;
    float fraction = 1.0f;

    if(action == GLFW_PRESS){
        if(key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, GL_TRUE);
        if(key == GLFW_KEY_UP){
            x += lx * fraction;
            z += lz * fraction;
//            incZ += sp;


        }else if(key == GLFW_KEY_DOWN){
            x -= lx * fraction;
            z -= lz * fraction;
//            incZ -= sp;
        }
        if(key == GLFW_KEY_LEFT){
            angle -= 0.1f;
            lx = sin(angle);
            lz = -cos(angle);
//            rotY -= sp;
        }else if(key == GLFW_KEY_RIGHT){
            angle += 0.1f;
            lx = sin(angle);
            lz = -cos(angle);  
//            rotY += sp;
        }
    }
}

void carregaTextura(char *imagePath){
    texture = SOIL_load_OGL_texture(
        imagePath,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if (texture == 0 ) {
        printf("Erro carregando textura...\n");
    }
}


void drawFace(int i, int j, int bottomTop){
    //30x30 
    int size = 10;
    int faceSize = 2;

    i = (i-(size/2))*faceSize;

    j = (j-(size/2))*faceSize;
    j +=4*faceSize;

    GLfloat verticesTop[] =
    {
        -1,  1, -1,   -1,  1,  1,    1,  1,  1,    1,  1, -1
    };

    GLfloat verticesBottom[] = 
    {
        -1, -1, -1,   -1, -1,  1,    1, -1,  1,    1, -1, -1
    };

    GLfloat colors[] =
    {
        1, 0, 0,   1, 0, 1,   1, 1, 1,   1, 1, 0
    };

    GLfloat textureVertices[] = 
    {
        0, 0,   1, 0,   1, 1,   0, 1
    };

    glPushMatrix();
//    glRotatef(10, 1 , 0, 0);
    glTranslatef(i, 0, -j);

    glEnable(GL_TEXTURE_2D);
    /* We have a color array and a vertex array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//    glEnableClientState (GL_TEXTURE_COORD_ARRAY_EXT);
//    glEnableClientState(GL_COLOR_ARRAY);

    glBindTexture(GL_TEXTURE_2D, texture);

    if(!bottomTop){
        glVertexPointer(3, GL_FLOAT, 0, verticesBottom);
    }else{
        glVertexPointer(3, GL_FLOAT, 0, verticesTop);
    }

//    glColorPointer(3, GL_FLOAT, 0, colors);
    glTexCoordPointer(2, GL_FLOAT, 0, textureVertices);

    /* Send data : 24 vertices */
    glDrawArrays(GL_LINE_LOOP, 0, 4);

    /* Cleanup states */

//    glDisableClientState (GL_TEXTURE_COORD_ARRAY_EXT);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}


void drawCube(int i, int j){
    //30x30 
    int size = 10;
    int cubeSize = 2;

    i = (i-(size/2))*cubeSize;

    j = (j-(size/2))*cubeSize;
    j +=4*cubeSize;

    GLfloat vertices[] =
    {
        -1, -1, -1,   -1, -1,  1,   -1,  1,  1,   -1,  1, -1,
        1, -1, -1,    1, -1,  1,    1,  1,  1,    1,  1, -1,
        -1, -1, -1,   -1, -1,  1,    1, -1,  1,    1, -1, -1,
        -1,  1, -1,   -1,  1,  1,    1,  1,  1,    1,  1, -1,
        -1, -1, -1,   -1,  1, -1,    1,  1, -1,    1, -1, -1,
        -1, -1,  1,   -1,  1,  1,    1,  1,  1,    1, -1,  1
    };

    GLfloat colors[] =
    {
        0, 0, 0,   0, 0, 1,   0, 1, 1,   0, 1, 0,
        1, 0, 0,   1, 0, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 0, 1,   1, 0, 1,   1, 0, 0,
        0, 1, 0,   0, 1, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 1, 0,   1, 1, 0,   1, 0, 0,
        0, 0, 1,   0, 1, 1,   1, 1, 1,   1, 0, 1
    };

    GLfloat textureVertices[] = 
    {
        0, 0,   1, 0,   1, 1,   0, 1,
        0, 0,   1, 0,   1, 1,   0, 1,
        0, 0,   1, 0,   1, 1,   0, 1,
        0, 0,   1, 0,   1, 1,   0, 1,
        0, 0,   1, 0,   1, 1,   0, 1,
        0, 0,   1, 0,   1, 1,   0, 1
    };


    glPushMatrix();
//    glRotatef(10, 1 , 0, 0);
    glTranslatef(i, 0, -j);

    glEnable(GL_TEXTURE_2D);
    /* We have a color array and a vertex array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//    glEnableClientState (GL_TEXTURE_COORD_ARRAY_EXT);
//    glEnableClientState(GL_COLOR_ARRAY);

    glBindTexture(GL_TEXTURE_2D, texture);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, textureVertices);

//    glColorPointer(3, GL_FLOAT, 0, colors);

    /* Send data : 24 vertices */
    glDrawArrays(GL_QUADS, 0, 24);

    /* Cleanup states */
//    glDisableClientState (GL_TEXTURE_COORD_ARRAY_EXT);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

void desenhaCenario(){

    glPushMatrix();
    glScalef(4,4,4);

//    glTranslatef(0,0,10.0f);

    int labirinth[5][5] = { {1,0,1,1,1},
    {1,0,1,1,1},
    {1,0,0,1,1},
    {1,1,0,1,1},
    {1,1,0,1,1}};
    int i, j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(labirinth[i][j]){
                drawCube(i+1,j+1);
            }else{
                drawFace(i+1,j+1,0);
                drawFace(i+1,j+1,1);

            }
        }
    }

    glPopMatrix();
}

void desenhaPersonagem(){
  glPushMatrix();
  glTranslatef(0, -1, -8);

  drawCube(5,1);
  glPopMatrix();
//    glTranslatef(0, 1, 0);
}


void display( GLFWwindow* window )
{
    float ratio;
    static float angle = 0;

    while(!glfwWindowShouldClose(window))
    {
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



        glLookAt(  x, 1.0f, z, x+lx, 1.0f,  z+lz, 0.0f, 1.0f,  0.0f);

//        desenhaPersonagem();

        glTranslatef(0,0,-8);
        glRotatef(90, 1, 0, 0);
        desenhaCenario();

        // Update Screen
        glfwSwapBuffers(window);

        // Check for any input, or window movement
        glfwPollEvents();
    }
}

GLFWwindow* initWindow(const int resX, const int resY)
    {
        if(!glfwInit())
        {
            fprintf(stderr, "Failed to initialize GLFW\n");
            return NULL;
        }
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing

    // Open a window and create its OpenGL context
    GLFWwindow* window = glfwCreateWindow(resX, resY, "LabirinthScape", NULL, NULL);

    if(window == NULL)
    {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, controls);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
    
    // Get info of GPU and supported OpenGL version
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("OpenGL version supported %s\n", glGetString(GL_VERSION));

    glEnable(GL_DEPTH_TEST); // Depth Testing
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    return window;
}

int main(int argc, char** argv)
{
    GLFWwindow* window = initWindow(1024, 620);
    if( NULL != window )
    {
        carregaTextura("bg.jpg");
        display( window );
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}