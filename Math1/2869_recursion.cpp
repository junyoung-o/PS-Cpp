#include <iostream>
using namespace std;

int a, b, v;

int cal(int night, int daytime, int r) {
	if(night <= v and v <= daytime) {
		return r;
	}
	int new_daytime, new_night, result;
	new_daytime = night + a;
	new_night = new_daytime - b;

	result = cal(new_night, new_daytime, r + 1);
	return result;
}

int main(void) {
	int result, current;
	
	cin >> a >> b >> v;

	result = cal(a-b, a, 1);

	cout << result << endl;

	return 0;

}