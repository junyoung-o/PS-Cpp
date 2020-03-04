#include <iostream>
using namespace std;


int main(void) {
	int a, b, v;
	int result = 0;

	cin >> a >> b >> v;

	int temp = a - b;

	while(result * temp > v or v > result * temp + b) {
		result += 1;
	}

	
	cout << result << endl;

	return 0;

}
