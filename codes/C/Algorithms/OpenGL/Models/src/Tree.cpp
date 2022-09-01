#include "Object.h"
#include "Tree.h"

Tree::Tree(float X, float Y, float Z) : Object (X, Y, Z){ }

void Tree::draw(void){
	if (model == 1)
	{
		glPushMatrix();
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 1, 0, 0);
			glRotatef(rotZ, 1, 0, 0);

			glPushMatrix(); //Leaves
				glColor3f(0.0,1.0,0.0);
				glTranslatef(posX,posY+35,posZ);
				glScalef(1.0,1.0,1.0);
				glutSolidSphere(9,100,100);
			glPopMatrix();

			glPushMatrix(); //Trunk
				glColor3f(0.5,0.3,0.2);
				glTranslatef(posX,posY+25, posZ);
				glScalef(0.3,4.0,0.3);
				glutSolidSphere(3,100,100);
			glPopMatrix();
		glPopMatrix();
	}
	else if (model == 2)
	{
		glPushMatrix();
			glColor3f(0,1,0);
			glTranslatef(posX,posY+50, posZ);
			glRotatef(-90,1,0,0);
			glRotatef(45,0,0,1);
			glutSolidCone(10,50,43,43);
		glPopMatrix();
 
		glPushMatrix();
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 1, 0, 0);
			glRotatef(rotZ, 1, 0, 0);

			glPushMatrix(); //Trunk
				glColor3f(0.5,0.3,0.2);
				glTranslatef(posX,posY+50, posZ);
				glScalef(0.3,15.0,0.3);
				glutSolidSphere(3,100,100);
			glPopMatrix();
		glPopMatrix();
	}
}

void Tree::setModel(unsigned int md){
	this->model = md;
}

unsigned int Tree::getModel(){
	return model;
}
