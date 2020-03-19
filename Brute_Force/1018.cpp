#include <stdio.h>
#include <algorithm>
using namespace std;

char map[51][51];
int main(void) {
	int n, m;

	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf_s("\n");
		for (int j = 0; j < m; j++) {
			scanf_s("%c", &map[i][j]);
		}
	}

	int result = 65;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {

			int cnt = 0;
			for (int a = i; a < i + 8; a++) {
				for (int b = j; b < j + 8; b++) {
					if ((a % 2) ^ (b % 2)) {
						if (map[a][b] == 'B') {
							cnt++;
						}
					}
					else {
						if (map[a][b] == 'W') {
							cnt++;
						}
					}
				}
			}

			result = min(cnt, result);
			result = min(64 - cnt, result);
		}
	}

	printf("%d", result);

	return 0;
}