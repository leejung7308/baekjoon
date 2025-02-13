#include<bits/stdc++.h>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int n, m;
vector<vector<int>> edges, ans;
void dijkstra(int s) {
	vector<int> dist(n + 1, INF), p(n + 1);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	dist[s] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 1; i <= n; i++) {
			if (edges[cur][i] == INF) continue;
			int ncost = cost + edges[cur][i];
			int next = i;
			if (dist[next] > ncost) {
				p[next] = cur;
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i == s) continue;
		int cur = i;
		int next;
		while (true) {
			next = p[cur];
			if (next == s) break;
			cur = next;
		}
		ans[s][i] = cur;
	}
}
int main() {
	FAST_IO;
	cin >> n >> m;
	edges = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
	ans = vector<vector<int>>(n + 1, vector<int>(n + 1));
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a][b] = c;
		edges[b][a] = c;
	}
	for (int i = 1; i <= n; i++) dijkstra(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << "- ";
				continue;
			}
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}