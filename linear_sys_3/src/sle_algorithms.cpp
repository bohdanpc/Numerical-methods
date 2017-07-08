#include <iostream>
#include <cmath>
#include <iomanip>
#include "sle_algorithms.h"
#include "output.h"

using namespace std;

double *copy_vector(double *vect_to_copy, int n);
double **copy_matrix(double **matr_to_copy, int n);

//iteration's functions
double *iteration(double **, double *, int, double, int &);
inline double calculate_q(double **, const int );
inline double calculate_norm(const double *, const double *, const int );
inline double *calculate_aproximation(double **alpha, double *beta, double *Xk0, int n);
void prepare_for_iteration(double **alpha, double *beta, int n);
void check_convergence(double **, int );

//elimination's functions
void dir_elimination(double **linear_system, double *beta, int n);
double *back_substitution(double **linear_system, double *beta, int n);


double *direct_iteration(double **alpha, double *beta, int n, double eps, int &k) {
	//output matrix is unchanged
	double *b = copy_vector(beta, n);
	double **linear_system = copy_matrix(alpha, n);
	
	check_convergence(linear_system, n);	//throws exception, if condition is not accomplished
	prepare_for_iteration(linear_system, b, n);

	return iteration(linear_system, b, n, eps, k);
}


double *iteration(double **alpha, double *beta, int n, double eps, int &k) {
	double *Xk1;
	double *Xk0 = new double[n];
	double q, norm;

	//initial approximation
	for (int i = 0; i < n; i++)		
		Xk0[i] = beta[i];

	q = calculate_q(alpha, n);		
	
	//first aproximation
	Xk1 = calculate_aproximation(alpha, beta, Xk0, n);	
	for (int i = 0; i < n; i++)
		Xk0[i] = Xk1[i];

	k = 2;
	while(1) {
		//calculate next approximation
		delete[] Xk1;
		Xk1 = calculate_aproximation(alpha, beta, Xk0, n);	
		norm = calculate_norm(Xk0, Xk1, n);

		if (norm <= eps*(1-q)/q)
			break;
		
		for (int i = 0; i < n; i++)
			Xk0[i] = Xk1[i];
		k++;
	}

	delete[] Xk0;
	for (int i = 0; i < n; i++)
		delete[] alpha[i];
	delete[] alpha;
	delete[] beta;
	return Xk1;
}


double calculate_q(double **alpha, const int n) {
	double sum, max = 0;

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++)
			sum += abs(alpha[i][j]);
		if (sum > max) 
			max = sum;
	}
	return max;
}


double calculate_norm(const double *Xk0,const double *Xk1,const int n) {
	double curr, max;

	max = abs(Xk0[0] - Xk1[0]);
	for (int i = 1; i < n; i++) {
		curr = abs(Xk0[i] - Xk1[i]);
		if (curr > max)
			max = curr;
	}
	return max;
}


double *calculate_aproximation(double **alpha, double *beta, double *Xk0, int n) {
	double *Xk = new double[n];
	double sum;

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {	//calculate second term
			if (i == j)
				continue;
			sum += alpha[i][j]*Xk0[j];
		}
		Xk[i] = beta[i] + sum;
	}
	return Xk;
}


//throws exception, if convergence condition is not accomplished
void check_convergence(double **alpha, int n) {
	double sum;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++)
			if (i != j)
				sum += abs(alpha[i][j]);
		if (abs(alpha[i][i]) <= sum)
			throw exception("Convergence condition is not accomplished...");
	}
}


void prepare_for_iteration(double **alpha, double *beta, int n) {
	for (int i = 0; i < n; i++) {
		beta[i] /= alpha[i][i];
		for (int j = 0; j < n; j++) 
			if (i != j) 
				alpha[i][j] /= -alpha[i][i];
		alpha[i][i] = 0;
	}
}


//create new linear_system and beta, Output matrix is unchanged
double* gaussian_elimination(double **lin_system, double *b, int n) {
	double *beta = copy_vector(b, n);
	double **linear_system = copy_matrix(lin_system, n);

	dir_elimination(linear_system, beta, n);
	double *answer = back_substitution(linear_system, beta, n);

	for (int i = 0; i < n; i++)
		delete [] linear_system[i];
	delete [] linear_system;
	delete [] beta;

	return answer;
}


void dir_elimination(double **linear_system, double *beta, int n) {
    double tmp;
    double *A1 = new double[n+1];	//+1 to get beta too

	for (int i = 0; i < n; i++) {
		tmp = linear_system[i][i];
		if (tmp == 0)
			throw exception("element at main diagonal is equal to zero...");

		for (int j = i; j < n; j++)
			linear_system[i][j] /= tmp;
		beta[i] /= tmp;

		for (int k = i; k < n; k++)				//save i-line
			A1[k] = linear_system[i][k];
		A1[n] = beta[i];

		for (int i1 = i+1; i1 < n; i1++) {
			double diff, Aik = linear_system[i1][i];
			for (int k = i; k < n; k++)	{
				diff = A1[k];
				diff *= Aik;
				linear_system[i1][k] -= diff;
			}
			diff = A1[n];
			diff *= Aik;
			beta[i1] -= diff;
		}
	}

	delete [] A1;
}

double *back_substitution(double **linear_system, double *beta, int n) {
	double sum;
	double *linear_sys_answer = new double[n];
	for (int k = n - 1; k >= 0; k--) {
		sum = 0;
		for (int j = k + 1; j < n; j++)
			sum += linear_system[k][j] * linear_sys_answer[j];
		linear_sys_answer[k] = beta[k] - sum;
	}
	return linear_sys_answer;
}

double *copy_vector(double *vect_to_copy, int n) {
	double *new_vect = new double[n];
	for (int i = 0; i < n; i++)
		new_vect[i] = vect_to_copy[i];

	return new_vect;
}

double **copy_matrix(double **matr_to_copy, int n) {
	double **new_matrix = new double*[n];
	for (int i = 0; i < n; i++)
		new_matrix[i] = new double[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			new_matrix[i][j] = matr_to_copy[i][j];

	return new_matrix;
}