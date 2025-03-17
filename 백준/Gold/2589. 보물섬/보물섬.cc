#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
DIR;
int bfs(const vector<string>& v, int y, int x) {
	vector<vector<bool>> visited(v.size(), vector<bool>(v[0].size(), false));
	queue<pair<int, pair<int, int>>>q;
	visited[y][x] = true;
	q.push({ 0,{y,x} });
	int cost = 0;
	while (!q.empty()) {
		int cy = q.front().second.first;
		int cx = q.front().second.second;
		cost = q.front().first;
		q.pop();
		for (const auto& d : dir) {
			int ny = cy + d.first;
			int nx = cx + d.second;
			int ncost = cost + 1;
			if (ny < 0 || ny >= v.size() || nx < 0 || nx >= v[0].size()) continue;
			if (visited[ny][nx]) continue;
			if (v[ny][nx] == 'W') continue;
			visited[ny][nx] = true;
			q.push({ ncost,{ny,nx} });
		}
	}
	return cost;
}
int main() {
	FAST_IO;
	int n, m, ans = 0;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(v[i][j]=='L') ans = max(ans, bfs(v, i, j));
		}
	}
	cout << ans;
}