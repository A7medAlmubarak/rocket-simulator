#pragma once
#include <YSGLall.h>
#include"Vec.h"
#include"Planet.h"
class Rocket
{
public:
	Vec v, pos,omega,teta;
	Planet *p;
	double m, dt, rr,idelta;
	bool autoPilotStatus;

	Rocket(Planet * pp){
		m = 759000;
		dt = 100;
		p = pp;
		rr = 0.1;
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
		return 1;
	}

	Vec drag(){
		double cd = 0.5, area = 3.14 * rr*rr;
		Vec dir = -v.unitry();

		double dra = 0.5*cd *rho() *area * v.loong() * v.loong();
		return dir * dra;
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
		ysDrawCube();
	}
	void draw_movement(){
		glPushMatrix();
		Vec ppp = pos / p->R;
		double oo = oo+10;
		glTranslated(ppp.x, ppp.y, ppp.z);
		glRotated( oo , teta.x  , teta.y , teta.z);
		draw_static();
		glPopMatrix();
	}
};

