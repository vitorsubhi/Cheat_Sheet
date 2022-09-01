#ifndef __ENEMY__
#define __ENEMY__
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
	#include <stdlib.h>
	#include <iostream>
	#include <thread>
	#include <chrono>

	using namespace std;

	class Enemy{
		private:
			GLfloat posX, posY, posZ, initialZ, direction;
			std::thread currentThread;

		public:
			Enemy (float X, float Y, float Z, float dir);
			void draw(void);
			void run();
	};
#endif
