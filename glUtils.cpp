#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <SOIL.h>

using namespace std;

#include "glUtils.h"


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

int carregaTextura(string imagePath){
    int texture = SOIL_load_OGL_texture(
        imagePath.c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if (texture == 0 ) {
        cout << "Erro carregando textura..." << endl;
    }
    return texture;
}
