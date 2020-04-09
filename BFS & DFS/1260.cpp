// libraries
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// global variables
#define max_node 1000 + 1
vector<int> graph[max_node];
queue<int> dfs_node;
queue<int> bfs_node;
bool is_visit[max_node] = { false, };
int node, edge, start;

// functions
void init();
void get_graph();
void sort_graph();
void dfs(int vertex);
void bfs(int start);
void print_result();

// main
int main(void) {
	cin >> node >> edge >> start;

	// 그래프 만들기
	for(int i = 0; i < edge; i++) {
		get_graph();
	}

	// 정렬
	sort_graph();

	// dfs
	dfs(start);

	// is_visit 초기화 후 bfs
	init();
	bfs(start);

	// 출력
	print_result();

	return 0;
}

void init() {
	for(int i = 0; i < max_node; i++) {
		is_visit[i] = false;
	}
}

void get_graph() {
	int x, y;

	cin >> x >> y;

	graph[x].push_back(y);
	graph[y].push_back(x);
}

void sort_graph() {
	for(int i = 0; i < node; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
}

void dfs(int vertex) {
	if(is_visit[vertex] == true) {
		return;
	}

	is_visit[vertex] = true;
	dfs_node.push(vertex);

	for(int i = 0; i < graph[vertex].size(); i++) {
		int next = graph[vertex][i];
		if(is_visit[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> node_list;
	if(is_visit[start] == true) {
		return;
	}

	is_visit[start] = true;
	node_list.push(start);
	bfs_node.push(start);

	while(!node_list.empty()) {
		int cur = node_list.front();
		node_list.pop();
		for(int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if(is_visit[next] == false) {
				node_list.push(next);
				is_visit[next] = true;
				bfs_node.push(next);
			}
		}
	}
}

void print_result() {
	while(!dfs_node.empty()) {
		int x = dfs_node.front();
		dfs_node.pop();
		cout << x << " ";
	}
	cout << endl;
	while(!bfs_node.empty()) {
		int x = bfs_node.front();
		bfs_node.pop();
		cout << x << " ";
	}
}