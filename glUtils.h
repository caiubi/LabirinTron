#ifndef GL_UTILS_H
#define GL_UTILS_H

void glPerspective(float fov, float aspectRatio, float znear, float zfar);

void normalize( float p[3] );

void cross(float a[3], float b[3], float c[3]);

void glLookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx,
 GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy,
 GLdouble upz);

int carregaTextura(char *imagePath);

#endif
