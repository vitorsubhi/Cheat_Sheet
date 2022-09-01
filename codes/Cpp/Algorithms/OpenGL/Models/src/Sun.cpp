#include "Object.h"
#include "Sun.h"

Sun::Sun(float X, float Y, float Z) : Object (X, Y, Z){ }

void Sun::draw(void){
	glPushMatrix();
		glColor3f(1.0,1.0,0);
		glTranslatef(posX,posY,posZ);
		glRotatef(rotX, 1, 0, 0);
		glRotatef(rotY, 0, 1, 0);
		glRotatef(rotZ, 0, 0, 1);
		glScalef(1.0,1.0,1.0);
		glutSolidSphere(20,80,80);
	glPopMatrix();
}

void Sun::action(){
	rotX += 10;
	rotY += 30;
	rotZ += 30;
}
