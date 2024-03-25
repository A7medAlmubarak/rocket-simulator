#pragma once
#include "Vec.h"
class Planet
{
public:
	double M, R, G ,P0 , Md ,Tkelvin ;

	Planet(double MM = 5.972e24, double RR = 6378000,
		   double P00 = 1.01325, double Mdd = 0.0289,
		   double TTkelvin = 287 ){

		G = 6.67428*1e-11 ;
		M = MM ; // Kg
		R = RR ; // m
		P0 = P00; //1 bar = 100000 pa
		Md = Mdd , //Kg/Mol
		Tkelvin = TTkelvin; // Kelvin
		
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

