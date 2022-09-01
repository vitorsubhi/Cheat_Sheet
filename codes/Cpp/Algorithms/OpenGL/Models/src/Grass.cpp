#include "Object.h"
#include "Grass.h"

Grass::Grass(float X, float Y, float Z) : Object (X, Y, Z){ }

void Grass::draw(void){
	glPushMatrix();	
		glColor3f(0.0, 0.5, 0.0);
		glRotatef(rotX, 1, 0, 0);
		glRotatef(rotY, 0, 1, 0);
		glRotatef(rotZ, 0, 0, 1);

		glBegin(GL_QUADS); //Floor
			glVertex3f(posX-width, posY-2, posZ+length);
			glVertex3f(posX+width, posY-2, posZ+length);
			glVertex3f(posX+width, posY-2, posZ-length);
			glVertex3f(posX-width, posY-2, posZ-length);
		glEnd();
	glPopMatrix();
}

void Grass::setWidth(float w){ this->width = w; }
void Grass::setLength(float l){ this->length = l; }
