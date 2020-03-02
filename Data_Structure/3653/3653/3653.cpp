#include <stdio.h>
#include <list>
#include <queue>
using namespace std;

queue<int> r;
int main(void) {
	int testcase;
	int n, m;

	scanf_s("%d", &testcase);

	for(int i = 0; i < testcase; i++) {
		list<int> l;

		scanf_s("%d", &n);
		scanf_s("%d", &m);

		for(int j = 1; j < n + 1; j++) {
			l.push_back(j);
		}

		for(int t = 0; t < m; t++) {
			int result, x;

			scanf_s("%d", &x);
			result = 0;

			while(true) {
				list<int>::iterator iter;
				list<int>::iterator re;

				for(iter = l.begin(); iter != l.end(); iter ++) {
					if(x == *iter) {
						re = iter;
						printf("%d", result);
						l.push_front(*iter);
						iter = l.end();
						break;
					}

					else {
						result += 1;
					}
				}
				l.erase(re);
				break;
			}
		}

		while(!r.empty()) {
			int t;
			t = r.front();
			r.pop();
			printf("%d ", t);
		}
		printf("\n");
	}

	return 0;
}