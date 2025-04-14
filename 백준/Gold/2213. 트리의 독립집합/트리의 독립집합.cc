#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int ans = 0;
void dfs(const vector<vector<int>>& g, const vector<int>& w, vector<vector<int>>& dp, vector<bool>& visited, int cur) {
	dp[cur][1] += w[cur];
	for (const int& i : g[cur]) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(g, w, dp, visited, i);
		dp[cur][1] += dp[i][0];
		dp[cur][0] += max(dp[i][1], dp[i][0]);
		visited[i] = false;
	}
}
void getans(const vector<vector<int>>& dp, const vector<vector<int>>& g, vector<bool>& visited, vector<int>& ans, int cur, int prev) {
	if (dp[cur][1] > dp[cur][0] && !visited[prev]) {
		ans.push_back(cur);
		visited[cur] = true;
	}
	for (const int& i : g[cur]) {
		if (i == prev) continue;
		getans(dp, g, visited, ans, i, cur);
	}
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<int> weight(n + 1);
	vector<vector<int>> g(n + 1), dp(n + 1, vector<int>(2));
	vector<bool> visited(n + 1);
	vector<int> ans;
	for (int i = 1; i <= n; i++) cin >> weight[i];
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	visited[1] = true;
	dfs(g, weight, dp, visited, 1);
	visited = vector<bool>(n + 1);
	getans(dp, g, visited, ans, 1, 0);
	sort(ans.begin(), ans.end());
	cout << max(dp[1][1], dp[1][0]) << '\n';
	for (const int& i : ans) {
		cout << i << ' ';
	}
}