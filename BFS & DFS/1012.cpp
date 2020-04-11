#include <iostream>
#include <vector>
using namespace std;

#define max_node 51 * 51 + 1

vector<int> graph[max_node];
vector<int> result;
bool is_visit[max_node] = { false, };
bool is_one[max_node] = { false, };
int m, n, k, cnt;


void init();
void set_graph();
void point_one();
void bfs(int node);

int main(void) {
	int test_case;

	cin >> test_case;

	for(int test = 0; test < test_case; test++) {
		init();
		int local_result = 0;

		cin >> m >> n >> k;

		set_graph();

		for(int i = 0; i < k; i++) {
			point_one();
		}

		for(int i = 0; i < max_node; i++) {
			if(is_visit[i] == false && is_one[i] == true) {
				bfs(i);
				local_result += 1;
			}
		}
		result.push_back(local_result);
	}

	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}

void init() {
	for(int i = 0; i < max_node; i++) {
		graph[i].clear();
		is_visit[i] = false;
		is_one[i] = false;
	}
	m = n = k = 0;
}

void point_one() {
	int x, y;

	cin >> x >> y;

	int node = y * m + (x + 1);

	is_one[node] = true;
}

void set_graph() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int node = (j + 1) + i * m;

			if(j > 0) {
				graph[node].push_back(node - 1);
				graph[node-1].push_back(node);

			}

			if(i > 0) {
				graph[node].push_back(node - m);
				graph[node - m].push_back(node);
			}
		}
	}
}

void bfs(int node) {
	if(is_visit[node] == true) {
		return;
	}

	if(is_one[node] == false) {
		return;
	}

	is_visit[node] = true;

	for(int i = 0; i < graph[node].size(); i++) {
		int next_node = graph[node][i];

		if(is_visit[next_node] == false && is_one[next_node] == true) {
			bfs(next_node);
		}
	}
}