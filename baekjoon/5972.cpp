#include<bits/stdc++.h>
using namespace std;
vector<int> cost;
vector<vector<pair<int, int>>> v;
int n, m;
void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	cost[start] = 0;
	while (!pq.empty()) {
		int ccost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second + ccost;
			if (ncost < cost[next]) {
				cost[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cost = vector<int>(n+1,987654321);
	v = vector<vector<pair<int, int>>>(n+1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dijkstra(1);
	cout << cost[n];
}