#include <iostream>
using namespace std;

int main(void) {
	int n, result = 0;
	int temp, r;

	cin >> n;

	temp = n % 5;
	r = n / 5;

	// temp = 0, 1, 2, 3, 4
	if(temp == 0) {
		result = r;
	}

	if(temp == 1) {
		if(r >= 1) {
			r--;
			result = r + 2;
		}
		else {
			result = -1;
		}
	}

	if(temp == 2) {
		if(r >= 2) {
			r -= 2;
			result = r + 4;
		}
		else {
			result = -1;
		}
	}

	if(temp == 3) {
		result = r + 1;
	}

	if(temp == 4) {
		if(r >= 1) {
			r -= 1;
			result = r + 3;
		}

		else {
			result = -1;
		}
	}

	
	cout << result << endl;
	return 0;
}