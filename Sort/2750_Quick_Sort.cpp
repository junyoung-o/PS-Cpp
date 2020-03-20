#include <iostream>
using namespace std;

int arr[1001];

int Partion(int *arr, int s, int e) {
	int pivot = arr[s];
	int lptr = s + 1, rptr = e;

	while(lptr <= rptr) {
		if(arr[lptr] <= pivot) {
			if(lptr <= rptr) {
				lptr++;
			}
		}

		if(arr[rptr] > pivot) {
			if(lptr <= rptr) {
				rptr--;
			}
		}

		if(lptr <= rptr) {
			swap(arr[lptr], arr[rptr]);
		}
	}

	swap(arr[s], arr[rptr]);

	return rptr;
}

void Quick_sort(int *arr, int s, int e) {
	if(s >= e) {
		return;
	}

	int m = Partion(arr, s, e);

	Quick_sort(arr, s, m);
	Quick_sort(arr, m+1, e);
}

void init() {
	for(int i = 0; i < 1000; i++) {
		arr[i] = 0;
	}
}

int main(void) {
	init();

	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}

	Quick_sort(arr, 0, n-1);

	for(int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}