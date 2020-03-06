#include <stdio.h>
#include <math.h>

const int max_n = 10001;
bool arr[max_n];

void init() {
	for(int i = 0; i < max_n; i++) {
		arr[i] = true;
	}
	arr[1] = false;
}

void set_prime(int n) {
	for(int i = 2; i * i < n; i++) {
		for(int j = i * i; j < n; j += i) {
			arr[j] = false;
		}
	}
}

void show(int n) {
	int temp = 2, result1 = -1, result2 = -1;
	int mindiff = 10000;

	while(temp < n) {
		if(arr[temp] == true) {
			int remain = n - temp;
			if(arr[remain] == true) {
				if(abs(temp -remain) < mindiff) {
					result1 = temp;
					result2 = remain;
					mindiff = abs(temp - remain);
				}
			}
		}
		temp++;
	}

	printf("%d %d\n", result1, result2);
}


int main(void) {
	init();

	int t;
	scanf_s("%d", &t);

	for(int tt = 0; tt < t; tt++) {
		int n;
		scanf_s("%d", &n);

		set_prime(n);

		show(n);

	}

	return 0;
}