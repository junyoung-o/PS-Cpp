#include <iostream>
using namespace std;

#define max_num 1000 + 1

int n, result = 0;

void solution();

int main(void) {
	cin >> n;

	solution();

	cout << result << endl;
	return 0;
}

void solution() {
	long long int arr[max_num];
	arr[0] = 1;
	arr[1] = 2;
	// arr[i] = arr[i-1] + (b+1), i = a±îÁö
	for(int i = 2; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i-2];
		arr[i] %= 10007;
	}
	result += arr[n - 1] % 10007;
}