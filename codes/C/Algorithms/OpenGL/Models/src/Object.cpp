#include "Object.h"

Object::Object(){
	this->posX = 0.0;	
	this->posY = 0.0;	
	this->posZ = 0.0;	
	currentThread = thread(bind(&Object::animate, this));	
}

Object::Object(float X, float Y, float Z){
	this->posX = X;
	this->posY = Y;
	this->posZ = Z;
	currentThread = thread(bind(&Object::animate, this));	
}

void Object::draw(void){
	glPushMatrix();
		glRotatef(rotX, 1, 0, 0);
		glRotatef(rotY, 0, 1, 0);
		glRotatef(rotZ, 0, 0, 1);
		glColor3f(0.0,0.0,0);
		glTranslatef(posX,posY,posZ);
		glScalef(2.0,3.0,1.0);
		glutSolidSphere(3,100,100);
	glPopMatrix();
}

void Object::action(){

}

void Object::animate(){
	while(true){
		this_thread::sleep_for(chrono::milliseconds(delay));
		thread a = thread(bind(&Object::action, this));
		a.join();
	}
}

void Object::setDelay(unsigned int ndelay){ this->delay = ndelay; }

void Object::setPosX(float X){ this->posX = X; }
void Object::setPosY(float Y){ this->posY = Y; }
void Object::setPosZ(float Z){ this->posZ = Z; }
void Object::setPosition(float X, float Y, float Z) { this->posX = X; this->posY = Y; this->posZ = Z; }

void Object::setRotX(float X){ this->rotX = X; }
void Object::setRotY(float Y){ this->rotY = Y; }
void Object::setRotZ(float Z){ this->rotZ = Z; }

float Object::getPosX(){ return this->posX; }
float Object::getPosY(){ return this->posY; }
float Object::getPosZ(){ return this->posZ; }

float Object::getRotX(){ return this->rotX; }
float Object::getRotY(){ return this->rotY; }
float Object::getRotZ(){ return this->rotZ; }
