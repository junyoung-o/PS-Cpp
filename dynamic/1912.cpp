#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int n, max_sum = -1001;
int temp = -1001;

void get_arr();
int PS(int a);

int main(void) {
	cin >> n;

	for(int i = 0; i < n; i++) {
		get_arr();
	}

	// result = PS(n - 1), PS(n) = max(arr[n], PS(n-1) + arr[n])
	int t1 = PS(n - 1);

	cout << max_sum << endl;

	return 0;
}

void get_arr() {
	int x;

	cin >> x;

	arr.push_back(x);
}

int PS(int a) {
	if(a == 0) {
		max_sum = max(temp, arr[a]);
		temp = max_sum;
		return max_sum;
	}

	int cmp_n1 = PS(a - 1) + arr[a];
	int cmp_n2 = arr[a];

	int cmp_n = max(cmp_n1, cmp_n2);

	if(cmp_n > temp) {
		temp = cmp_n;
		if(max_sum < temp) {
			max_sum = temp;
		}
	}

	else {
		temp = -1001;
	}

	return max(temp, cmp_n);
}