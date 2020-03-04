#include <iostream>
using namespace std;

int main(void) {
	int a, b, v;
	int result = 0, current = 0;
	cin >> a >> b >> v;

	while(true) {
		result += 1;
		current += a;
		if(current >= v) {
			break;
		}
		current -= b;
	}
	cout << result << endl;

	return 0;

}