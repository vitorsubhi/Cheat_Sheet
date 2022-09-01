#ifndef __PLAYER__
#define __PLAYER__
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
	#include <thread>
	#include <iostream>
	#include <chrono>
	#include <stdlib.h>

	using namespace std;

	class Player{
		private:
			short int lifes = 3;
			bool jumping = false;
			GLfloat posX, posY, posZ;
			GLfloat initialY;
			bool movimento;
			std::thread currentThread;

		public:
			Player(float X, float Y, float Z);

			void draw(void);
			void jump();
			void doJump();
			bool isJumping();
			int getPoints();
			
			void setPosX(float X);
			void setPosY(float Y);
			void setPosZ(float Z);

			float getPosX();
			float getPosY();
			float getPosZ();

			float getInitialY();
	};
#endif
