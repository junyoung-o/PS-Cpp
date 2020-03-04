#include <stdio.h>
#include <math.h>
using namespace std;

int main(void) {
	int a, b, v;
	int result;
	
	scanf_s("%d %d %d", &a, &b, &v);

	result = ceil((v - b) / (a - b) + ((v - b) % (a - b))* 0.1);

	printf("%d", result);

	return 0;
}

