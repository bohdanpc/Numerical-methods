/* 
 * file: lab2_test.c
 * Created: 25.09.16
 * last modified: 03.10.16
 * author: Levunets B.V., kv-42
 */ 

#include "lab2_myEquation.h"

int main() {
	printNewtonTable(-2.0, -1.5);
	printIterationTable(-2.0, -1.5);

	printNewtonTable(-1.3, -0.81);
	printIterationTable(-1.3, -0.81);

	printNewtonTable(-0.1, 0.4);
	printIterationTable(-0.1, 0.4);

	printGeneralTable(-2.0, -1.5);
	return 0;
}