#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define max_node 801
#define INF 1000000

vector<pair<int, int>> graph[max_node];
vector<int> dist(max_node, INF);
bool is_visit[3] = { false, };
int node, edge;
int v1, v2;

void set_graph();
void bfs0();
int bfs1();
int bfs2();

int main(void) {
	int r1 = INF, r2 = INF;
	cin >> node >> edge;

	// 0. graph 그리기, v1,v2 받기
	for(int i = 0; i < edge; i++) {
		set_graph();
	}

	cin >> v1 >> v2;

	// 1. 1-> n 다익스트라 한번 돌린다. = dist, 이때 v1, v2로 가는 경로가 있는지 각각 구해야한다.
	bfs0();

	// 2. dist를 가지고 2번 돌릴것이다.
	// 2 - 1. 1 -> V1까지 path가 있다면 dist[V1] -> n
	if(is_visit[1] == true) {
		r1 = bfs1();
	}

	// 2 - 2. 1 -> V2까지 path가 있다면 dist[V2] -> n
	if(is_visit[2] == true) {
		r2 = bfs2();
	}

	// 3. 앞서 했던 두개 dist[n]을 비교 후 가장 작은것.
	int result = min(r1, r2);

	if(result == INF) {
		cout << -1 << endl;
	}

	else {
		cout << result << endl;
	}

	return 0;
}

bool operator<(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

void set_graph() {
	int x, y, w;

	cin >> x >> y >> w;
	graph[x].push_back(make_pair(y, w));
	graph[y].push_back(make_pair(x, w));
}

void bfs0() {
	priority_queue<pair<int, int>> pq;

	dist[1] = 0;
	pq.push(make_pair(1, 0));

	while(!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();

		for(int i = 0; i < graph[cur_node].size(); i++) {
			int next_node = graph[cur_node][i].first;
			int next_cost = graph[cur_node][i].second + cur_cost;
			if(next_node == v1) {
				is_visit[1] = true;
			}
			if(next_node == v2) {
				is_visit[2] = true;
			}

			if(dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				pq.push(make_pair(next_node, next_cost));
			}
		}

	}
}

int bfs1() {
	priority_queue<pair<int, int>> pq;
	vector<int> dist1(node +1, INF);
	bool is_visit_v2 = false;

	dist1[v1] = dist[v1];
	pq.push(make_pair(v1, dist[v1]));

	while(!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();

		for(int i = 0; i < graph[cur_node].size(); i++) {
			int next_node = graph[cur_node][i].first;
			int next_cost = graph[cur_node][i].second + cur_cost;
			if(next_node == v2) {
				is_visit_v2 = true;
			}

			if(dist1[next_node] > next_cost) {
				dist1[next_node] = next_cost;
				pq.push(make_pair(next_node, next_cost));
			}
		}
	}

	if(is_visit_v2) {
		vector<int> dist2(node + 1, INF);
		dist2[v2] = dist1[v2];
		pq.push(make_pair(v2, dist2[v2]));

		while(!pq.empty()) {
			int cur_node = pq.top().first;
			int cur_cost = pq.top().second;
			pq.pop();

			for(int i = 0; i < graph[cur_node].size(); i++) {
				int next_node = graph[cur_node][i].first;
				int next_cost = graph[cur_node][i].second + cur_cost;

				if(dist2[next_node] > next_cost) {
					dist2[next_node] = next_cost;
					pq.push(make_pair(next_node, next_cost));
				}
			}
		}

		return dist2[node];
	}

	else {
		return INF;
	}
}

int bfs2() {
	priority_queue<pair<int, int>> pq;
	vector<int> dist2(node + 1, INF);
	bool is_visit_v1 = false;

	dist2[v2] = dist[v2];
	pq.push(make_pair(v2, dist[v2]));

	while(!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();

		for(int i = 0; i < graph[cur_node].size(); i++) {
			int next_node = graph[cur_node][i].first;
			int next_cost = graph[cur_node][i].second + cur_cost;
			if(next_node == v1) {
				is_visit_v1 = true;
			}

			if(dist2[next_node] > next_cost) {
				dist2[next_node] = next_cost;
				pq.push(make_pair(next_node, next_cost));
			}
		}
	}

	if(is_visit_v1) {
		vector<int> dist1(node + 1, INF);

		dist1[v1] = dist2[v1];
		pq.push(make_pair(v1, dist1[v1]));

		while(!pq.empty()) {
			int cur_node = pq.top().first;
			int cur_cost = pq.top().second;
			pq.pop();

			for(int i = 0; i < graph[cur_node].size(); i++) {
				int next_node = graph[cur_node][i].first;
				int next_cost = graph[cur_node][i].second + cur_cost;

				if(dist1[next_node] > next_cost) {
					dist1[next_node] = next_cost;
					pq.push(make_pair(next_node, next_cost));
				}
			}
		}

		return dist1[node];
	}

	else {
		return INF;
	}
}