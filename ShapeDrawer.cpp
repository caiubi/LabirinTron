#include <GLFW/glfw3.h>
#include <cmath>
#include "ShapeDrawer.h"

void ShapeDrawer::square(int texture){
	GLfloat vertices[] =
	{
		-1,  1, -1,   -1,  1,  1,    1,  1,  1,    1,  1, -1
	};

/*		GLfloat verticesBottom[] = 
		{
			-1, -1, -1,   -1, -1,  1,    1, -1,  1,    1, -1, -1
		};*/

	GLfloat colors[] =
	{
		1, 1, 0,   1, 1, 0,   1, 1, 0,   1, 1, 0
	};

	GLfloat textureVertices[] = 
	{
		0, 0,   1, 0,   1, 1,   0, 1
	};

	    GLfloat normals[] =
    {
        0,1,0,  0,1,0,  0,1,0,  0,1,0 //Top
    };
    



	glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    if(texture != -1){
		glEnable(GL_TEXTURE_2D);
    	glEnableClientState(GL_TEXTURE_COORD_ARRAY);	
    }else{

	    glEnableClientState(GL_COLOR_ARRAY);
    }

    if(texture != -1){
    	glBindTexture(GL_TEXTURE_2D, texture);
    }

	glVertexPointer(3, GL_FLOAT, 0, vertices);

    if(texture != -1){
		glTexCoordPointer(2, GL_FLOAT, 0, textureVertices);
    }else{
	    glColorPointer(3, GL_FLOAT, 0, colors);
    }
    glNormalPointer(GL_FLOAT, 0, normals);

    /* Send data : 24 vertices */

	glDrawArrays(GL_QUADS, 0, 4);

    /* Cleanup states */
    if(texture != -1){
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisable(GL_TEXTURE_2D);
    }else{
	    glDisableClientState(GL_COLOR_ARRAY);
    }
    glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

}

void ShapeDrawer::circle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
        float x = r * cosf(theta);//calculate the x component 
        float y = r * sinf(theta);//calculate the y component 
        glVertex3f(x + cx, 0,  y + cy);//output vertex 
    }
    glEnd();
}


void ShapeDrawer::cube(int texture){
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

    GLfloat normals[] =
    {
        -1,0,0, -1,0,0,  -1,0,0, -1,0,0,  //Left
        1,0,0,   1,0,0,   1,0,0,  1,0,0, //Right
        0,-1,0,  0,-1,0,  0,-1,0, 0,-1,0, //Bottom
        0,1,0,  0,1,0,  0,1,0,  0,1,0, //Top
        0,0,-1, 0,0,-1, 0,0,-1, 0,0,-1, //front
        0,0,1,  0,0,1,  0,0,1,  0,0,1 //back
    };
    
	


	glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
//    glEnableClientState (GL_TEXTURE_COORD_ARRAY_EXT);
    if(texture != -1){
		glEnable(GL_TEXTURE_2D);
    	glEnableClientState(GL_TEXTURE_COORD_ARRAY);	
    }else{
	    glEnableClientState(GL_COLOR_ARRAY);
    }

    if(texture != -1){
    	glBindTexture(GL_TEXTURE_2D, texture);
    }

	glVertexPointer(3, GL_FLOAT, 0, vertices);
    
    if(texture != -1){
		glTexCoordPointer(2, GL_FLOAT, 0, textureVertices);
    }else{
	    glColorPointer(3, GL_FLOAT, 0, colors);
    }
    glNormalPointer(GL_FLOAT, 0, normals);


    /* Send data : 24 vertices */
	glDrawArrays(GL_QUADS, 0, 24);

    /* Cleanup states */
//    glDisableClientState (GL_TEXTURE_COORD_ARRAY_EXT);
    if(texture != -1){
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisable(GL_TEXTURE_2D);
    }else{
	    glDisableClientState(GL_COLOR_ARRAY);
    }
    glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

