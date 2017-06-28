#include "lab1_sinh.h"
#include <exception>

using namespace std;
int main() {
	Sinh _sinh;

	try {
		_sinh.table1(-0.8, 6.9);
		_sinh.table2(-0.8, 6.9);
	}
	catch (exception &err) {
		cerr << "Exception occured...\n";
		cerr << err.what();
	}

	return 0;
}
