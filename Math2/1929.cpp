#include <stdio.h>

const int max_n = 1000001;
bool arr[max_n];

void init() {
	for(int i = 0; i < max_n; i++) {
		arr[i] = true;
	}
	arr[1] = false;
}

void cal_p(int n) {
	if(n == 1) {
		return;
	}

	for(int i = 2; i * i <= n; i++) {
		for(int j = i * i; j <= n; j += i) {
				arr[j] = false;
			}
	}
}

void show(int m, int n) {
	for(int i = m; i <= n; i++) {
		if(arr[i] == true) {
			printf("%d\n", i);
		}
	}
}

int main(void) {
	init();

	int m, n;
	scanf_s("%d %d", &m, &n);

	cal_p(n);
   
	show(m, n);

	return 0;
}