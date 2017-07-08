/*
**** file: lab4_test.cpp
**** author: Levunets B.V
**** created: 28.10.16
*/
#include <iostream>
#include "lab4_tables.h"
#include "lab4_integration.h"
#include "lab4_myFunc.h"
#include <iomanip>

using namespace std;

int main() {
	double a = 0, b = 36;
	const double m4 = 43.563630918825;
	vector<double> refined_eps;

	refined_eps = table_Simpson_calculation(a, b, m4);
	table_refined_calculation(a, b, refined_eps);
	
	return 0;
}