#ifndef __STAIR__
#define __STAIR__
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
	#include <stdlib.h>
	#include <thread>
	#include <chrono>

	using namespace std;

	class Stair{
		private:
			GLfloat posX, posY, posZ;
			GLfloat width, height, length;
			bool anima_aux = true;
			int direction;
			std::thread currentThread;

		public:
			Stair(float posX, float posY, float posZ, float width, float  height, float length, int direction);
			void draw(void);
			void anime();
	};
#endif
