#include <iostream>
using namespace std;

bool arr[10001];
void init() {
	for(int i = 0; i < 10001; i++) {
		arr[i] = true;
	}
	arr[1] = false;
}

void cal(int n) {
	if(n == 1) {
		return;
	}

	for(int i = 2; i * i < n + 1; i++) {
		for(int j = i * i; j < n + 1; j += i) {
			arr[j] = false;
		}
	}
}

int cal_sum(int m, int n) {
	int sum = 0;
	for(int i = m; i < n + 1; i++) {
		if(arr[i] == true) {
			sum += i;
		}
	}
	return sum;
}

int cal_min(int m, int n) {
	int min = -1;
	for(int i = m; i < n + 1; i++) {
		if(arr[i] == true) {
			min = i;
			break;
		}
	}

	return min;
}

int main(void) {
	init();

	int m, n;
	int result, min;
	cin >> m >> n;

	cal(n);
	min = cal_min(m, n);

	if(min == -1) {
		cout << -1 << endl;
	}

	else {
		result = cal_sum(m, n);
		cout << result << endl;
		cout << min << endl;
	}
	return 0;
}