#include <iostream>
#include <algorithm>
using namespace std;

#define INF 10000

string A, B;
string temp_A, temp_B;
int result = INF;

void solution();

int main(void) {
	// ����
	// 0. A�� ���̴� B�� ���� ���� �۰ų� ����.
	// 1. A �տ� ���ĺ��� �߰� �� �� �ִ�.
	// 2. A �ڿ� ���ĺ��� �߰� �� �� �ִ�.
	// 3. A, B �� �ִ��� ���� �����.
	// 4. A, B�� ���̸� ���

	// solution
	// 0. input
	cin >> A >> B;
	// 0 - 1.string �ڿ� '\n'�� ���δ�.
	temp_A = A + '\n';
	temp_B = B + '\n';

	// 1. A�� ���������� �����̸鼭 B�� ���Ѵ�.
	solution();

	// 2. �׶��� �ּڰ��� ����Ѵ�.
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