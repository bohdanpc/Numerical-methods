/*
*** file: lab4_integration.cpp
*** author: Levunets B.V
*** created: 28.10.16
*** last modified: 30.10.16
*/

#include <cmath>
#include "lab4_integration.h"

double calculate_by_Newton_Leibn(const double a, const double b, double(*calc_origin) (const double x)) {
	return calc_origin(b) - calc_origin(a);
}


//used to calculate integral with fixed length-n
double calculate_next_aproximation(const double a, const double b, const int n, double(*calc_integrand) (const double x)) {
	double sigma1 = 0, sigma2 = 0;
	double h = (b - a) / n;

	for (int i = 1; i < n - 1; i += 2) {
		sigma1 += calc_integrand(a + h*i);
		sigma2 += calc_integrand(a + h*(i + 1));
	}
	sigma1 += calc_integrand(a + h*(n - 1));
	
	return h / 3 * (calc_integrand(a) + calc_integrand(b) + 4 * sigma1 + 2 * sigma2);
}


double calculate_refined_Simpson(const double a, const double b, const double eps, 
	double &h, double(*calc_integrand) (const double x)) {

	double i_n, i_2n;
	int n = (int) ceil((b - a) / pow(eps, 0.25));

	//in case of n - odd
	if (n % 2 != 0)
		n++;

	h = (b - a) / n;

	i_n = calculate_next_aproximation(a, b, n, calc_integrand);
	n *= 2;
	i_2n = calculate_next_aproximation(a, b, n, calc_integrand);

	double new_eps = 15 * eps;

	while (abs(i_n - i_2n) > new_eps) {
		i_n = i_2n;
		n *= 2;
		i_2n = calculate_next_aproximation(a, b, n, calc_integrand);
	}

	//used to to get 'h' to print in the table
	
	return i_n;
}


double calculate_by_Simpson(const double a, const double b,const double eps,
	double &h, const double m4, double(*calc_integrand) (const double x)) {

	h = pow(180.0 * eps / ((b - a) * m4), 0.25);
	int n = (int) ((b - a) / h);
	double sigma1 = 0, sigma2 = 0;

	//in case of n - odd
	if (n % 2 != 0) 
		n++;
	h = (b - a) / n;

	for (int i = 1; i < n - 1; i += 2) {
		sigma1 += calc_integrand(a + h*i);
		sigma2 += calc_integrand(a + h*(i + 1));
	}

	sigma1 += calc_integrand(a + h*(n - 1));
	return h / 3.0 * (calc_integrand(a) + calc_integrand(b) + 4 * sigma1 + 2 * sigma2);
}

