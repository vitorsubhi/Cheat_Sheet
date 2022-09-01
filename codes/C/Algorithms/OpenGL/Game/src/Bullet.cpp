#include "Bullet.h"

Bullet::Bullet(float X, float Y, float Z, float dir){
	this->posX = X;
	this->posY = Y;
	this->posZ = Z;
	this->initialY = Y;
	this->initialZ = Z;
	this->direction = dir;
   	currentThread = std::thread(std::bind(&Bullet::run, this));
}

void Bullet::draw(void){
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glTranslatef(posX, posY, posZ);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(3,100,100);
	glPopMatrix();
}

void Bullet::run(){
	while (true){
		this_thread::sleep_for(chrono::milliseconds(75));
		if (posZ > -880 && posZ < 0)
			this->posZ = this->posZ + direction;
		else
			this->posZ = initialZ;
	}
}
