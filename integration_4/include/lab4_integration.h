/* 
*** file: lab4_integration.h
*** author: Levunets B.V
*** created: 28.10.16
*** last modified: 28.10.16
*/

#pragma once
double calculate_by_Newton_Leibn(const double a, const double b, double(*calc_origin) (const double x));

double calculate_by_Simpson(const double a, const double b,
	const double eps, double &h, const double m4, double(*calc_integrand) (const double x));

double calculate_refined_Simpson(const double a, const double b,
	const double eps, double &h, double(*calc_integrand) (const double x));
