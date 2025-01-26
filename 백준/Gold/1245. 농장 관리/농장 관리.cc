#include<bits/stdc++.h>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0);
using namespace std;
vector<pair<int, int>> dir = { {0,1},{1,0},{1,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1} };
int n, m;
vector<vector<int>> v;
vector<vector<bool>> visited;
bool bfs(int y, int x) {
	bool flag = true;
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty()) {
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();
		for (auto& d : dir) {
			int ny = cury + d.first;
			int nx = curx + d.second;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (v[cury][curx] < v[ny][nx]) flag = false;
			if (visited[ny][nx]) continue;
			if (v[cury][curx] != v[ny][nx]) continue;
			q.push({ ny,nx });
			visited[ny][nx] = true;
		}
	}
	return flag;
}
int main() {
	FAST_IO;
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<bool>>(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 0) continue;
			if (visited[i][j]) continue;
			if (bfs(i, j)) {
				cnt++;
			}
		}
	}
	cout << cnt;
}