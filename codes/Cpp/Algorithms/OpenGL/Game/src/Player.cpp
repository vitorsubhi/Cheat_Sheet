#include "Player.h"

void Player::draw(void){
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

Player::Player(float X, float Y, float Z){
	this->posX = X;
	this->posY = Y;
	this->posZ = Z;
}

void Player::jump(){
	if (!this->jumping)
	{
		this->jumping = !this->jumping;
		this->initialY = this->posY;
		currentThread = std::thread(std::bind(&Player::doJump, this));
		currentThread.detach();
	}
}

void Player::doJump(){
	for (int i = 7; i > 0; i--){
		this_thread::sleep_for(chrono::milliseconds(80));
		this->posY += i;
	}
	for (int i = 0; i <= 7; i++){
		this_thread::sleep_for(chrono::milliseconds(100));
		this->posY -= i;
	}
	this->jumping = !this->jumping;
	return;
}

bool Player::isJumping(){ return this->jumping; }

void Player::setPosX(float X){ this->posX = X; }
void Player::setPosY(float Y){ this->posY = Y; }
void Player::setPosZ(float Z){ this->posZ = Z; }

float Player::getPosX(){ return this->posX; }
float Player::getPosY(){ return this->posY; }
float Player::getPosZ(){ return this->posZ; }

float Player::getInitialY(){ return this->initialY; }
