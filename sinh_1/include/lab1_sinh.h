/*
* sinh.h
*
*  Created on: Sep 9, 2016
*      Author: Levunets B.V, Kv-42
*/
#pragma once

#include <cmath>
#include <iostream>

class Sinh {
public:
	Sinh():x(0), eps(0), n(0), absError(0), rn(0), value(0), nTab2(0){};
	Sinh(double x, double eps){ value = calculateByEps(x, eps); };
	~Sinh() {};

	double calculateByEps(double, double);
	double calculateByNum(double, int);
	void table1(double, double);
	void table2(double, double);

	double getValue() { return value; };
	double getRn() { return rn; };
	double getAbsError() { return absError; };
	double getEps() { return eps; };
	double getX() { return x; };
	int getN() { return n; };
	int getN2() { return nTab2; };

private:
	int n, nTab2;
	double x, eps, absError, rn, value;
};
