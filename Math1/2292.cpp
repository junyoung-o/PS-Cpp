#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	long long int n;
	long long int y = 0;

	cin >> n;

	if(n == 1) {
		cout << 1 << endl;
	}

	else {
		# 3n^2 - 3n + 2
		while((3 * pow(y, 2)) - 3 * y + 2 <= n) {
			y ++;
		}
		cout << y << endl;
	}

	return 0;
}
