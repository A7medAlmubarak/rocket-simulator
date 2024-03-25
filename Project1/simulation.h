#ifndef YSGL_sim
#define YSGL_sim
#include <YSGLall.h>
#include "Rocket.h"
//YSGL 3D show - v2 elv

YSCamera myCam;
YS3dModel_OBJ myHeli, myTree;
YSTexture texRoad, texMou, texGround, textiles;

Planet earth ,
	   mars(4.972e24, 6378000) ,
	   etc(1,1);

//Rocket rocket(&earth);

Rocket rocket(&mars);

void YSGL_init()
{	
	//ysgl_about_mb();
	//ysgl_openGL_ver_mb();

	rocket.pos.y = 10e6;
	rocket.v.x = 7000;
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
	ysDrawCube();
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