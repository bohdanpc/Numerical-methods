/*
*** file: lab4_tables.cpp
*** author: Levunets B.V
*** created: 29.10.16
*** last modified: 30.10.16
*/

#include "lab4_tables.h"
#include "lab4_myFunc.h"
#include "lab4_integration.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void table_refined_calculation(const double a, const double b, vector<double> &refined_eps) {
	double accur_integral, aprox_integral;
	double h;

	cout << scientific;

	cout << "-----table 2, refined Simpson's calculation-----" << endl;
	cout << setw(12) << "eps" << setw(26) << "integration step" << setw(17) << "abs error" << endl;

	for (vector<double>::iterator eps = refined_eps.begin(); eps != refined_eps.end(); eps++) {
		cout << setw(18) << setprecision(12) << *eps;
		accur_integral = calculate_by_Newton_Leibn(a, b, calculate_original);
		aprox_integral = calculate_refined_Simpson(a, b, *eps, h, calculate_integrand);

		cout << setprecision(12) << setw(22) << h;
		cout << setw(22) << abs(accur_integral - aprox_integral) << endl;
	}
}


vector<double> table_Simpson_calculation(const double a, const double b, const double m4) {
	double accur_integral;
	double aprox_integral;
	double h;
	vector<double> eps_for_refined;

	cout << scientific;

	cout << "-----table 1, Simpson's calculation-----" << endl;
	cout << setw(6) << "eps" << setw(23) << "integration step" << 
		setw(20) << "accurate value" << setw(17) << "abs error" << endl;

	for (double eps = 1.0e-01; eps > 1.0e-12; eps *= 1.0e-3) {
		cout << setw(5) << setprecision(1) << eps;
		accur_integral = calculate_by_Newton_Leibn(a, b, calculate_original);
		aprox_integral = calculate_by_Simpson(a, b, eps, h, m4, calculate_integrand);

		cout << setprecision(12) << setw(22) << h;
		cout << setprecision(12) << setw(22) << accur_integral;
		double abs_error = abs(accur_integral - aprox_integral);
		cout << setw(22) << abs_error << endl;
		eps_for_refined.push_back(abs_error);
	}
	cout << endl;

	return eps_for_refined;
}