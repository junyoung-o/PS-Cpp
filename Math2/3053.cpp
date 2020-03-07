#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main(void) {
	double r;
	double r1, r2;

	cin >> r;

	printf("%.6f\n", r * r * M_PI);
	printf("%.6f\n", 2.0 * r * r);
	
	return 0;
}