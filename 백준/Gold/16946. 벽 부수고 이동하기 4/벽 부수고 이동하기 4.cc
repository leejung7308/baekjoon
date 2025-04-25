#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
DIR;
void bfs(vector<vector<int>>& v, vector<vector<bool>>& visited, int y, int x) {
	int n = v.size(), m = v[0].size();
	queue<pair<int, int>> q;
	queue<pair<int, int>> memo;
	q.push({ y,x });
	visited[y][x] = true;
	int cnt = 1;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (const auto& d : dir) {
			int ny = cy + d.first;
			int nx = cx + d.second;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (v[ny][nx] != 0) {
				visited[ny][nx] = true;
				memo.push({ ny,nx });
				continue;
			}
			visited[ny][nx] = true;
			q.push({ ny,nx });
			cnt++;
		}
	}
	while (!memo.empty()) {
		v[memo.front().first][memo.front().second] += cnt;
		visited[memo.front().first][memo.front().second] = false;
		memo.pop();
	}
}
int main() {
	FAST_IO;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) v[i][j] = tmp[j] - '0';
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		if (!visited[i][j] && v[i][j] == 0) bfs(v, visited, i, j);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << v[i][j] % 10;
		cout << '\n';
	}
}