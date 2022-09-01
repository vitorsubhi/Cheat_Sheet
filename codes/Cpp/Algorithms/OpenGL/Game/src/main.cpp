#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include "bibutil.h"
#include <thread>
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "Stair.h"

using namespace std;

GLfloat angle, fAspect;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
Player *player;
Stair *stair_1;
Stair *stair_2;
Stair *stair_3;
Stair *stair_4;
Stair *stair_5;
Bullet *bullet;
Enemy *enemy;

int controle = 0;

float final = 30.0;
TEX *texture;

bool view = 1;
int x_ini,y_ini,bot, abc = 0;

void Lights (void)
{
	GLfloat luzAmbiente[4]={0.25,0.25,0.25,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0}; 
	GLfloat posicaoLuz0[4]={0.0, 80.0, 0.0, 1.0};
	GLfloat posicaoLuz1[4]={0.0, -80.0, 0.0, 1.0};

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz0 );

	glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz1 );
}

void desenhaObstFig(float X, float Y, float Z){
     // Face posterior
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0);
        
                //x =40  y= 20  z= 5
                    //retangulo pequeno
                glNormal3f(3.0, 45.0, -0.0);
                glVertex3f(X, Y, Z);
                glVertex3f(X, Y+15, Z);
                glVertex3f(X-10, Y+15, Z);
                glVertex3f(X-10, Y, Z);
                    //retangulo pequeno
                glNormal3f(3.0, 45.0, -0.0);
                glVertex3f(X, Y, Z);
                glVertex3f(X, Y+15, Z);
                glVertex3f(X, Y+15, Z);
                glVertex3f(X, Y, Z);
                 // Face anterior
                glNormal3f(3.0, 45.0, -0.0);
                glVertex3f(X, Y, Z+45);
                glVertex3f(X, Y+15, Z+45);
                glVertex3f(X-10, Y+15, Z+45);
                glVertex3f(X-10, Y, Z+45);
                  // Face frente
                glNormal3f(3.0, 45.0, -0.0);
                glVertex3f(X-10, Y, Z);
                glVertex3f(X-10, Y+15, Z);
                glVertex3f(X-10, Y+15, Z+45);
                glVertex3f(X-10, Y, Z+45);
                  // Face topo
                glNormal3f(3.0, 45.0, -0.0);
                glVertex3f(X, Y+15, Z);
                glVertex3f(X-10, Y+15, Z);
                glVertex3f(X-10, Y+15, Z+45);
                glVertex3f(X, Y+15, Z+45);
        glEnd();

}

void Environment(void)
{
	glColor3f(1.0f, 1.0f, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		//Left Wall
		if (view){
			glNormal3f(-1.0, 0.0, 0.0);
			glVertex3f(-40.0, 0.0, 40.0);
			glVertex3f(-40.0, 0.0, -880.0);
			glVertex3f(-40.0, 480.0, -880.0);
			glVertex3f(-40.0, 480.0, 40.0);
		}

		//Right Wall
		glVertex3f(40.0, 0.0, 40.0);
		glVertex3f(40.0, 480.0, 40.0);
		glVertex3f(40.0, 480.0, -880.0);
		glVertex3f(40.0, 0.0, -880.0);
		glNormal3f(0.0, -1.0, 0.0);

		//Front Wall
		glVertex3f(-40.0, 0.0, -880.0);
		glVertex3f(40.0, 0.0, -880.0);
		glVertex3f(40.0, 480.0, -880.0);
		glVertex3f(-40.0, 480.0, -880.0);

		//Back Wall
		glVertex3f(-40.0, 0.0, 40.0);
		glVertex3f(40.0, 0.0, 40.0);
		glVertex3f(40.0, 480.0, 40.0);
		glVertex3f(-40.0, 480.0, 40.0);

		//Floor
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 0.0, -880.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 0.0, -880.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 0.0, 40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 0.0, 40.0);

	
		//Floor #2
		glColor3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 80.0, -800.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 80.0, -800.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 80.0, 40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 80.0, 40.0);
		
		glColor3f(0.2473f, 0.2862f, 0.011f);
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 75.0, -800.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 75.0, -800.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 75.0, 40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 75.0, 40.0);


	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.3843f, 0.2862f, 0.011f);
		glVertex3f(-40.0, 80.0, 40.0);
		glVertex3f(-40.0, 75.0, 40.0);
		glVertex3f(-40.0, 75.0, -880.0);
		glVertex3f(-40.0, 80.0, -880.0);
	
	glEnd();
	glBegin(GL_QUADS);
		//Floor #3
		glColor3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 160.0, -880.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 160.0, -880.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 160.0, -40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 160.0, -40.0);

		glColor3f(0.2473f, 0.2862f, 0.011f);
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 155.0, -880.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 155.0, -880.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 155.0, -40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 155.0, -40.0);
	
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.3843f, 0.2862f, 0.011f);
		glVertex3f(-40.0, 160.0, 40.0);
		glVertex3f(-40.0, 155.0, 40.0);
		glVertex3f(-40.0, 155.0, -880.0);
		glVertex3f(-40.0, 160.0, -880.0);
	
	glEnd();
	glBegin(GL_QUADS);
	
		//Floor #4
		glColor3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 240.0, -800.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 240.0, -800.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 240.0, 40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 240.0, 40.0);

		glColor3f(0.2473f, 0.2862f, 0.011f);
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 235.0, -800.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 235.0, -800.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 235.0, 40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 235.0, 40.0);
		
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.3843f, 0.2862f, 0.011f);
		glVertex3f(-40.0, 240.0, 40.0);
		glVertex3f(-40.0, 235.0, 40.0);
		glVertex3f(-40.0, 235.0, -880.0);
		glVertex3f(-40.0, 240.0, -880.0);
	
	glEnd();
	glBegin(GL_QUADS);
		

		//Floor #5
		glColor3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 320.0, -880.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 320.0, -880.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 320.0, -40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 320.0, -40.0);
		
		glColor3f(0.2473f, 0.2862f, 0.011f);
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 315.0, -880.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 315.0, -880.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 315.0, -40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 315.0, -40.0);
		
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.3843f, 0.2862f, 0.011f);
		glVertex3f(-40.0, 320.0, 40.0);
		glVertex3f(-40.0, 315.0, 40.0);
		glVertex3f(-40.0, 315.0, -880.0);
		glVertex3f(-40.0, 320.0, -880.0);
	
	glEnd();
	glBegin(GL_QUADS);
		
		//Floor #6
		glColor3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 400.0, -800.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 400.0, -800.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 400.0, 40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 400.0, 40.0);

		glColor3f(0.2473f, 0.2862f, 0.011f);
		glTexCoord2f(0,0);
		glVertex3f(-40.0, 395.0, -800.0);
		glTexCoord2f(final,0);
		glVertex3f(40.0, 395.0, -800.0);
		glTexCoord2f(final,final);
		glVertex3f(40.0, 395.0, 40.0);
		glTexCoord2f(0,final);
		glVertex3f(-40.0, 395.0, 40.0);
			
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.3843f, 0.2862f, 0.011f);
		glVertex3f(-40.0, 400.0, 40.0);
		glVertex3f(-40.0, 395.0, 40.0);
		glVertex3f(-40.0, 395.0, -800.0);
		glVertex3f(-40.0, 400.0, -800.0);
	
	glEnd();
	glBegin(GL_QUADS);


		//Roof
		glColor3f(0.3473f, 0.2862f, 0.011f);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-40.0, 480.0, -880.0);
		glVertex3f(40.0, 480.0, -880.0);
		glVertex3f(40.0, 480.0, 40.0);
		glVertex3f(-40.0, 480.0, 40.0);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	Lights();

	Environment();
	player->draw();
	stair_1->draw();
	stair_2->draw();
	stair_3->draw();
	stair_4->draw();
	stair_5->draw();

	bullet->draw();
	enemy->draw();

int posx = 40;
	// blobos primeiro andar
	desenhaObstFig( posx,0,-800);
	desenhaObstFig( posx,0,-600);
	desenhaObstFig( posx,0,-400);
	desenhaObstFig( posx,0,-200);
	desenhaObstFig( posx,0,-50);

	// blobos segundo andar
	desenhaObstFig( posx,80,-800);
	desenhaObstFig( posx,80,-600);
	desenhaObstFig( posx,80,-400);
	desenhaObstFig( posx,80,-200);
	desenhaObstFig( posx,80,-50);

	// blobos terceiro andar
	desenhaObstFig( posx,160,-800);
	desenhaObstFig( posx,160,-600);
	desenhaObstFig( posx,160,-400);
	desenhaObstFig( posx,160,-200);
	//desenhaObstFig(20,160,-50);
	// blobos quanto andar
	desenhaObstFig( posx,240,-800);
	desenhaObstFig( posx,240,-600);
	desenhaObstFig( posx,240,-400);
	desenhaObstFig( posx,240,-200);
	desenhaObstFig( posx,240,-50);
	// blobos quinto andar
	desenhaObstFig( posx,320,-800);
	desenhaObstFig( posx,320,-600);
	desenhaObstFig( posx,320,-400);
	desenhaObstFig( posx,320,-200);
	//desenhaObstFig(20,320,-50);
	// blobos sexto andar
	desenhaObstFig( posx,400,-800);
	desenhaObstFig( posx,400,-600);
	desenhaObstFig( posx,400,-400);
	desenhaObstFig( posx,400,-200);
	desenhaObstFig( posx,400,-50);

	glutSwapBuffers();
	glutPostRedisplay();
}

void Camera(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Lights();
	glTranslatef(-obsX,-obsY,-obsZ);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
}

void Visualization(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(angle,fAspect,0.5,1000);

	Camera();
}

void Keyboard (unsigned char key, int x, int y)
{
	switch (key){
		case 27: //ESC
			exit (0);
			break;
		case 119: //w
			if (view){
				if (rotY != 180)
				{
					if (player->getPosZ() > -880)
					{
						if (player->getPosZ() <= -800 && controle < 16 )
						{
							player->setPosY(player->getPosY() + 5);
							controle ++;
						}
						obsZ-=5;
						player->setPosZ(player->getPosZ() - 5);
					}
				}
				else
				{
					if (player->getPosZ() < 40)
					{
						if (player->getPosZ() >= -40 && controle > 0)
						{
							player->setPosY(player->getPosY() + 5);
							controle --;
						}
						obsZ-=5;
						player->setPosZ(player->getPosZ() + 5);
					}
				}
			}
			else{
				player->jump();
			}
			break;
		case 97: //a
		//	obsX-= 40;
			if (!view){
				if (player->getPosZ() > -880)
				{
					if (player->getPosZ() <= -800 && controle < 16 )
					{
						player->setPosY(player->getPosY() + 5);
						controle ++;
					}
					player->setPosZ(player->getPosZ() - 5);
				}
			}
			else{
				rotX = 0;
				rotY = 0;
				obsX = -20;	
				if (player->isJumping())
					obsY = player->getInitialY() + 15;
				else
					obsY = player->getPosY() + 15;
				obsZ = player->getPosZ() + 100;
			}
			break;
		case 115: //s
			if (view){
				if (rotY != 180)
				{
					if (player->getPosZ() < 40)
					{
						if (player->getPosZ() >= -40 && controle > 0)
						{
							player->setPosY(player->getPosY() + 5);
							controle --;
						}
						obsZ+=5;
						player->setPosZ(player->getPosZ() + 5);
					}
				}
				else{
					if (player->getPosZ() > -880)
					{
						if (player->getPosZ() <= -800 && controle < 16 )
						{
							player->setPosY(player->getPosY() + 5);
							controle ++;
						}
						obsZ+=5;
						player->setPosZ(player->getPosZ() - 5);
					}
				}
			}
			break;
		case 100: //d
		//	obsX+= 40;
			if (!view){
				if (player->getPosZ() < 40)
				{
					if (player->getPosZ() >= -40 && controle > 0)
					{
						player->setPosY(player->getPosY() + 5);
						controle --;
					}
					player->setPosZ(player->getPosZ() + 5);
				}
			}
			else{
				rotX = 0;
				rotY = 180;
				obsX = 20;
				if (player->isJumping())
					obsY = player->getInitialY() + 15;
				else
					obsY = player->getPosY() + 15;
				obsZ = -player->getPosZ() + 100;
			}
			break;
		case 32: //SPACE
			player->jump();
			//obsY+= 20;
			break;
			
		case 118: //v
			if (view){
				rotX = 0;
				rotY = 90;
				obsX = -420;	
				obsY = 240;
				obsZ = 620;
			}else
			{
				rotX = 0;
				rotY = 0;
				obsX = -20;	
				if (player->isJumping())
					obsY = player->getInitialY() + 15;
				else
					obsY = player->getPosY() + 15;
				obsZ = player->getPosZ() + 100;
			}
			view = !view;
			break;
	}
	Camera();
	glutPostRedisplay();
}

void TeclasEspeciais (int tecla, int x, int y)  
{
	switch (tecla)
	{
		case GLUT_KEY_HOME:	if(angle>=10)  angle -=5;
							break;
		case GLUT_KEY_END:	if(angle<=150) angle +=5;
							break;
	}
	Visualization();
	glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
}

#define SENS_ROT	5.0
#define SENS_OBS	10.0
#define SENS_TRANSL	10.0
void MouseMovements(int x, int y)
{
	if(bot==GLUT_LEFT_BUTTON)
	{
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;
	}
	else if(bot==GLUT_RIGHT_BUTTON)
	{
		int deltaz = y_ini - y;
		obsZ = obsZ_ini + deltaz/SENS_OBS;
	}
	else if(bot==GLUT_MIDDLE_BUTTON)
	{
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		obsX = obsX_ini + deltax/SENS_TRANSL;
		obsY = obsY_ini - deltay/SENS_TRANSL;
	}
	Camera();
	glutPostRedisplay();
}

void updateWindowSize(GLsizei w, GLsizei h)
{
	if ( h == 0 ) h = 1;

	glViewport(0, 0, w, h);
 
	fAspect = (GLfloat)w/(GLfloat)h;

	Visualization();
}

void Initialize (void)
{   
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	texture = CarregaTextura("texturas/revmur037.jpg", false);

	glBindTexture(GL_TEXTURE_2D, texture->texid);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);  
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);

	glShadeModel(GL_SMOOTH);
    
	player = new Player(-20.0, 32.0, -100.0);
	bullet = new Bullet(-20.0, 50.0, -800.0, 3.0);
	enemy  = new Enemy(-20.0, 32.0, -30.0, -10.0);
	stair_1 = new Stair(0.0, -5.0, -800.0, -40.0, 80.0, 5.0, 1);
	stair_2 = new Stair(0.0, 75.0, -40.0, -40.0, 80.0, 5.0, -1);
	stair_3 = new Stair(0.0, 155.0, -800.0, -40.0, 80.0, 5.0, 1);
	stair_4 = new Stair(0.0, 235.0, -40.0, -40.0, 80.0, 5.0, -1);
	stair_5 = new Stair(0.0, 315.0, -800.0, -40.0, 80.0, 5.0, 1);

	angle=45;
    
	rotX = 0;
	rotY = 0;
	obsX = -20;
	obsY = 45;
	obsZ = 0;    
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowPosition(1,1); 
	glutInitWindowSize(800,800); 
	glutCreateWindow("Game");
	glutDisplayFunc(Display);
	glutReshapeFunc(updateWindowSize);
	glutKeyboardFunc (Keyboard);
	glutSpecialFunc (TeclasEspeciais);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMovements);
	Initialize();
 
	glutMainLoop();
 
	return 0;
}
