#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> graph(n + 1);
	vector<int> indegree(n + 1);
	while (m--) {
		int s, e, t;
		cin >> s >> e >> t;
		indegree[e]++;
		graph[s].push_back({ e,t });
	}
	int s, e;
	vector<int> dist(n + 1);
	vector<vector<int>> prev(n + 1);
	cin >> s >> e;
	queue<pair<int, int>> q;
	q.push({ s,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();
		for (const auto& p : graph[cur]) {
			int next = p.first;
			int ncost = cost + p.second;
			if (dist[next] == ncost) prev[next].push_back(cur);
			if (dist[next] < ncost) {
				prev[next].clear();
				prev[next].push_back(cur);
				dist[next] = ncost;
			}
			if (--indegree[next] == 0) q.push({ next,dist[next] });
		}
	}
	int ans = 0;
	queue<int> g;
	vector<bool> visited(n + 1);
	g.push(e);
	while (!g.empty()) {
		int cur = g.front();
		g.pop();
		for (int next : prev[cur]) {
			ans++;
			if (visited[next]) continue;
			visited[next] = true;
			g.push(next);
		}
	}
	cout << dist[e] << '\n' << ans;
}