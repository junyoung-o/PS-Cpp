#include <iostream>
using namespace std;

int main(void) {
	int x, y, w, h;
	int r1, r2;
	cin >> x >> y >> w >> h;

	if(h - y >= y) {
		r1 = y;
	}
	else {
		r1 = h - y;
	}
	if(w - x >= x) {
		r2 = x;
	}
	else {
		r2 = w - x;
	}
	if(r1 >= r2) {
		cout << r2 << endl;
	}
	else {
		cout << r1 << endl;
	}

	
	return 0;
}