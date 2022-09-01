#include "Object.h"
#include "Street.h"

Street::Street(float X, float Y, float Z) : Object (X, Y, Z){ }

void Street::draw(void){
	glPushMatrix();	
		glColor3f(0.3, 0.3, 0.3);
		glRotatef(rotX, 1, 0, 0);
		glRotatef(rotY, 0, 1, 0);
		glRotatef(rotZ, 0, 0, 1);

		glBegin(GL_QUADS); //Floor
			glVertex3f(posX-width, posY-2, posZ+length);
			glVertex3f(posX+width, posY-2, posZ+length);
			glVertex3f(posX+width, posY-2, posZ-length);
			glVertex3f(posX-width, posY-2, posZ-length);
		glEnd();
	
		float a = (width/10);
		
		glBegin(GL_QUADS);
			glColor3f(1.0, 1.0, 0.0);
			glVertex3f(posX-a, posY-1, posZ+length);
			glVertex3f(posX+a, posY-1, posZ+length);
			glVertex3f(posX+a, posY-1, posZ-length);
			glVertex3f(posX-a, posY-1, posZ-length);
		glEnd();
	glPopMatrix();
}

void Street::setWidth(float w){ this->width = w; }
void Street::setLength(float l){ this->length = l; }
