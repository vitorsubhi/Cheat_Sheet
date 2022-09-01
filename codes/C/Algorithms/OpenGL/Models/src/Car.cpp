#include "Object.h"
#include "Car.h"

Car::Car(float X, float Y, float Z) : Object (X, Y, Z){ }

void Car::draw(void){
	glPushMatrix();
		glRotatef(rotX, 1, 0, 0);
		glRotatef(rotY, 0, 1, 0);
		glRotatef(rotZ, 0, 0, 1);

		glPushMatrix();
			glColor3f(1,0,0);
			glTranslatef(posX, posY, posZ);
			glutSolidCube(15);
		glPopMatrix();
     
		glPushMatrix();
			glColor3f(1,0,0);
			glTranslatef(posX-15,posY,posZ);
			glScalef(1.5,1,1);
			glutSolidCube(15);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1,0,0);
			glTranslatef(posX+15,posY,posZ);
			glutSolidCube(15);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1,0,0);
			glTranslatef(posX-14,posY+10,posZ);
			glutSolidCube(16);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.9,0.9,0.9);
			glTranslatef(posX-12,posY+13,posZ);
			glScalef(1,1,2.4);
			glutSolidCube(8);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(posX-27,posY+2,posZ-5);
			glutSolidSphere(2,20,20);
		glPopMatrix();     
	
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(posX-27,posY+2,posZ+5);
			glutSolidSphere(2,20,20);
		glPopMatrix();     

		glPushMatrix();
			glColor3f(0,0,0);
			glTranslatef(posX-16,posY-7,posZ-7);
			glutSolidTorus(2,3,20,20);
		glPopMatrix();
     
		glPushMatrix();
			glColor3f(0,0,0);
			glTranslatef(posX-16,posY-7,posZ+7);
			glutSolidTorus(2,3,20,20);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0,0,0);
			glTranslatef(posX+16,posY-7,posZ-7);
			glutSolidTorus(2,3,20,20);
		glPopMatrix();
     
		glPushMatrix();
			glColor3f(0,0,0);
			glTranslatef(posX+16,posY-7,posZ+7);
			glutSolidTorus(2,3,20,20);
		glPopMatrix();

	glPopMatrix();

}

void Car::action(){
//	posX -= 10;
}
