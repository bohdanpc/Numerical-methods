/*
*** file: lab4_tables.h
*** author: Levunets B.V
*** created: 29.10.16
*** last modified: 29.10.16
*/

#pragma once
#include <vector>

void table_refined_calculation(const double a, const double b, std::vector<double> &refined_eps);
std::vector<double> table_Simpson_calculation(const double a, const double b, const double m4);