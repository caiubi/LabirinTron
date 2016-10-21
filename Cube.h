void drawCube(int i, int j, float rot){
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

	glRotatef(rot, 0 , 0, 1);
	glTranslatef(i, 0, j);

    /* We have a color array and a vertex array */
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);

    /* Send data : 24 vertices */
	glDrawArrays(GL_QUADS, 0, 24);

    /* Cleanup states */
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
