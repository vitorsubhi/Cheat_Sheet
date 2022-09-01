#include "Stair.h"

Stair::Stair(float X, float Y, float Z, float width, float height, float length, int direction){
	this->posX = X;
	this->posY = Y;
	this->posZ = Z;
	this->width = width;
	this->height = height;
	this->length = length;
	this->direction = direction;
	currentThread = std::thread(std::bind(&Stair::anime, this));
}
	
void Stair::draw(void){
	float a, b;
	for (a = 0, b = length; a < height; a += length, b += length)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f (posX, posY+a, posZ-(a*direction));
			glVertex3f (posX+width, posY+a, posZ-(a*direction));
			glVertex3f (posX+width, posY+b, posZ-(a*direction));
			glVertex3f (posX, posY+b, posZ-(a*direction));
		glEnd();

		glColor3f(0.3f, 0.3f, 0.3f);
		glBegin(GL_QUADS);
			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f (posX+width, posY+b, posZ-(a*direction));
			glVertex3f (posX, posY+b, posZ-(a*direction));
			glVertex3f (posX, posY+b, posZ-(b*direction));
			glVertex3f (posX+width, posY+b, posZ-(b*direction));
		glEnd();
	}
}

void Stair::anime(){
	while (true){
		for (float i=1; i <= this->length; i+=1)
		{
			this_thread::sleep_for(chrono::milliseconds(60));
			this->posZ -= this->direction;	
			this->posY += 1;	
		}
		this->posZ += this->length * direction;
		this->posY -= this->length;
		this->anima_aux = !this->anima_aux;
	}
}
