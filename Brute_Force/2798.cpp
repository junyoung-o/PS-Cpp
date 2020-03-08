#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[101];
void init() {
	for(int i = 0; i < 101; i++) {
		arr[i] = 0;
	}
}

bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	init();

	int num, limit, x, result = 0;
	
	scanf_s("%d %d", &num, &limit);

	for(int i = 0; i < num; i++) {
		scanf_s("%d", &x);
		arr[i] = x;
	}

	sort(arr, arr + num, compare);

	for(int i = 0; i < num; i++) {
		int a = arr[i];
		for(int j = i + 1; j < num; j++) {
			int b = arr[j];
			for(int k = j + 1; k < num; k++) {
				int c = arr[k];
				if(a + b + c <= limit) {
					if(a + b + c >= result) {
						result = a + b + c;
					}
				}
			}
		}
	}

	printf("%d\n", result);

	return 0;
}