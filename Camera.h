#ifndef CAMERA_H
#define CAMERA_H

#include "LabirinthDrawer.h"
#include "Character.h"

class Camera
{	
	private:
		float angle, angleSpeed, fraction;
		float lx,lz;
		float x,z;
		float initialX, initialZ;
		LabirinthDrawer *labirinthDrawer;
		Character *character;
	public:
		Camera(float,float, LabirinthDrawer *labirinthDrawer, Character *character);
		void processKeyboardInput(GLFWwindow*, float deltaT);
		void look();
		void getEye(float *eye);
		void getDirection(float *direction);
		float getAngle();
};

#endif



