#include <stdio.h>

const int max_n = 10001;
int arr[max_n];

void init() {
	for(int i = 0; i < max_n; i++) {
		arr[i] = 0;
	}
}

int main(void) {
	init();

	int n, main_max_n = 0;
	scanf_s("%d", &n);

	for(int i = 1; i < n + 1; i++) {
		int temp;
		scanf_s("%d", &temp);

		if(temp >= main_max_n) {
			main_max_n = temp;
		}

		arr[temp]++;
	}

	for(int i = 1; i < main_max_n+1; i++) {
		while(arr[i] > 0) {
			printf("%d\n", i);
			arr[i]--;
		}
	}

	return 0;
}