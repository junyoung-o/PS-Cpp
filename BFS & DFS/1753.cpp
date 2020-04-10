#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define max_num 20001
#define INF 1000000

vector<pair<int, int>> graph[max_num];
int node, edge, start;

void set_graph();
vector<int> bfs();
void print_result(vector<int> result);

int main(void) {
	cin >> node >> edge;
	cin >> start;

	set_graph();

	print_result(bfs());

	return 0;
}

void set_graph() {
	int x, y, w;

	for(int i = 0; i < edge; i++) {
		cin >> x >> y >> w;
		graph[x].push_back(make_pair(y, w));
	}
}

vector<int> bfs() {
	priority_queue<pair<int, int>> pq;
	vector<int> dist(node + 1, INF);

	pq.push(make_pair(0, start));
	dist[start] = 0;

	while(!pq.empty()) {
		int cur_node = pq.top().second;
		int cur_cost = -pq.top().first;

		pq.pop();

		for(int i = 0; i < graph[cur_node].size(); i++) {
			int next_node = graph[cur_node][i].first;
			int next_cost = graph[cur_node][i].second + cur_cost;

			if(dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				pq.push(make_pair(-next_cost, next_node));
			}
		}
	}

	return dist;
}

void print_result(vector<int> result) {
	for(int i = 1; i < node + 1; i++) {
		if(result[i] == INF) {
			cout << "INF" << endl;
		}

		else {
			cout << result[i] << endl;
		}
	}
}