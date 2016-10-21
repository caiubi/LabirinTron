#include <GLFW/glfw3.h>
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
		1, 0, 0,   1, 0, 1,   1, 1, 1,   1, 1, 0
	};

	GLfloat textureVertices[] = 
	{
		0, 0,   1, 0,   1, 1,   0, 1
	};


	glEnable(GL_TEXTURE_2D);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//    glEnableClientState (GL_TEXTURE_COORD_ARRAY_EXT);
//    glEnableClientState(GL_COLOR_ARRAY);

	glBindTexture(GL_TEXTURE_2D, texture);

	glVertexPointer(3, GL_FLOAT, 0, vertices);

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

	glEnable(GL_TEXTURE_2D);

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
}