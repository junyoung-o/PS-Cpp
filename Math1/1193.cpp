#include <iostream>
using namespace std;

int main(void) {
	int n, b = 0;
	long long int result;
	cin >> n;
	
	while(n > b *(b + 1) * 0.5) {
		b++;
	}
	
	result = b * (b - 1) * 0.5 + 1;

	int x, y;

	if(b % 2 == 0) {
		x = 1;
		y = b;
		while(result < n) {
			x++;
			y--;		
			result++;
		}
	}
	else {
		x = b;
		y = 1;
		while(result < n) {
			x--;
			y++;		
			result++;
		}
	}
	
	cout << x << "/" << y << endl;


	return 0;
}