#ifndef YSGL_sim
#define YSGL_sim
#include <YSGLall.h>
#include "Rocket.h"

//YSGL 3D show - v2 elv

YSCamera myCam;
YS3dModel_OBJ myHeli, myTree;
YSTexture texRoad, texMou, texGround, textiles;

Planet Earth ,
	   Mars(4.972e24, 6378000,0.0065500194,0.044,210) ,
	   etc(1,1,1,1,1);

Rocket rocket(&Earth);

//Rocket rocket(&Mars);

void YSGL_init(double speed)
{	

	cout << "SppeeD = " << speed << endl;

	//ysgl_about_mb();
	//ysgl_openGL_ver_mb();

	rocket.pos.y = 10e6;
	rocket.v.x = speed;
	//rocket.a.y = 0;
	//rocket.a.z = -0.5;


	// resources main folder
	char resFol[] = "C:\\resources\\";

	texMou.load("texture\\sky.bmp", resFol);
	texGround.load("texture\\earth.bmp", resFol);
	texRoad.load("texture\\road.bmp", resFol);
	textiles.load("texture\\tiles.bmp", resFol);

	//myHeli.load("heli\\Heli.obj", "heli\\leviathnbody8bit256.bmp", resFol); 	myHeli.sc = 0.02;
	//myTree.load("tree\\tree trunck.obj", "tree\\treet2.bmp", resFol);

	myCam.Position.z = 10;
	myCam.Position.y = 2;
}

double ElvY = 1;
double elvDir = 0;
void drawElvStatic(){
		{
			glPushMatrix();
			{
				glRotatef(90, 1, 0, 0);
				texGround.draw(1, 30, 30);
			}
			glPopMatrix();

			glPushMatrix();
			{
				glTranslatef(0, -1, 1);
				textiles.draw(1, 5);
			}
			glPopMatrix();


			glPushMatrix();
			{
				glTranslatef(0, -1, -1);
				textiles.draw(1, 5);
			}
			glPopMatrix();

			glPushMatrix();
			{
				glTranslatef(1, -1, 0);
				glRotatef(90, 0, 1, 0);
				textiles.draw(1);
			}
			glPopMatrix();


			glPushMatrix();
			{
				glTranslatef(-1, -1, 0);
				glRotatef(90, 0, 1, 0);
				textiles.draw(1);
			}
			glPopMatrix();
		}
}
void drawElv(){
	if (elvDir > 0 && ElvY < 2)
		ElvY += elvDir;

	if (elvDir < 0 && ElvY > 1)
		ElvY += elvDir;

	glPushMatrix();
	{
		glScalef(5, 1, 1);
		glTranslatef(0, ElvY, 0);
		drawElvStatic();
	}
	glPopMatrix();
}

void track(){
	myCam.Position.y = rocket.pos.y;
	myCam.Position.x = rocket.pos.x;
	myCam.Position.z = rocket.pos.z + 20;
}


void YSGL_mainGL()
{
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3d(-6, -0.3, 3);					//the ground
	glVertex3d(-6, -0.3, -3);
	glVertex3d(3, -0.3, -3);
	glVertex3d(3, -0.3, 3);
	glEnd();
	glTranslated(-2, -0.3, 1);
	glColor3d(0, 0, 0);
	glBegin(GL_QUADS);								//the right column
	glVertex3d(0, 0, 0);
	glVertex3d(0, 10, 0);
	glVertex3d(0.3, 10, 0);
	glVertex3d(0.3, 0, 0);
	glEnd();
	glColor3d(0, 0, 0);
	glBegin(GL_QUADS);								//the left column
	glVertex3d(-2, 0, 0);
	glVertex3d(-2, 7, 0);
	glVertex3d(-1.7, 7, 0);
	glVertex3d(-1.7, 0, 0);
	glEnd();
	glColor3d(0, 0, 0);
	glBegin(GL_QUADS);								//the connection column
	glVertex3d(-2, 7, 0);
	glVertex3d(0, 10, 0);
	glVertex3d(0.3, 10, 0);
	glVertex3d(-1.7, 7, 0);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);							//1--3	R			
	glVertex3d(0, 1, -0.1);
	glVertex3d(-2, 3, -0.1);
	glVertex3d(-1.7, 3, -0.1);
	glVertex3d(0.3, 1, -0.1);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);						//1--3 L
	glVertex3d(-2, 1, -0.1);
	glVertex3d(0, 3, -0.1);
	glVertex3d(0.3, 3, -0.1);
	glVertex3d(-1.7, 1, -0.1);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);						//3--5 R
	glVertex3d(0, 3, -0.1);
	glVertex3d(-2, 5, -0.1);
	glVertex3d(-1.7, 5, -0.1);
	glVertex3d(0.3, 3, -0.1);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);						//3--5 L
	glVertex3d(-2, 3, -0.1);
	glVertex3d(0, 5, -0.1);
	glVertex3d(0.3, 5, -0.1);
	glVertex3d(-1.7, 3, -0.1);
	glEnd();

	glBegin(GL_QUADS);						//5--7 R
	glVertex3d(0, 5, -0.1);
	glVertex3d(-2, 7, -0.1);
	glVertex3d(-1.7, 7, -0.1);
	glVertex3d(0.3, 5, -0.1);
	glEnd();
	glBegin(GL_QUADS);						//5--7 L
	glVertex3d(-2, 5, -0.1);
	glVertex3d(0, 7, -0.1);
	glVertex3d(0.3, 7, -0.1);
	glVertex3d(-1.7, 5, -0.1);
	glEnd();

	glColor3d(0, 0, 0);
	glBegin(GL_QUADS);								//the right column
	glVertex3d(0, 0, -2);
	glVertex3d(0, 10, -2);
	glVertex3d(0.3, 10, -2);
	glVertex3d(0.3, 0, -2);
	glEnd();
	glColor3d(0, 0, 0);
	glBegin(GL_QUADS);								//the left column
	glVertex3d(-2, 0, -2);
	glVertex3d(-2, 7, -2);
	glVertex3d(-1.7, 7, -2);
	glVertex3d(-1.7, 0, -2);
	glEnd();
	glColor3d(0, 0, 0);
	glBegin(GL_QUADS);								//the connection column
	glVertex3d(-2, 7, -2);
	glVertex3d(0, 10, -2);
	glVertex3d(0.3, 10, -2);
	glVertex3d(-1.7, 7, -2);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);							//1--3	R			
	glVertex3d(0, 1, -2.1);
	glVertex3d(-2, 3, -2.1);
	glVertex3d(-1.7, 3, -2.1);
	glVertex3d(0.3, 1, -2.1);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);						//1--3 L
	glVertex3d(-2, 1, -2.1);
	glVertex3d(0, 3, -2.1);
	glVertex3d(0.3, 3, -2.1);
	glVertex3d(-1.7, 1, -2.1);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);						//3--5 R
	glVertex3d(0, 3, -2.1);
	glVertex3d(-2, 5, -2.1);
	glVertex3d(-1.7, 5, -2.1);
	glVertex3d(0.3, 3, -2.1);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);						//3--5 L
	glVertex3d(-2, 3, -2.1);
	glVertex3d(0, 5, -2.1);
	glVertex3d(0.3, 5, -2.1);
	glVertex3d(-1.7, 3, -2.1);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);						//5--7 R
	glVertex3d(0, 5, -2.1);
	glVertex3d(-2, 7, -2.1);
	glVertex3d(-1.7, 7, -2.1);
	glVertex3d(0.3, 5, -2.1);
	glEnd();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);						//5--7 L
	glVertex3d(-2, 5, -2.1);
	glVertex3d(0, 7, -2.1);
	glVertex3d(0.3, 7, -2.1);
	glVertex3d(-1.7, 5, -2.1);
	glEnd();
	glColor3d(1, 0.6, 0);
	glBegin(GL_QUADS);						//first level
	glVertex3d(0.3, 1, -0.1);
	glVertex3d(-2, 1, -0.1);
	glVertex3d(-2, 1, -2);
	glVertex3d(0.3, 1, -2);
	glEnd();
	glColor3d(1, 0.6, 0);
	glBegin(GL_QUADS);						//second level
	glVertex3d(0.3, 3, -0.1);
	glVertex3d(-2, 3, -0.1);
	glVertex3d(-2, 3, -2);
	glVertex3d(0.3, 3, -2);
	glEnd();
	glBegin(GL_QUADS);						//bridge
	glVertex3d(0.3, 3, -0.8);
	glVertex3d(0.3, 3, -1.3);
	glVertex3d(1.2, 3, -1.3);
	glVertex3d(1.2, 3, -0.8);
	glEnd();

	glPopMatrix();

	//ysDrawCube();
	static float xxx = 0;
	static float theta = 0;
	theta += 1;
	//track();

	rocket.physics_draw();
	//rocket.print();

	//cout << "current frame: " << theta << endl;

	//drawElv();

	glPushMatrix();
	{
		glTranslatef(0, ysSinD(theta) + 2, -2);
		glColor3f(1, 0, 0);
		ysPrintf("YSGL frame %.0f", theta);
	}
	glPopMatrix();

	

	glPushMatrix();
	{
		float a = 60, b = 15;
		glTranslatef(0, a, -25);
		texMou.draw(a, b, b * 2);
	}
	glPopMatrix();

	glPushMatrix();
	{
		float a = 60, b = 15;
		glRotatef(90, 1, 0, 0);
		//texGround.draw(40, 30, 30);
	}
	glPopMatrix();


	glPushMatrix();
	{
		float a = 60, b = 15;
		//glRotatef(theta, 1, 1, 1);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 0, 1);

		glTranslatef(-5, -10, -0.1);
		glScalef(10, 1, 1);
		texRoad.draw(3, 10, 2);
	}
	glPopMatrix();



	if (keys['Z'])
		elvDir = -0.01;
	if (keys['X'])
		elvDir = +0.01;

	Sleep(10);
}

#endif