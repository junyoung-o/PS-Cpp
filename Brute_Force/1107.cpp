// libaries
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// global variables
int botton[11] = { 0, 1,2,3,4,5,6,7,8,9 };
int n, curr = 100;

// function
void set_botton();
int cal_digits(int x);
int get_max_botton_num();
bool checking_botton(int a);
int solution(int a);

// main
int main(void) {
	int digits;
	int about_n, max_botton_num;
	cin >> n;

	// 고장난 버튼 설정
	set_botton();

	// 자릿수 구하고
	digits = cal_digits(n);

	// 적당히 n에 가까운 수 setting <- using 자릿수 (한자리 작은 가장 큰수의 조합)
	max_botton_num = get_max_botton_num();

	about_n = max_botton_num * pow(10,digits-2);

	// n이 될떄까지 temp ++ 하면서 temp일때의 최솟값을 구한다.
	// 조건 temp에 botton 조합에 고장난 버튼이 있는지.
	int result = 5000001;
	while(about_n <= 1000000) {
		if(checking_botton(about_n)) {
			int x = solution(about_n);

			result = min(result, x);
		}

		about_n++;
	}

	// 버튼이 다 고장 났을때
	if(result == 5000001) {
		cout << abs(n - curr) << endl;
	}

	else {
		cout << result << endl;
	}

	return 0;
}

void set_botton() {
	int m;

	cin >> m;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		botton[x] = -1;
	}
}

int cal_digits(int x) {
	int digits = 1, temp = x;
	while(temp / 10 > 0) {
		digits++;
		temp = int(temp / 10);
	}
	return digits;
}

int get_max_botton_num() {
	int max_botton_num = 0;
	for(int &i : botton) {
		if(i != -1) {
			if(i > max_botton_num) {
				max_botton_num = i;
			}
		}
	}
	return max_botton_num;
}

bool checking_botton(int a) {
	int digits, temp = a, num_of_d;
	bool check = true;
	digits = cal_digits(a) - 1;

	for(int i = digits; i >= 0; i--) {
		check = true;

		num_of_d = temp / (pow(10, i));
		temp = temp - num_of_d * pow(10, i);

		if(botton[num_of_d] == -1) {
			check = false;
			break;
		}
	}

	return check;
}

int solution(int a) {
	int digits;
	digits = cal_digits(a);

	int r1 = abs(n - a) + digits;
	int r2 = abs(n - curr);

	return min(r1, r2);
}