#include "Object.h"
#include "Airplane.h"

Airplane::Airplane(float X, float Y, float Z) : Object (X, Y, Z){  }

void Airplane::draw(void){
	    GLUquadricObj *quadric;
		GLfloat asa[][3]={
		{-32.0,0.0,0.0},
		{+32.0,0.0,0.0},
		{0.0,0.0,24.0}
		};

		GLfloat cauda[][3]={
		{0.0,0.0,0.0},
		{0.0,16.0,-16.0},
		{0.0,16.0,0.0},
		{0.0,0.0,8.0}
		};
		glPushMatrix();
			glTranslatef(posX+0,posY+0,posZ);
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 0, 1, 0);
			glRotatef(rotZ, 1, 0, 0);
			
			glBegin(GL_TRIANGLES);
			
				glVertex3fv(asa[0]);
				glVertex3fv(asa[1]);
				glVertex3fv(asa[2]);
				
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 0, 1, 0);
			glRotatef(rotZ, 0, 0, 1);
			glTranslatef(posX+0,posY+0,posZ);
			quadric = gluNewQuadric();
			gluQuadricTexture(quadric, GL_TRUE);
			gluCylinder(quadric, 4.0, 4.0, 32, 96, 24);
		glPopMatrix();
		

 		quadric = gluNewQuadric();
		gluQuadricTexture(quadric, GL_TRUE);

		glPushMatrix();
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 0, 1, 0);
			glRotatef(rotZ, 0, 0, 1);
			glTranslatef(posX+0,posY+0,posZ+32);
			gluCylinder(quadric, 4.0, 0.0, 12.0, 80, 18);
			
		glPopMatrix();

		glPushMatrix();
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 0, 1, 0);
			glRotatef(rotZ, 0, 0, 1);
			glTranslatef(posX+0,posY+0,posZ);
			glBegin(GL_POLYGON);
				glVertex3fv(cauda[0]);
				glVertex3fv(cauda[1]);
				glVertex3fv(cauda[2]);
				glVertex3fv(cauda[3]);
				
			glEnd();
		glPopMatrix();

		
		glPushMatrix();
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 0, 1, 0);
			glRotatef(rotZ, 0, 0, 1);
			glTranslatef(posX+0,posY+0,posZ);
			glScalef(2.8,2.8 ,8.0);
			quadric=gluNewQuadric();
			glColor4f(0.3,0.5,1,0.5);
			glDisable(GL_TEXTURE_2D);
			gluSphere(quadric,1.0,24,24);
		glPopMatrix();
		
	glEndList();
}

void Airplane::action(){
	if (posZ > 450)
	{
		posZ = -450;
		posY = 80;
	}
	posZ += 10;
	posY += 1;
}
