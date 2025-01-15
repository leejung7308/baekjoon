#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
vector<vector<int>> edges;
vector<int> child;
vector<bool> visited;
int dfs(int cur, int n) {
	child[cur]++;
	for (int& next : edges[cur]) {
		if (visited[next]) continue;
		visited[next] = true;
		child[cur] += dfs(next, n + 1);
		visited[next] = false;
	}
	return child[cur];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, r, q;
	cin >> n >> r >> q;
	edges = vector<vector<int>>(n + 1);
	child = vector<int>(n + 1);
	visited = vector<bool>(n + 1);
	while (--n) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	visited[r] = true;
	dfs(r, 0);
	while (q--) {
		int tmp;
		cin >> tmp;
		cout << child[tmp] << '\n';
	}
}