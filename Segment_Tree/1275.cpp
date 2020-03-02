#include <stdio.h>
#define max_size 100001

int list_n[max_size];

int main(void) {
	int n, q;
	
	scanf_s("%d", &n);
	scanf_s("%d", &q);

	for(int i = 0; i < n; i++) {
		int temp;
		scanf_s("%d", &temp);
		list_n[i] = temp;
	}

	for(int i = 0; i < q; i ++) {
		int x, y, a, b;
		long long int result = 0;
		scanf_s("%d %d", &x, &y);
		scanf_s("%d %d", &a, &b);

		x--;
		y--;
		a--;

		if(x > y) {
			int temp;
			temp = x;
			x = y;
			y = temp;
		}

		for(int j = x; j <= y; j ++) {
			result += list_n[j];
		}

		list_n[a] = b;
		printf("%lld\n",result);
	}
	return 0;
}