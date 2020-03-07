#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void) {
	int x, y, z;

	while(true) {
		scanf("%d %d %d", &x, &y, &z);

		if(x == 0 or y == 0 or z == 0) {
			break;
		}

		int max_n;
		max_n = max(x, y);
		max_n = max(max_n, z);

		if(x == max_n) {
			if(pow(y, 2) + pow(z, 2) == pow(max_n,2)) {
				printf("%s\n", "right");
			}
			else {
				printf("%s\n", "wrong");
			}
		}

		if(y == max_n) {
			if(pow(x, 2) + pow(z, 2) == pow(max_n,2)) {
				printf("%s\n", "right");
			}
			else {
				printf("%s\n", "wrong");
			}
		}

		if(z == max_n) {
			if(pow(y, 2) + pow(x, 2) == pow(max_n,2)) {
				printf("%s\n", "right");
			}
			else {
				printf("%s\n", "wrong");
			}
		}
	}

	return 0;
}