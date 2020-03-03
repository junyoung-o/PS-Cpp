#include <iostream>
using namespace std;

long long int dif, result;
long long int a, b, c;
int main(void) {
	cin >> a >> b >> c;

	dif = c - b;

	if(dif <= 0) {
		cout << -1 << endl;
	}

	else {
		result = a / dif;
		cout << result + 1 << endl;
	}

	return 0;
}