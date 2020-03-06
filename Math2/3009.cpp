#include <iostream>
#include <map>
using namespace std;

int main(void) {
	map<int, int> x_list;
	map<int, int> y_list;
	int r1 = -1, r2 = -1;

	for(int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		if(x_list.count(x) == 0) {
			x_list[x] = 1;
		}
		else {
			x_list[x] += 1;
		}
		if(y_list.count(y) == 0) {
			y_list[y] = 1;
		}
		else {
			y_list[y] += 1;
		}
	}

	map<int, int>::iterator iter;
	for(iter = x_list.begin(); iter != x_list.end(); iter++) {
		if(iter->second == 1) {
			r1 = iter->first;
			break;
		}
	}
	for(iter = y_list.begin(); iter != y_list.end(); iter++) {
		if(iter->second == 1) {
			r2 = iter->first;
			break;
		}
	}

	printf("%d %d", r1, r2);
	return 0;
}