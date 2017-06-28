/* 
 * file: lab2_myEquation.c
 * Created: 25.09.16
 * last modified: 03.10.16
 * author: Levunets B.V., kv-42
 */
#include "lab2_myEquation.h"

double countY( double x){
	return exp(x) - 3*cos(2*x)+2*x+1; 
}

double countMinusY(double x) {
	return -exp(x) + 3*cos(2*x) - 2*x - 1;
}

double countMinus1DerivativeY(double x) {
	return -exp(x) - 6*sin(2*x) - 2;
}

double count1DerivativeY( double x){
	return exp(x) + 6*sin(2*x) + 2;
}

double count2DerivativeY( double x){
	return exp(x) + 12*cos(2*x);
}

double myDefaultIterationAccuration(double a, double b, double eps, accurateInfo* info) {
	if (count1DerivativeY(a) < 0) 
		return accurateRootByIteration(a, b, eps, info, &countMinusY, &countMinus1DerivativeY);
	return accurateRootByIteration(a, b, eps, info, &countY, &count1DerivativeY);
}

void printNewtonTable(double a,double b) {
	printf("\nAccuration by Newton's method, a=%.1lf, b=%.1lf:\n", a, b);
	printTable(a, b, (void*)&accurateRootByNewton, &countY, &count1DerivativeY, &count2DerivativeY);
}

void printIterationTable(double a, double b) {
	printf("\nAccuration by Iteration's method, a=%.1lf, b=%.1lf:\n", a, b);
	printTable(a, b, &myDefaultIterationAccuration, &countY, &count1DerivativeY, &count2DerivativeY);
}

void printGeneralTable(double a, double b) {
	printf("\nComparation of Iteration's and Newton's convergence, a=%.1lf, b=%.1lf", a, b);
	printTable2(a, b, &countY, &count1DerivativeY, &count2DerivativeY);
}
