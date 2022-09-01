#ifndef __CAMERA__
#define __CAMERA__

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

using namespace std;

class Camera
{
	private:
		GLfloat angle, fAspect;
		GLfloat rotX = 0.0, rotY = 0.0, rotX_ini, rotY_ini;
		GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;

	public:
		Camera(float X, float Y, float Z);

		void look(void);

		void setObsX(float X);
		void setObsY(float Y);
		void setObsZ(float Z);
		void setObsPosition(float X, float Y, float Z);

		void setRotX(float X);
		void setRotY(float Y);

		float getObsX();
		float getObsY();
		float getObsZ();

		float getRotX();
		float getRotY();
};

#endif
