/* 
 * file: lab2_Equation.c
 * Created: 25.09.16
 * last modified: 03.10.16
 * author: Levunets B.V., kv-42
 */
#include "lab2_Equation.h"


double _abs(double arg) {
	if (arg < 0) 
		return arg = -arg;
	return arg;
}

double getDerivativeMax( double a,  double b, function fx1){
	double max1 = fx1(a);
	double max2 = fx1(b);

	return (max1 > max2)? max1 : max2; 
}

double getDerivativeMin( double a,  double b, function fx1){
	double min1 = fx1(a);
	double min2 = fx1(b);

	return (min1 < min2)? min1 : min2; 
}


double accurateRootByNewton( double a,  double b,  double eps, accurateInfo *info, function countY, function fx1, function fx2) {
	//countY - function to accurate, fx1 - first derivative of countY, fx2 - second
	double min = getDerivativeMin(a, b, fx1);
	double leftDerivative = fx2(a);
	double rightDerivative = fx2(b);
	double xA = countY(a);
	double xB = countY(b);
	double xN;
	int steps = 0;

	if (leftDerivative * xA > 0)
		xN = a;
	else
		if (rightDerivative * xB > 0)
			xN = b;
		else 
			return info->isGetRoot = -1;

	//continue accuration until setted eps is reached
	while (eps < _abs(countY(xN) / min)) {
		xN = xN - countY(xN)/fx1(xN);
		steps++;
	}
	
	//save returned information to further input in the table
	info->a = a;
	info->b = b;
	info->isGetRoot = 1;
	info->eps = eps;
	info->_precision = _abs(countY(xN) / min);
	info->steps = steps;
	return info->root = xN;
}

double accurateRootByIteration(double a, double b, double eps, accurateInfo* info, function countY, function fx1) {
	//accurate root, as if f'(x) > 0
	double min, max, lambda, q, xN, xK, precision;
	int steps = 0;
	min = getDerivativeMin(a, b, fx1);
	max = getDerivativeMax(a, b, fx1);

	lambda = 1.0/max;
	q = 1 - min/max;
	
	xK = (a+b)/2.0;
	xN = xK;
	xK -= lambda*countY(xK);
	precision = _abs(xK - xN);

	while (precision >= (1-q)*eps/q) {
		xN = xK;
		xK -= lambda*countY(xK);
		steps++;
		precision = _abs(xK - xN);
	}

	info->a = a;
	info->b = b;
	info->_precision = precision;
	info->isGetRoot = 1;
	info->steps = steps;
	info->eps = eps;
	return info->root = xK;
}

void printTable( double a,  double b, method accurateMethod, function countY, function fx1, function fx2) {
	double eps;
	double root;
	accurateInfo info;

	printf("%5s %15s %20s", "eps", "root","precision\n");

	for (eps = 0.01; eps > 1e-12; eps *= 0.001) {
		root = accurateMethod(a, b, eps, &info, countY, fx1, fx2 );
		if (info.isGetRoot == -1) {
			printf("Error, root is undefined\n");
			return;
		}
		printf("%8.1e", info.eps);
		printf("%20.8e %20.8e \n", info.root, info._precision);
		
	}
}

void printTable2(double a, double b, function countY, function fx1, function fx2) {
	double eps;
	accurateInfo info1, info2;
	printf ("\n%5s %15s %10s" , "eps", "n-iteration", "n-Newton\n");
	for (eps = 0.01; eps > 1e-12; eps*=0.001) {
		accurateRootByIteration(a, b, eps, &info1, countY, fx1);
		accurateRootByNewton(a, b, eps, &info2, countY, fx1, fx2);
		if (info1.isGetRoot == -1 || info2.isGetRoot == -1) {
			printf("Error, root is undefined\n");
			return;
		}
		printf("%8.1e %8.1d %8.1d\n", eps, info1.steps, info2.steps);
	}
}