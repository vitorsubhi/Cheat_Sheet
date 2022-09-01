#include "Enemy.h"

Enemy::Enemy(float X, float Y, float Z, float dir){
	this->posX = X;
	this->posY = Y;
	this->posZ = Z;
	this->initialZ = Z;
	this->direction = dir;
   	currentThread = std::thread(std::bind(&Enemy::run, this));
}

void Enemy::draw(void){
float fatCrescimento = 2.0;
	glPushMatrix();
        glColor3f(1.0,1.0,1.0);    //cor
        glTranslatef(posX, posY, posZ);    // posicao plano
        glScalef(0.2*fatCrescimento,0.2*fatCrescimento,0.2*fatCrescimento);      //olho esquerdo
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();
	glPushMatrix();
        glColor3f(0.0,0.0,0.0);    //cor
        glTranslatef(posX, posY, posZ);    // posicao plano
        glScalef(0.1*fatCrescimento,0.1*fatCrescimento,0.1*fatCrescimento);      //bola de olho esquerdo
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();
    glPushMatrix();
        glColor3f(1.0,1.0,1.0);    //cor
        glTranslatef(posX, posY, posZ);    // posicao plano
        glScalef(0.2*fatCrescimento,0.2*fatCrescimento,0.2*fatCrescimento);      //olho direito
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.0,0.0,0.0);    //cor
        glTranslatef(posX, posY, posZ);    // posicao plano
        glScalef(0.1*fatCrescimento,0.1*fatCrescimento,0.1*fatCrescimento);      //bola de olho direito
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();
    glPushMatrix();
        glColor3f(1.0*fatCrescimento,1.0*fatCrescimento,1.0*fatCrescimento);    //cor
        glTranslatef(posX, posY, posZ);    // posicao plano
        glScalef(0.1,0.1,0.3);      //nariz
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0,0.0,0);    //cor
        glTranslatef(posX, posY, posZ);    // posicao plano
        glScalef(1.0*fatCrescimento,1.0*fatCrescimento,1.0*fatCrescimento);      //kbc
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0,0.0,0);    //cor
        glTranslatef(posX+0.7, posY-10, posZ);    // posicao plano
        glScalef(0.8*fatCrescimento,2.0*fatCrescimento,0.8*fatCrescimento);      //corpo
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0,0.0,0);    //cor
        glTranslatef(posX-4.0, posY-13	, posZ);    // posicao plano
        glScalef(0.6*fatCrescimento,1.5*fatCrescimento,0.6*fatCrescimento);      //braco esquerdo
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();

    glPushMatrix();
		glColor3f(1.0,1.0,0); //cor amarelo               
        glTranslatef(posX+5.0, posY-13	, posZ);    // posicao plano
        glScalef(0.6*fatCrescimento,1.5*fatCrescimento,0.6*fatCrescimento);      //braco direto
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0,0.0,0);    //cor
        glTranslatef(posX+2, posY-23, posZ);    // posicao plano
        glScalef(0.6*fatCrescimento,1.5*fatCrescimento,0.6*fatCrescimento);      //perna
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();

	glPushMatrix();
        glColor3f(0.0,0.0,0);    //cor
        glTranslatef(posX-2, posY-23, posZ);    // posicao plano
        glScalef(0.6*fatCrescimento,1.5*fatCrescimento,0.6*fatCrescimento);      //perna
        glutSolidSphere(3,100,100);    //raio,
    glPopMatrix();
}

void Enemy::run(){
	while (true){
		this_thread::sleep_for(chrono::milliseconds(75));
		if (posY > 432)
		{
//			exit(0);
			//Game Over
		}
		else if (posZ > -880 && posZ < 40)
		{
			if ((posZ <= -800 && direction < 0) || (posZ >= -40 && direction > 0))
				this->posY += 10;
			this->posZ = this->posZ + direction;
		}
		else
		{
			//this->posY += 80;
			this->posZ -= direction;
			this->direction = - direction;
		}
	}
}
