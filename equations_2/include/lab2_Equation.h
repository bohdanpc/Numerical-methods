/* 
 * file: lab2_Equation.h
 * Created: 25.09.16
 * last modified: 03.10.16
 * author: Levunets B.V., kv-42
 */

#pragma once
#include "stdio.h"
#include "math.h"

typedef struct {
	double a;
	double b;
	double eps;
	double root;
	double _precision;
	int isGetRoot;
	int steps;
} accurateInfo;

typedef double (*function) (double);
typedef double (*method)(double, double, double, accurateInfo* , function, function, function);

double getDerivativeMax( double,  double, function );
double getDerivativeMin( double,  double, function );

double accurateRootByNewton(double,  double,  double, accurateInfo*, function, function, function );
double accurateRootByIteration(double,  double,  double, accurateInfo*, function, function );
void printTable( double,  double, void*, function, function, function );	//print table for eps, accurated root and returned precision
void printTable2(double, double, function, function, function);				//compare convergence of iteration and Newton's methods

