#include <stdio.h>

int main(void) {
	int t, h, w, n;

	scanf_s("%d", &t);

	for(int k = 0; k <t; k++) {
		int x, y, temp;
		scanf_s("%d %d %d", &h, &w, &n);

		temp = n / h;
		
		if(n % h == 0) {
			x = temp;
			y = h;
		}

		else {
			x = temp + 1;
			y = n - h * temp;
		}

		if(x < 10) {
			printf("%d0%d\n", y, x);
		}
		else {
			printf("%d%d\n", y, x);
		}
	}
	return 0;
}