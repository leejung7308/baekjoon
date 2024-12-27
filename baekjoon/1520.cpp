//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int n, m;
//vector<vector<int>> v, dp;
//vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//int dfs(int y, int x) {
//	if (dp[y][x] != -1) return dp[y][x];
//	if (y == m && x == n) return 1;
//	dp[y][x] = 0;
//	for (auto& d : dir) {
//		int ny = y + d.first;
//		int nx = x + d.second;
//		if (v[y][x] <= v[ny][nx]) continue;
//		dp[y][x] += dfs(ny, nx);
//	}
//	return dp[y][x];
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> m >> n;
//	v = vector<vector<int>>(m + 2, vector<int>(n + 2, INF));
//	dp = vector<vector<int>>(m + 2, vector<int>(n + 2, -1));
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= n; j++) {
//			cin >> v[i][j];
//		}
//	}
//	cout << dfs(1, 1);
//}