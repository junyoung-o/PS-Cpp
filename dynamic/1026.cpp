#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define max_num 51

typedef struct bs {
	int data;
	int ind;
	int rank;
}bs;

bool operator<(bs a, bs b) {
	return a.data < b.data;
}

int arr_A[max_num] = { 0, };
bs arr_B[max_num];
priority_queue<bs> rank_B;
int n, result = 0;

void set_a(int i);
void set_b(int i);
void set_rank_b();
void print_result();

int main(void) {
	cin >> n;

	// set a, b
	for(int i = 0; i < n; i++) {
		set_a(i);
	}

	for(int i = 0; i < n; i++) {
		set_b(i);
	}

	// 1. a를 정렬한다.
	sort(&arr_A[0], &arr_A[n]);

	// 2. b에 있는 원소들의 순위를 저장한다.
	set_rank_b();

	// 3. a[i의 순위] * b[i] 를 result에 더해준다.
	print_result();

	cout << result << endl;

	return 0;
}

void set_a(int i) {
	int x;
	cin >> x;

	arr_A[i] = x;
}

void set_b(int i) {
	int x;
	cin >> x;

	arr_B[i].data = x;
	arr_B[i].ind = i;
	arr_B[i].rank = 0;

	rank_B.push(arr_B[i]);
}

void print_result() {
	for(int i = 0; i < n; i++) {
		result += arr_A[arr_B[i].rank] * arr_B[i].data;
	}
}

void set_rank_b() {
	int r = 0;

	while(!rank_B.empty()) {
		bs temp = rank_B.top();
		rank_B.pop();

		arr_B[temp.ind].rank = r;
		r++;
	}
}