// libaries
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// define
#define max_size 100 * 100 + 1

// global variable
int M, N, K;
vector<int> graph[max_size];
bool is_visit[max_size] = {false, };
vector<int> area_cnt;

// function
void make_graph();
void check_graph();
void bfs(int start);
void make_block(int x1, int y1, int x2, int y2);

// main
int main(void) {
	cin >> M >> N >> K;
	int x1, y1, x2, y2;

	make_graph();

	for(int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		make_block( x1, y1, x2, y2);
	}

	for(int i = 1; i < M * N + 1; i++) {
		if(!is_visit[i]) {
			bfs(i);
		}
	}

	sort(area_cnt.begin(), area_cnt.end());

	cout << area_cnt.size() << endl;

	for(int &result : area_cnt) {
		cout << result << " ";
	}

	return 0;
}

void node_link(int a, int b) {
	graph[a].push_back(b);
	graph[b].push_back(a);
}

int node_naming(int i, int j) {
	return (i - 1) * N + j;
}

void make_graph() {
	for(int i = 1; i < M + 1; i++) {
		for(int j = 1; j < N + 1; j++) {
			if(i > 1) {
				node_link(node_naming(i, j), node_naming(i - 1, j));
			}
			if(j > 1) {
				node_link(node_naming(i, j), node_naming(i, j - 1));
			}
		}
	}
}

void check_graph() {
	for(int i = 1; i < M * N + 1; i++) {
		cout << i << " : ";
		for(int &node : graph[i]) {
			cout << node << ", ";
		}
		cout << endl;
	}
}

void bfs(int start) {
	queue<int> node_list;

	if(is_visit[start]) {
		return;
	}

	is_visit[start] = true;

	node_list.push(start);

	int area = 1;

	while(!node_list.empty()) {
		int next = node_list.front();
		node_list.pop();

		for(int &next_pro : graph[next]) {
			if(!is_visit[next_pro]) {
				node_list.push(next_pro);
				is_visit[next_pro] = true;
				area++;
			}
		}
	}
	area_cnt.push_back(area);
}

void make_block(int x1, int y1, int x2, int y2) {
	int height = y2 - y1; //2
	int width = x2 - x1; //4
	int start = (M - y2) * N + (x1 + 1);

	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			is_visit[start + j] = true;
		}
		start += N;
	}
}