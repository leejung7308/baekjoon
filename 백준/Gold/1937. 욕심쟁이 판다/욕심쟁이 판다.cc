#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define LL long long
#define pii pair<int,int>
using namespace std;
DIR;
int n, ans = 0;
int v[500][500], dp[500][500];
int dfs(int y, int x) {
	if (dp[y][x] != 0) return dp[y][x];
	dp[y][x] = 1;
	for (const auto& d : dir) {
		int ny = y + d.first;
		int nx = x + d.second;
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (v[ny][nx] <= v[y][x]) continue;
		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
	}
	return dp[y][x];
}
int main() {
	FAST_IO;
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans = max(ans, dfs(i, j));
	cout << ans;
}