#include <iostream>
#include <vector>
using namespace std;

vector<int> results;

void test_case();
void print_result();

int main(void) {
	int t;

	cin >> t;

	for(int i = 0; i < t; i++) {
		test_case();
	}

	print_result();

	return 0;
}

int divide_conquer(int a, int b) {
	if(b == 1) {
		return a % 10;
	}
	
	if(b % 2 == 0) {
		int m = b / 2;
		int r1 = divide_conquer(a, m);
		
		return ((r1 % 10) * (r1 % 10)) %10;
	}

	else {
		int m = b / 2;
		int r1 = divide_conquer(a, m);
		int r2 = divide_conquer(a, m + 1);

		return ((r1 %10)* (r2 % 10))%10;
	}
}

void test_case() {
	int a, b;
	cin >> a >> b;

	int result = divide_conquer(a, b);

	if(result == 0) {
		result = 10;
	}

	results.push_back(result);
}

void print_result() {
	for(int i = 0; i < results.size(); i++) {
		cout << results[i] << endl;
	}
}