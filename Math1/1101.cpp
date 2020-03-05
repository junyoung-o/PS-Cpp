#include <stdio.h>
#include <math.h>

int main(void) {
	int x, y, t;

	scanf("%d", &t);

	for(int tt = 0; tt < t; tt++) {
		scanf("%d %d", &x, &y);
		int n = 1, temp, result;
		temp = y - x;

		while(pow(n,2) <= temp) {
			n++;
		}

		n--;
		result = 2 * n - 1;

		long long int t1 = pow(n, 2);
		long long int t2 = pow(n + 1, 2);

		if(t1 < temp and temp <= ((t2 - t1) / 2) + t1) {
			result += 1;
		}

		else if((t2 - t1) / 2 + t1 < temp and temp <t2) {
			result += 2;
		}

		printf("%d\n", result);
	}
	
	return 0;
}