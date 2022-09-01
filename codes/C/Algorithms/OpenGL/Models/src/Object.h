#ifndef __OBJECT__
#define __OBJECT__

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <thread>
#include <chrono>

using namespace std;

class Object
{
	protected:
		GLfloat posX, posY, posZ;
		GLfloat rotX = 0.0, rotY = 0.0, rotZ = 0.0;
		unsigned int delay = 10;
		thread currentThread;

	public:
		Object();
		Object(float X, float Y, float Z);

		virtual void draw(void);
		virtual void action();
		virtual void animate();

		virtual void setDelay(unsigned int ndelay);

		virtual void setPosX(float X);
		virtual void setPosY(float Y);
		virtual void setPosZ(float Z);
		virtual void setPosition(float X, float Y, float Z);

		virtual void setRotX(float X);
		virtual void setRotY(float Y);
		virtual void setRotZ(float Z);

		virtual float getPosX();
		virtual float getPosY();
		virtual float getPosZ();

		virtual float getRotX();
		virtual float getRotY();
		virtual float getRotZ();
};

#endif
