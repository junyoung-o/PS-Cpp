// Quick_Sort 로 구현 했지만 어느정도 진행되다가 시간 초과가 난다.
// 그 이유로 worst case에서 O(nlogn) 이 아닌 O(n^2)이라고 예상한다.
#include <stdio.h>

int arr[1000001];

void swap(int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;

	return;
}

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
			swap(lptr, rptr);
		}
	}

	swap(s, rptr);

	return rptr;
}

void Quick_sort(int *arr, int s, int e) {
	if(s >= e) {
		return;
	}

	int m = Partion(arr, s, e);

	Quick_sort(arr, s, m);
	Quick_sort(arr, m+1, e);

	return;
}

void init() {
	for(int i = 0; i < 1000001; i++) {
		arr[i] = 0;
	}
}

int main(void) {
	init();

	int n, temp;
	scanf_s("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf_s("%d", &temp);
		arr[i] = temp;
	}

	Quick_sort(arr, 0, n-1);

	for(int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}