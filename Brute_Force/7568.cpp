#include <iostream>
using namespace std;

typedef struct People {
	int weight;
	int height;
	int rank;
}people;

people p[51];
int main(void) {
	int n;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		p[i].weight = x;
		p[i].height = y;
		p[i].rank = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i].weight > p[j].weight and p[i].height > p[j].height) {
				p[j].rank++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << p[i].rank << " ";
	}

	return 0;
}