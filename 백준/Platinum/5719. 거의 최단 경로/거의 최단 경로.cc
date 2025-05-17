#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n, m, s, d;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin	>> s >> d;
		vector<vector<int>> graph(n,vector<int>(n));
		vector<int> dist(n, INF);
		vector<vector<int>> prev(n);
		while (m--) {
			int u, v, p;
			cin >> u >> v >> p;
			graph[u][v] = p;
		}
		priority_queue<pair<int, int>> pq;
		pq.push({ 0,s });
		dist[s] = 0;
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			if (dist[cur] < cost) continue;
			for (int i = 0; i < n; i++) {
				int next = i;
				int ncost = cost + graph[cur][next];
				if (graph[cur][next] == 0) continue;
				if (dist[next] == ncost) {
					prev[next].push_back(cur);
				}
				if (dist[next] > ncost) {
					prev[next].clear();
					prev[next].push_back(cur);
					dist[next] = ncost;
					pq.push({ -ncost,next });
				}
			}
		}
		fill(dist.begin(), dist.end(), INF);
		queue<int> q;
		vector<bool> visited(n);
		q.push(d);
		visited[d] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : prev[cur]) {
				graph[next][cur] = 0;
				if (visited[next]) continue;
				q.push(next);
				visited[next] = true;
			}
		}
		pq.push({ 0,s });
		dist[s] = 0;
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			if (dist[cur] < cost) continue;
			for (int i = 0; i < n; i++) {
				int next = i;
				int ncost = cost + graph[cur][next];
				if (graph[cur][next] == 0) continue;
				if (dist[next] > ncost) {
					dist[next] = ncost;
					pq.push({ -ncost,next });
				}
			}
		}
		if (dist[d] != INF) cout << dist[d] << '\n';
		else cout << "-1\n";
	}
}