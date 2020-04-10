#include <iostream>
#include <vector>
using namespace std;

vector<int> result;

void _1010();
void print_result();

int main(void) {
	int test_case;

	cin >> test_case;

	for(int t = 0; t < test_case; t++) {
		_1010();
	}

	print_result();

	return 0;
}

long long int factorial1(int a, int b) {
	long long int re = 1;
	for(int i = a; i >= a-b+1; i--) {
		re *= i;
	}
	return re;
}

long long int factorial2(int a) {
	long long int re = 1;
	for(int i = 1; i < a + 1; i++) {
		re *= i;
	}
	return re;
}

void _1010() {
	int n, m;
	cin >> n >> m;

	long long int r1, r2;

	if(n > m / 2) {
		n = m - n;
	}

	r1 = factorial1(m, n);
	r2 = factorial2(n);

	result.push_back(r1 / r2);
}

void print_result() {
	vector<int>::iterator itr;

	for(itr = result.begin(); itr != result.end(); itr++) {
		cout << *itr << endl;
	}
}