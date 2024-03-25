#pragma once
#include "Vec.h"
class Planet
{
public:
	double M, R, G;

	Planet(double MM = 5.972e24, double RR = 6378000 ){

		G = 6.67428*1e-11 ;
		M = MM ;
		R = RR ;
		
	}

	Vec gravity(Vec pos){

		// The direction of the gravitational ray (But) long ray is wrong
		Vec dirfg = - pos;
		// Unitary ray of gravitational ray (Note) long ray equal one
		dirfg = dirfg.unitry();
		// h is the heigh of rocket above the surface the planet
		double r = pos.loong();
		// The intensity of the gravitational force
		double ifg = (M*G)/(r*r);
	
		return dirfg*ifg;
	}


};

