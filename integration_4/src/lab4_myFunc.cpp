/*
*** file: lab4_myFunc.cpp
*** author: Levunets B.V
*** created: 28.10.16
*** last modified: 28.10.16
*/

#include <cmath>

double calculate_integrand(const double x) {
	return x*((2 * cos(x / 2)) - x / 2 * sin(x / 2));
}


//calculate F(x)
double calculate_original(const double x) {
	return x*x*cos(x / 2);
}
