#include<bits/stdc++.h>
#include<unordered_map>
#define INF 2000000001
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
bool isleaf(const vector<vector<int>>& g, vector<bool>& visited, vector<bool>& used, int& ans, int cur) {
	bool ret = true;
	for (const int& i : g[cur]) {
		if (visited[i]) continue;
		visited[i] = true;
		if (isleaf(g, visited, used, ans, i) && !used[cur]) {
			ret = false;
			ans++;
			used[cur] = true;
		}
		visited[i] = false;
	}
	return ret;
}
int main() {
	FAST_IO;
	int n, ans = 0;
	cin >> n;
	vector<bool> used(n + 1), visited(n + 1);
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	visited[1] = true;
	isleaf(g, visited, used, ans, 1);
	cout << ans;
}