#pragma once
#include <YSGLall.h>
#include"Vec.h"
#include"Planet.h"
#include <cmath>
class Rocket
{
public:
	Vec v, pos,omega,teta;
	Planet *p;
	double m,mtotal, dt, rr, idelta, Cd , mfuel ;
	bool autoPilotStatus;

	Rocket(Planet * pp){
		m = 759000; // mRocket
		dt = 100;
		p = pp;
		rr = 0.1;
		Cd = 0.5;
		mtotal = m + mfuel; 
		mfuel = 500000; //mFuel Kg
		autoPilotStatus = 0;
		idelta = 1;

		}

	void autoPilot(){
		if (autoPilotStatus){

		}
	}

	void physics_draw(){
		physics();
		draw_movement();
	}
	
private:
	Vec a , alpha;
	// Gravity force intensity ray 
	Vec fg(){
		Vec g = p->gravity(pos);
		//g.print("g");
		Vec w = g*m;
		return w;
	}

	// Total forace ray 
	Vec ft(){
		Vec total = fg() + drag();
		//f.print("W:");
		return total;
	}

	double rho(){
		//À«»  «·€«“«  «·⁄«„ 
		double r = 8.3148;
		//À«»  «·€«“ ··ÂÊ«¡ «·Ã«›
		double Rspecific = 287.058;
		// Õ”«» «— ›«⁄ «·’«—ÊŒ ⁄‰ «·«—÷
		double h = pos.loong() - p->R;
		// Õ”«» ‘œ… «·Ã«–»Ì… 
		Vec g = p->gravity(pos);
		// Õ”«» «·÷€ÿ «·ÃÊÌ ··ﬂÊﬂ»
		double pressure = p->P0 * exp((-p->Md * g.loong() * h) / (r * p->Tkelvin));

		double rhoo = pressure / (Rspecific * p->Tkelvin);

		return rhoo;
	}

	// „ﬁ«Ê„… «·ÂÊ«¡ 
	Vec drag(){
		double area = 3.14 * rr*rr;
		Vec dir = -v.unitry();

		double dra = 0.5*Cd * rho() * area * v.loong() * v.loong();
		Vec dragg = dir * dra;
		//dragg.print("drag:");
		return dragg;
	}


	Vec thrust()
	{
		// Fthrust = deltm * Ve 



	}



	void physics(){
		autoPilot();
		a = ft() / m;
		v = a*dt + v;
		pos = v*dt + pos;

		alpha = 1 / idelta;
		omega = alpha * dt + omega; 
		teta = omega * dt + teta;
		print();

	}

	void print() {

		pos.print("pos:");
		v.print("v:");
		a.print("a:");
		cout << endl;
	}
	void draw_static(){

		glPushMatrix();
		glRotated(-90, 1, 0, 0);						//the body of the rocket
		GLUquadricObj *p = gluNewQuadric();
		gluQuadricDrawStyle(p, GLU_FILL);
		glColor3d(0.155, 0.155, 0.155);
		gluCylinder(p, 0.5, 0.5, 5, 50, 1);
		glPopMatrix();

		glPushMatrix();								//the cockpit
		glTranslated(0, 5, 0);
		glRotated(-90, 1, 0, 0);
		glColor3f(0, 0.6f, 1.0f);
		gluCylinder(p, 0.5, 0, 2, 50, 1);
		glPopMatrix();

		glPushMatrix();									//the fins
		glTranslated(0.5, 0, 0);
		glBegin(GL_TRIANGLES);							//fin 1 Right
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0.5, 0);
		glVertex3d(0.5, 0, 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.5, 0, 0);
		glBegin(GL_TRIANGLES);							//fin 1 Left
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0.5, 0);
		glVertex3d(-0.5, 0, 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0, 0.5);
		glBegin(GL_TRIANGLES);							//fin 1 front
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0.5, 0);
		glVertex3d(0, 0, 0.5);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0, -0.5);
		glBegin(GL_TRIANGLES);							//fin 1 back
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0.5, 0);
		glVertex3d(0, 0, -0.5);
		glEnd();

		glPopMatrix();								//the bottom of the rocket
		glPushMatrix();
		glRotated(-90, 1, 0, 0);
		glColor3f(0, 0, 0);
		gluCylinder(p, 0, 0.5, 0, 50, 1);
		glPopMatrix();

		glPushMatrix();								// the nozzle
		glTranslated(0, 0.5, 0);
		glRotated(90, 1, 0, 0);
		glColor3f(1, 0, 0);
		gluCylinder(p, 0, 0.3, 0.7, 50, 1);
		glPopMatrix();

		//ysDrawCube();
	}
	void draw_movement(){
		glPushMatrix();
		Vec ppp = pos / p->R;
		double oo = 0;
		oo + 10;
		glTranslated(ppp.x, ppp.y, ppp.z);
		//glRotated( oo , teta.x  , teta.y , teta.z);
		draw_static();
		glPopMatrix();
	}
};

