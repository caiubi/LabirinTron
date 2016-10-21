#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

using namespace std;

#include "glUtils.h"
#include "Camera.h"

Camera::Camera(){
    fraction = 12.0f;
    angleSpeed = 2.0;
	angle=0.0;
	lx=0.0f;
	lz=-1.0f;
	x=0.0f;
	z=5.0f;
}

void Camera::processKeyboardInput(GLFWwindow* window, float deltaT){
	if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
		x += lx * fraction*deltaT;
		z += lz * fraction*deltaT;
	}else if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
		x -= lx * fraction*deltaT;
		z -= lz * fraction*deltaT;
	}
	if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
		angle -= angleSpeed*deltaT;
		lx = sin(angle);
		lz = -cos(angle);
	}else if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
		angle += angleSpeed*deltaT;
		lx = sin(angle);
		lz = -cos(angle);  
	}
}

void Camera::look(){
	glLookAt(  x, 1.0f, z, x+lx, 1.0f,  z+lz, 0.0f, 1.0f,  0.0f);
}