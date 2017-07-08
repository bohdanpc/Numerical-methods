#include <iostream>
#include "sle_algorithms.h"
#include "output.h"
#include <exception>

using namespace std;
#define n 4

void fill_system(double **alpha, double *beta);
void fill_iteration_system(double **alpha, double *beta);

int main() {
	double **system;
	double *beta = new double[n];

	system = new double*[n];
	for (int i = 0; i < n; i++)
		system[i] = new double[n];

	try {
		fill_system(system, beta);
		print_gaussian_elimination(system, beta, n);
		fill_iteration_system(system, beta);
		print_direct_iteration(system, beta, n);
	}
	catch(exception &excp) {
		cout << "Exception occured: " << excp.what() << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] system[i];

	delete [] system;
	delete [] beta;
	return 0;
}


void fill_iteration_system(double **system, double *beta) {
	system[0][0] = 60;
	system[0][1] = -7;
	system[0][2] = 39;
	system[0][3] = -6;

	system[1][0] = 15;
	system[1][1] = 41;
	system[1][2] = 16;
	system[1][3] = 9;

	system[2][0] = 0;
	system[2][1] = 3;
	system[2][2] = 20;
	system[2][3] = 16;

	system[3][0] = 15;
	system[3][1] = 9;
	system[3][2] = 17;
	system[3][3] = 45;

	beta[0] = 69;
	beta[1] = 76;
	beta[2] = 100;
	beta[3] = 257;
}


void fill_system(double **system, double *beta) {
	system[0][0] = 15;
	system[0][1] = 8;
	system[0][2] = 19;
	system[0][3] = 7;

	system[1][0] = 15;
	system[1][1] = 41;
	system[1][2] = 16;
	system[1][3] = 9;

	system[2][0] = 0;
	system[2][1] = 3;
	system[2][2] = 20;
	system[2][3] = 16;

	
	system[3][0] = 15;
	system[3][1] = 7;
	system[3][2] = 8;
	system[3][3] = 18;

	beta[0] = 69;
	beta[1] = 76;
	beta[2] = 100;
	beta[3] = 113;
}