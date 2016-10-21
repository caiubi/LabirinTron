#ifndef CAMERA_H
#define CAMERA_H

class Camera
{	
	private:
		float angle, angleSpeed, fraction;// actual vector representing the camera's direction
		float lx,lz;// XZ position of the camera
		float x,z;
	public:
		Camera();
		void processKeyboardInput(GLFWwindow*, float deltaT);
		void look();
};

#endif



