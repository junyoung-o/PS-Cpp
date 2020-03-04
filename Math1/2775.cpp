#include <iostream>
using namespace std;

int arr[15][15];

void init_arr() {
	for(int t = 0; t < 15; t++) {
		arr[0][t] = t;
		arr[t][1] = 1;
	}

	for(int i = 1; i < 15; i++) {
		for(int j = 1; j < 15; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
}

int main(void) {
	int t, a, b;

	init_arr();

	cin >> t;

	for(int k = 0; k < t; k++) {
		cin >> a >> b;

		cout << arr[a][b] << endl;
	}

	return 0;
}