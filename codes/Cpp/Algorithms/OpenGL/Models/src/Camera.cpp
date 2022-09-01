#include "Camera.h"

Camera::Camera(float X, float Y, float Z){
	this->obsX = X;
	this->obsY = Y;
	this->obsZ = Z;
}

void Camera::look(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(-obsX, -obsY, -obsZ);
	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);
}

void Camera::setObsX(float X){ this->obsX = X; }
void Camera::setObsY(float Y){ this->obsY = Y; }
void Camera::setObsZ(float Z){ this->obsZ = Z; }
void Camera::setObsPosition(float X, float Y, float Z) { this->obsX = X; this->obsY = Y; this->obsZ = Z; }

void Camera::setRotX(float X){ this->rotX = X; }
void Camera::setRotY(float Y){ this->rotY = Y; }

float Camera::getObsX(){ return this->obsX; }
float Camera::getObsY(){ return this->obsY; }
float Camera::getObsZ(){ return this->obsZ; }

float Camera::getRotX(){ return this->rotX; }
float Camera::getRotY(){ return this->rotY; }
