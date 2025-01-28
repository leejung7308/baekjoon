#include<bits/stdc++.h>
#include<unordered_map>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define LL long long
#define LD long double
using namespace std;
vector<vector<int>> graphs;
vector<vector<bool>> order;
void bfs(int start, int n) {
	vector<bool> visited(n + 1);
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& g : graphs[cur]) {
			int next = g;
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
			order[start][next] = true;
		}
	}
}
int main() {
	FAST_IO;
	int n, k;
	cin >> n >> k;
	graphs = vector<vector<int>>(n + 1);
	order = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
	while (k--) {
		int a, b;
		cin >> a >> b;
		graphs[a].push_back(b);
		order[a][b] = true;
	}
	for (int i = 1; i <= n; i++) bfs(i, n);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (order[a][b]) cout << -1 << '\n';
		else if (order[b][a]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}