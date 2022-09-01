#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include "Object.h"
#include "Camera.h"
#include "Airplane.h"
#include "Car.h"
#include "Cloud.h"
#include "Grass.h"
#include "House.h"
#include "Player.h"
#include "Street.h"
#include "Sun.h"
#include "Tree.h"

using namespace std;

GLfloat angle, fAspect;
GLfloat rotX_ini, rotY_ini;
GLfloat obsX_ini, obsY_ini, obsZ_ini;

Camera *camera;
House *house;
Grass *grass;
Car *car;
Airplane *airplane;
Tree *tree;
Tree *tree_2;
Tree *tree_3;
Tree *tree_4;
Sun *sun;
Cloud *cloud;
Object *object;

int x_ini,y_ini,bot;

void Lights (void)
{
	GLfloat luzAmbiente[4]={0.25,0.25,0.25,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0}; 
	GLfloat posicaoLuz0[4]={175.0, 150.0, -275.0, 1.0};
	GLfloat posicaoLuz1[4]={175.0, -150.0, -275.0, 1.0};

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz0 );

	glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz1 );
}

void Environment(void)
{
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_QUADS);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 30.0, 0.0);
		glVertex3f(30.0, 30.0, 0.0);
		glVertex3f(30.0, 0.0, 0.0);
	glEnd();
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	Lights();

	grass->draw();
	sun->draw();
	house->draw();
	car->draw();
	tree->draw();
	tree_2->draw();
	tree_3->draw();
	tree_4->draw();
	cloud->draw();
	airplane->draw();

	glutSwapBuffers();
	glutPostRedisplay();
}

void Visualization(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(angle,fAspect,0.5,1000);

	camera->look();
}

void Keyboard (unsigned char key, int x, int y)
{
	switch (key){
		case 27: //ESC
			exit (0);
			break;
		case 'a': // Vira carro para frente
				car->setRotY(-90);
				car->direction = true;
			break;
		case 'z': //Vira carro para trás
				car->setRotY(0);
				car->direction = true;
			break;
	}
	camera->look();
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
		case GLUT_KEY_RIGHT:
				if (car->direction)
					car->setPosX(car->getPosX() + 10);	
				else
					car->setPosZ(car->getPosZ() - 10);
				break;
		case GLUT_KEY_LEFT:
				if (car->direction)
					car->setPosX(car->getPosX() - 10);	
				else
					car->setPosZ(car->getPosZ() + 10);
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
		obsX_ini = camera->getObsX();
		obsY_ini = camera->getObsY();
		obsZ_ini = camera->getObsZ();
		rotX_ini = camera->getRotX();
		rotY_ini = camera->getRotY();
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
		camera->setRotY(rotY_ini - deltax/SENS_ROT);
		camera->setRotX(rotX_ini - deltay/SENS_ROT);
	}
	else if(bot==GLUT_RIGHT_BUTTON)
	{
		int deltaz = y_ini - y;
		camera->setObsZ(obsZ_ini + deltaz/SENS_OBS);
	}
	else if(bot==GLUT_MIDDLE_BUTTON)
	{
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		camera->setObsX(obsX_ini + deltax/SENS_TRANSL);
		camera->setObsY(obsY_ini - deltay/SENS_TRANSL);
	}
	camera->look();
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
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f); //Background Color

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);  
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);

	camera = new Camera(0, 50, 150);
	glShadeModel(GL_SMOOTH);

	grass = new Grass(0.0, 0.0, -50.0);
	grass->setWidth(300);
	grass->setLength(200);
	grass->setRotY(90);
	car = new Car(0.0, 10.0, -18.0);
	car->setDelay(500);
	cloud = new Cloud(0.0, 175.0, -280.0);
	cloud->setDelay(800);
	house = new House(0.0, 17.0, -275.0);
	tree = new Tree(40.0, -17.0, -180.0);
	tree->setModel(2);
	tree_2 = new Tree(-80.0, -17.0, -180.0);
	tree_3 = new Tree(-40, -17.0, -180);
	tree_3->setModel(2);
	tree_4 = new Tree(80, -17.0, -180);
	sun = new Sun(-175.0, 150.0, -275.0);
	airplane = new Airplane(380.0, 75.0, -450.0);
	airplane->setRotY(90);
	airplane->setDelay(100);
	angle=45;
    
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowPosition(1,1); 
	glutInitWindowSize(1920,1000); 
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
