#include "Object.h"
#include "Cloud.h"

Cloud::Cloud(float X, float Y, float Z) : Object (X, Y, Z){ }

void Cloud::draw(void){
     glPushMatrix();
       glTranslatef(posX+1,posY+1,posZ+1);
       glColor3f(1,1,1);
       glutSolidSphere(20,40,40);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(posX-15,posY+15,posZ);     
       glColor3f(1,1,1);
       glutSolidSphere(20,40,40);
     glPopMatrix();
     
     glPushMatrix();
       glTranslatef(posX+15,posY-15,posZ);          
       glColor3f(1,1,1);
       glutSolidSphere(20,40,40);
     glPopMatrix();     
     
     glPushMatrix();
       glTranslatef(posX-15,posY-15,posZ);          
       glColor3f(1,1,1);
       glutSolidSphere(20,40,40);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(posX+15,posY+15,posZ);          
       glColor3f(1,1,1);
       glutSolidSphere(20,40,40);
     glPopMatrix();    
}

void Cloud::action(){
	if (posX > 200 || posX < -100)
	{
		sentido = -sentido;
	}
	posX += (10 * sentido);
	//rotX += 10;
}
