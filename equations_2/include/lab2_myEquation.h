/* 
 * file: lab2_myEquation.h
 * Created: 02.09.16
 * last modified: 03.10.16
 * author: Levunets B.V., kv-42
 */

#pragma once
#include "math.h"
#include "lab2_Equation.h"

double countY( double );
double count1DerivativeY(double);
double count2DerivativeY(double);
double myDefaultIterationAccuration(double, double, double, accurateInfo* );	//Iteration's methond depending on sign(f'(x))
void printNewtonTable(double, double);
void printIterationTable(double, double);

void printGeneralTable(double, double);