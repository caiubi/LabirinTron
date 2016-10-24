#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

using namespace std;

#include "glUtils.h"
#include "Camera.h"

Camera::Camera(float x, float z, LabirinthDrawer *labirinthDrawer){
    fraction = 24.0f;
    angleSpeed = 3.0;
	angle=0.0;
	lx=0.0f;
	lz=-1.0f;
	this->labirinthDrawer = labirinthDrawer;
	this->x = x;//0.0f;
	this->z = z;//5.0f;
}

void Camera::processKeyboardInput(GLFWwindow* window, float deltaT){
	float up[] = {x+(lx * fraction*deltaT), 0, z+(lz * fraction*deltaT)};
	float down[] = {x-(lx * fraction*deltaT), 0, z-(lz * fraction*deltaT)};
	float inc = 0.1, sp = 0.001;
	if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
		if(!labirinthDrawer->collidesWith(up)){
			x += lx * fraction*deltaT;			
			z += lz * fraction*deltaT;		
		}
	}else if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
		if(!labirinthDrawer->collidesWith(down)){
			x -= lx * fraction*deltaT;
			z -= lz * fraction*deltaT;
		}
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
/*
	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
		labirinthDrawer->inc(-inc,0,0);
	}else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
		labirinthDrawer->inc(inc,0,0);
	}

	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
		labirinthDrawer->inc(0,inc,0);
	}else if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
		labirinthDrawer->inc(0,-inc,0);
	}

	if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
		labirinthDrawer->inc(0,0,-sp);
	}else if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
		labirinthDrawer->inc(0,0,sp);
	}*/
		
}

void Camera::look(){
	glLookAt(x, 1.0f, z, x+lx, 1.0f,  z+lz, 0.0f, 1.0f,  0.0f);
}

void Camera::getEye(float *eye){
	eye[0] = x;
	eye[1] = 1.0f;
	eye[2] = z;
}

void Camera::getDirection(float *direction){
	direction[0] = lx;
	direction[1] = 0;
	direction[2] = lz;
}

float Camera::getAngle(){
	return this->angle;
}