#include <stdio.h>

const int max_n = 10000001;
const int max_num = 10001;

int arr[max_n];
int result[max_n];
int count_i[max_num];
int count_a[max_num];

void init() {
	for(int i = 0; i < max_n; i++) {
		arr[i] = 0;
		result[i] = 0;
	}

	for(int i = 0; i < max_num; i++) {
		count_i[i] = 0;
		count_a[i] = 0;
	}
}

int main(void) {
	init();

	int n;
	scanf_s("%d", &n);

	int main_max_n = 0;
	for(int i = 0; i < n; i++) {
		int temp;
		scanf_s("%d", &temp);

		arr[i] = temp;
		if(temp > main_max_n) {
			main_max_n = temp;
		}
		count_i[arr[i]]++;
	}

	for(int i = 1; i < max_num; i++) {
		count_a[i] = count_i[i] + count_a[i - 1];
	}

	for(int i = max_n - 1; i > -1; i--) {
		result[count_a[arr[i]]] = arr[i];
		count_a[arr[i]]--;
	}

	for(int i = 1; i < n+1; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}