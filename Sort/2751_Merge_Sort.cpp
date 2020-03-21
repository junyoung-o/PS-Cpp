// library
#include <stdio.h>

// global_variables
const int max_n = 1000001;
int arr[max_n];
int sorted[max_n];
void Merge_Sort(int *arr, int s, int e);
void merge(int *arr, int s, int m, int e);

// functions
void Merge_Sort(int *arr, int s, int e) {
	if(s == e) {
		return;
	}

	int m = (s + e) / 2;
	Merge_Sort(arr, s, m);
	Merge_Sort(arr, m+1, e);

	merge(arr, s, m, e);
}

void merge(int *arr, int s, int m, int e) {
	int lptr = s, rptr = m + 1;
	int ind = s;

	while(lptr <= m and rptr <= e) {
		if(arr[lptr] <= arr[rptr]) {
			sorted[ind++] = arr[lptr++];
		}
		else {
			sorted[ind++] = arr[rptr++];
		}
	}

	if(lptr > m) {
		for(int iter = rptr; iter < e + 1; iter++) {
			sorted[ind++] = arr[iter];
		}
	}

	if(rptr > e) {
		for(int iter = lptr; iter < m + 1; iter++) {
			sorted[ind++] = arr[iter];
		}
	}

	for(int i = s; i < e + 1; i++) {
		arr[i] = sorted[i];
	}
}

void init() {
	for(int i = 0; i < max_n; i++) {
		arr[i] = 0;
		sorted[i] = 0;
	}
}

// main
int main(void) {
	init();

	int n;
	scanf_s("%d", &n);

	for(int i = 0; i < n; i++) {
		int temp;
		scanf_s("%d", &temp);
		arr[i] = temp;
	}

	Merge_Sort(arr, 0, n - 1);

	for(int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}