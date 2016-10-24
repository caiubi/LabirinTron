#ifndef CAMERA_H
#define CAMERA_H

#include "LabirinthDrawer.h"

class Camera
{	
	private:
		float angle, angleSpeed, fraction;// actual vector representing the camera's direction
		float lx,lz;// XZ position of the camera
		float x,z;
		LabirinthDrawer *labirinthDrawer;
	public:
		Camera(float,float, LabirinthDrawer *labirinthDrawer);
		void processKeyboardInput(GLFWwindow*, float deltaT);
		void look();
		void getEye(float *eye);
		void getDirection(float *direction);
};

#endif



