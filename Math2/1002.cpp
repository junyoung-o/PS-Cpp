#include <stdio.h>
#include <math.h>

int main(void) {
	int testcase;
	scanf_s("%d", &testcase);

	for(int t = 0; t < testcase; t++) {
		int x1, y1, r1, x2, y2, r2;
		scanf_s("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		if(x1 == x2 and y1 == y2 and r1 == r2) {
			printf("%d\n", -1);
		}

		else {
			int distance;
			distance = pow(x1 - x2, 2) + pow(y1 - y2, 2);

			if(pow(r1 + r2, 2) == distance or pow(r1 - r2, 2) == distance) {
				printf("%d\n", 1);
			}

			else if(distance < pow(r1 - r2, 2)) {
				printf("%d\n", 0);
			}

			else if(pow(r1 + r2, 2) > distance and (x1 != x2 or y1 != y2)) {
				printf("%d\n", 2);
			}
			
			else {
				printf("%d\n", 0);
			}

		}
	}
	return 0;
}