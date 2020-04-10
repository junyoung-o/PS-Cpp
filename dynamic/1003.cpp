#include <iostream>
#include <vector>
using namespace std;

void solution();

int main(void) {
	int test_case;

	cin >> test_case;

	for(int t = 0; t < test_case; t++) {
		solution();
	}

	return 0;
}

void solution() {
	vector<int> arr_zero;
	vector<int> arr_one;
	int a;
	
	arr_zero.push_back(1);
	arr_zero.push_back(0);
	arr_zero.push_back(1);
	arr_zero.push_back(1);

	arr_one.push_back(0);
	arr_one.push_back(1);
	arr_one.push_back(1);
	arr_one.push_back(2);

	cin >> a;

	if(a > 3) {
		for(int i = 4; i < a + 1; i++) {
			arr_zero.push_back(arr_zero[i - 1] + arr_zero[i - 2]);
			arr_one.push_back(arr_one[i - 1] + arr_one[i - 2]);
		}
	}

	cout << arr_zero[a] << " " << arr_one[a] << endl;
}