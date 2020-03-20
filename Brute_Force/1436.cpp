#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n, cnt = 0;
	int result = 666;
	string s;

	cin >> n;

	while(true) {
		s = to_string(result);

		if(s.find("666") != -1) {
			cnt++;
		}

		if(cnt == n) {
			cout << result << endl;
			break;
		}
		result++;
	}

	return 0;
}