#include "output.h"
#include "sle_algorithms.h"
#include <iostream>
#include <iomanip>

using namespace std;

void print_system(double **linear_system, double *beta, int n,  char *tab) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout <<setw(7) << fixed << right << setprecision(2) << linear_system[i][j] << tab;
		cout << "| " << right << setw(7) << beta[i] << endl;
	}
	cout << endl;
}

void print_gaussian_elimination(double **linear_system, double *beta, int n) {
	cout << "-----Gaussian elimination-----\n";
	cout << "\nInput linear system:\n";
	print_system(linear_system, beta, n);

	double *result = gaussian_elimination(linear_system, beta, n);

	cout << setprecision(4) << "Resulting vector:\n";
	for (int i = 0; i < n; i++)
		cout << result[i] << "  ";
	cout << endl << endl;
	delete [] result;
}

void print_direct_iteration(double **linear_system, double *beta, int n) {
	int steps;
	double *result;
	cout << "-----Direct iteration-----\n";
	cout << "\nInput linear system:\n";
	print_system(linear_system, beta, n);

	for (double eps = 1; eps > 1e-3; eps *= 1e-1) {
		result = direct_iteration(linear_system, beta, n, eps, steps);
		cout << " steps: " << steps;
		cout << scientific << setprecision(1) << ", eps: " << eps << endl;

		cout << fixed << setprecision(4);
		cout << "Resulting vector:\n";
		for (int i = 0; i < n; i++)
			cout << right << setw(9) << result[i];
		cout << endl << endl;
		delete [] result;
	}
}