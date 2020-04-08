//libraries
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <set>
using namespace std;

// global variables
int n;
vector<int> nums;
vector<int>::iterator itr;

// function
void get_nums();
int avg_solution();
int mid_solution();
int freq_solution();
int range_solution();

// main
int main(void) {
	int avg_r, mid_r, freq_r, range_r;

	scanf_s("%d", &n);

	get_nums();
	sort(nums.begin(), nums.end());

	// »ê¼úÆò±Õ
	avg_r = avg_solution();
	printf("%d\n", avg_r);

	//// Áß¾Ó°ª
	mid_r = mid_solution();
	printf("%d\n", mid_r);

	//// ÃÖºó°ª
	freq_r = freq_solution();
	printf("%d\n", freq_r);

	//// ¹üÀ§
	range_r = range_solution();
	printf("%d\n", range_r);

	return 0;
}

void get_nums() {
	int temp = n;
	while(temp > 0) {
		int x;
		scanf_s("%d", &x);
		nums.push_back(x);
		temp--;
	}
}

int avg_solution() {
	double sum_n = 0;

	for(itr = nums.begin(); itr != nums.end(); itr++) {
		sum_n += *itr;
	}
	return round(sum_n / n);
}

int mid_solution() {
	int m;
	m = n / 2;
	return nums[m];
}

int freq_solution() {
	map<int, int> m;
	priority_queue<int> pq;
	set<int> s;
	set<int>::iterator sitr;


	int max_n = 0;
	for(itr = nums.begin(); itr != nums.end(); itr++) {
		if(m[*itr] == 0) {
			m[*itr] = 1;
			if(max_n < m[*itr]) {
				max_n = m[*itr];
			}
		}
		else {
			m[*itr]++;
			if(max_n < m[*itr]) {
				max_n = m[*itr];
			}
		}
	}

	for(itr = nums.begin(); itr != nums.end(); itr++) {
		if(m[*itr] == max_n) {
			s.insert(*itr);
		}
	}

	for(sitr = s.begin(); sitr != s.end(); sitr++) {
		pq.push(*sitr);
	}

	int cur = pq.top();
	pq.pop();
	int pre = cur;

	while(!pq.empty()) {
		pre = cur;
		cur = pq.top();
		pq.pop();
	}

	return pre;
}

int range_solution() {
	priority_queue<int> pq;
	int max_n = 0, min_n;

	for(itr = nums.begin(); itr != nums.end(); itr++) {
		pq.push(*itr);
	}

	max_n = pq.top();
	min_n = max_n;
	pq.pop();

	while(!pq.empty()) {
		min_n = pq.top();
		pq.pop();
	}

	return max_n - min_n;
}