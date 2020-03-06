#include <stdio.h>

const int max_n = 123457;
bool arr[max_n * 2];

void init() {
	for(int i = 0; i < max_n * 2; i++) {
		arr[i] = true;
	}
	arr[1] = false;
}

void cal_p(int n2) {
	for(int i = 2; i * i <= n2; i++) {
		for(int j = i * i; j <= n2; j+=i) {
			arr[j] = false;
		}
	}
}

int cal_result(int n, int n2) {
	int result = 0;

	for(int i = n + 1; i <= n2; i++) {
		if(arr[i] == true) {
			result += 1;
		}
	}
	return result;
}

int main(void) {
	init();

	int n;

	while(true) {
		scanf_s("%d", &n);
		
		if(n == 0) {
			break;
		}

		int n2 = n * 2, result;

		cal_p(n2);
		result = cal_result(n, n2);
		printf("%d\n", result);
	}

	return 0;
}