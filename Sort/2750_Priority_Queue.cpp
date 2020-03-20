#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
int main(void) {
	int n;
	cin >> n;


	for(int i = 0; i < n; i++){
		int x;

		cin >> x;

		pq.push(-x);
	}

	while(!pq.empty()) {
		int temp;

		temp = pq.top();

		pq.pop();
		cout << -temp << endl;
	}

	return 0;
}