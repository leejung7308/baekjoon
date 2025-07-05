#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
vector<int> money;
vector<LL> dist;
vector<vector<pii>> graph;
queue<int> q;
vector<bool> visited;
int n, s, e, m;
bool isValid() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == e) return true;
		for (const pii& p : graph[cur]) {
			int next = p.first;
			if (visited[next]) continue;
			q.push(next);
			visited[next] = true;
		}
	}
	return false;
}
int main() {
	FAST_IO;
	cin >> n >> s >> e >> m;
	dist = vector<LL>(n, LLINF);
	money.resize(n);
	visited.resize(n);
	graph.resize(n);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	for (int i = 0; i < n; i++) cin >> money[i];

	dist[s] = -money[s];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			for (const auto& p : graph[j]) {
				int next = p.first;
				LL ncost = p.second;
				if (dist[j] == LLINF) continue;
				if (dist[next] > dist[j] + ncost - money[next]) {
					dist[next] = dist[j] + ncost - money[next];
					if (i == n) visited[j] = true, q.push(j);
				}
			}
		}
	}
	if (dist[e] == LLINF) cout << "gg";
	else if (isValid()) cout << "Gee";
	else cout << -dist[e];
}