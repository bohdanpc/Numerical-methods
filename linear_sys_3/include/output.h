/*
 * file: Gaussian_elimination.h
 * author: Levunets B.V, KV-42
 * created: 11.10.16
 * last modified: 23.10.16
 */

#pragma once

void print_system(double **, double *, int , char *tab = " ");
void print_gaussian_elimination(double **, double *, int n);
void print_direct_iteration(double **, double *, int n);