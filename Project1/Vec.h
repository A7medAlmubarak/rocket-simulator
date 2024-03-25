#pragma once
#include <cmath>
#include <iostream>
using namespace std;
class Vec
{
public:
	double x, y, z;

	Vec(double xx=0, double yy=0, double zz=0){
		x = xx;
		y = yy;
		z = zz;
	}
	void set(double xx = 0, double yy = 0, double zz = 0){
		x = xx;
		y = yy;
		z = zz;
	}

	Vec operator+(Vec b){
		Vec c;
		c.x = x + b.x;
		c.y = y + b.y;
		c.z = z + b.z;
		return c;
	}
	Vec operator*(double n){
		Vec c;
		c.x = x *n;
		c.y = y *n;
		c.z = z *n;
		return c;
	}
	Vec operator/(double n){
		Vec c;
		c.x = x /n;
		c.y = y /n;
		c.z = z /n;
		return c;
	}
	Vec operator-(Vec b){
		Vec c;
		c.x = x - b.x;
		c.y = y - b.y;
		c.z = z - b.z;
		return c;
	}
	Vec operator-(){
		Vec c;
		c.x = -x ;
		c.y = -y;
		c.z = -z;
		return c;
	}

	double loong(){
		return sqrt(x*x+y*y+z*z);
	}
	Vec unitry(){
		// epsilon
		if (loong() < 0.0001)
			return (*this);
	
		return (*this) / loong();
	}

	void print(string str = ""){
		cout << str;
		cout <<  " ( " << x ;
		cout << " , " << y ;
		cout << " , " << z << " ) ";// << endl;

	}

}; 


