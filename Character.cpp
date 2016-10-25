#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "Character.h"
#include "ShapeDrawer.h"

Character::Character(int texture){
	this->frame = 0;
	this->texture = texture;
}

void Character::updateFrame(float deltaT){
	float frameSpeed = 10.0;
	this->frame += frameSpeed*deltaT;
	if(this->frame > 2*M_PI){
		this->frame -= 2*M_PI;
	}
}

void Character::draw(){
	glPushMatrix();
        glTranslatef(0, -3, -10);
        glScaled(0.5,0.5,0.5);
//		glRotatef(90, 0, 1, 0);
		glPushMatrix();
			glTranslatef(0, 1, 0);
			ShapeDrawer::cube(this->texture);
		glPopMatrix();
		glPushMatrix();
			glScaled(0.4,0.4,0.4);
			glTranslatef(-1.5, 0, 0);
			ShapeDrawer::cube(this->texture);
			glTranslatef(3, 0, 0);
			ShapeDrawer::cube(this->texture);
		glPopMatrix();
		
		glPushMatrix();
			glRotatef(sin(frame)*45, 1, 0, 0);
			glTranslatef(1,-1,0);
			glScaled(0.5,0.5,0.5);
			ShapeDrawer::cube(this->texture);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-sin(frame)*45, 1, 0, 0);
			glTranslatef(-1,-1,0);
			glScaled(0.5,0.5,0.5);
			ShapeDrawer::cube(this->texture);
		glPopMatrix();

	glPopMatrix();
    glTranslatef(0, 0, -10);

}