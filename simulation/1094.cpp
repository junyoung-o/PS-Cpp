#include <iostream>
using namespace std;

int result = 0;
int x, remain = 0;

void _1094(int a);

int main(void) {
	cin >> x;

	if(x == 64) {
		remain += 64;
		result += 1;
	}

	else {
		_1094(64);
	}
	
	cout << result << endl;

	return 0;
}

void _1094(int a) {
	if(a == 1) {
		return;
	}

	int	m = a / 2;

	if(remain + m > x) {
		_1094(m);
	}

	else {
		result += 1;
		remain += m;
		_1094(m);
	}
}