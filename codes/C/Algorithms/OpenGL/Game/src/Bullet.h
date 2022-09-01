#ifndef __BULLET__
#define __BULLET__
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
	#include <stdlib.h>
	#include <iostream>
	#include <thread>
	#include <chrono>

	using namespace std;

	class Bullet{
		private:
			GLfloat posX, posY, posZ, initialY, initialZ, direction;
			std::thread currentThread;

		public:
			Bullet (float X, float Y, float Z, float dir);
			void draw(void);
			void run();
	};
#endif
