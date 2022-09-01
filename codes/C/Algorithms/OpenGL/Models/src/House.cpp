#include "Object.h"
#include "House.h"

House::House(float X, float Y, float Z) : Object (X, Y, Z){ }

void House::draw(void){
	glPushMatrix();
		glColor3f(0.3,0.8,0.5);
		glTranslatef(posX, posY, posZ);
		glutSolidCube(60);
	glPopMatrix();

	glPushMatrix();
		glColor3f(1,0,0);
		glTranslatef(posX,posY+30, posZ);
		glRotatef(-90,1,0,0);
		glRotatef(45,0,0,1);
		glutSolidCone(60,20,4,4);
	glPopMatrix();
     
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(posX+11,posY+11,posZ+30);
		glutSolidCube(18);
	glPopMatrix();
     
	glPushMatrix();
		glColor3f(0.8,0.8,0.8);
		glTranslatef(posX-11,posY+9,posZ+30);
		glutSolidCube(18);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.8,0.8,0.8);
		glTranslatef(posX-11,posY-9,posZ+30);
		glutSolidCube(18);
	glPopMatrix();
}
