#include <iostream>
using namespace std;
int arr[101];

void init_value() {
	for(int i = 0; i < 101; i++) {
		arr[i] = -1;
	}
}

int main(void) {
	init_value();

	int n, result = 0;
	cin >> n;

	for(int i = 0; i < n; i++) {
		int x;

		cin >> x;
		arr[i] = x;
	}

	for(int j = 0; j < 101; j++) {
		int a = arr[j];
		bool check = true;

		if(a == -1) {
			break;
		}

		if(a != 1) {
			for(int i = 2; i < a; i++) {
				if(a % i == 0 and a != i) {
					check = false;
					break;
				}
			}
			if(check) {
				result += 1;
			}
		}
	}
	

	cout << result << endl;

	return 0;
}