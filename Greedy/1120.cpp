#include <iostream>
#include <algorithm>
using namespace std;

#define INF 10000

string A, B;
string temp_A, temp_B;
int result = INF;

void solution();

int main(void) {
	// 문제
	// 0. A의 길이는 B의 길이 보다 작거나 같다.
	// 1. A 앞에 알파벳을 추가 할 수 있다.
	// 2. A 뒤에 알파벳을 추가 할 수 있다.
	// 3. A, B 를 최대한 같게 만든다.
	// 4. A, B의 차이를 출력

	// solution
	// 0. input
	cin >> A >> B;
	// 0 - 1.string 뒤에 '\n'을 붙인다.
	temp_A = A + '\n';
	temp_B = B + '\n';

	// 1. A를 오른쪽으로 움직이면서 B랑 비교한다.
	solution();

	// 2. 그때의 최솟값을 출력한다.
	cout << result << endl;


	return 0;
}

int cal_dim(string x) {
	int temp = 0;
	while(x[temp] != '\n') {
		temp++;
	}
	return temp;
}

int cal_cmp(int a, int dim_x) {
	int cmp_local_result = 0;

	for(int i = 0; i < dim_x; i++) {
		if(A[i] != B[i +a]) {
			cmp_local_result += 1;
		}
	}
	return cmp_local_result;
}

void solution() {
	int dim_A, dim_B;
	int temp;

	dim_A = cal_dim(temp_A);
	dim_B = cal_dim(temp_B);

	if(dim_A == dim_B) {
		temp = cal_cmp(0, dim_A);
		result = min(result, temp);
	}
	else {
		for(int i = 0; i < dim_B - dim_A + 1; i++) {
			temp = cal_cmp(i, dim_A);
			result = min(result, temp);
		}
	}
}