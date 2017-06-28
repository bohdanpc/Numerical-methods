/*
* sinh.cpp
*
*   Created on: Sep 9, 2016
*Last modified: Sep 25, 2016
*       Author: Levunets B.V, Kv-42
*/
#include "lab1_sinh.h"
#include <iomanip>
#include <exception>

using namespace std;

double Sinh::calculateByEps(double arg, double epsil) {
	n = 1;
	x = arg;
	arg = abs(arg);
	rn = arg;
	value = rn;
	eps = epsil;

	while (epsil <= rn) {
		rn *= arg*arg / (2.0 * n*(2.0 * n + 1.0));		//count Uk
		value += rn;
		n++;
	}

	rn /= 3.0;											//count remainder
	value += rn;

	if (x < 0)											// sh(-x) = -sh(x)
		value = -value;

	absError = abs(sinh(x) - value);
	return value;
}

double Sinh::calculateByNum(double arg, int len) {
	n = len;
	x = arg;
	arg = abs(arg);
	rn = arg;
	value = rn;
	eps = 0;

	if (len <= 0)
		throw exception("the amount of member is incorrect...\n");

	for (int i = 1; i < n; i++) {
		rn *= arg*arg / (2.0 * i*(2.0 * i + 1.0));
		value += rn;
	}

	rn /= 3.0;
	value += rn;

	if (x < 0)								//sh(-x) = -sh(x)
		value = -value;

	absError = abs(sinh(x) - value);
	return value;
}

//for predefined arg value and different value of precision
void Sinh::table1(double a, double b) {
	const double arg =(b + a) / 2.0;
	const int view = 20;

	cout << setw(7) << "eps" << setw(8) << "n" << setw(18) << "Abs error" << setw(view) << "Rn\n";
	cout << scientific << setprecision(8);

	for (double eps = 1e-2; eps > 1e-14; eps *= 1e-3) {
		calculateByEps(arg, eps);
		if (eps == 1e-8)
			nTab2 = n;									//get n-value for table 2
		cout << right << setw(5) << setprecision(3) << eps;
		cout << setw(5) << n; 
		cout <<setw(view + 2) << setprecision(8) << absError << setw(view + 2) << rn << endl;
	}
}

//for defined accuracy of 10^-8 and variable arg with step 'h'
void Sinh::table2(double a, double b) {
	double h = (b - a) / 10.0;
	double arg;
	const int view = 20;
	if (nTab2 <= 0)
		throw exception("n for eps = 10^-8 is undefined\n");
	
	cout << endl << endl << setw(7) << "Xi" << setw(20) << "Abs error" << setw(view-2) << "Rn\n"; 
	cout << scientific << setprecision(8);
	
	for (int i = 0; i < 11; i++) {
		arg = a + h*i;
		calculateByNum(arg, nTab2);
		cout << right << setw(11) << setprecision(3) << arg;
		cout << setw(view) << setprecision(8) << absError << setw(view) << rn << endl;
	}
}



