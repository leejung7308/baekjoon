#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<vector<int>> v(50, vector<int>(50)), tmp(50, vector<int>(50));
vector<vector<bool>> visited;
int n, l, r;
bool populate(int y, int x) {
	DIR;
	if (visited[y][x]) return false;
	visited[y][x] = true;
	queue<pair<int, int>> q, m;
	q.push({ y,x });
	int p = 0, cnt = 0;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		p += v[cy][cx];
		cnt++;
		m.push({ cy,cx });
		for (const auto& d : dir) {
			int ny = cy + d.first;
			int nx = cx + d.second;
 			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (visited[ny][nx]) continue;
			if (abs(v[cy][cx] - v[ny][nx]) < l || r < abs(v[cy][cx] - v[ny][nx])) continue;
			visited[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
	if (m.size() == 1) {
		tmp[m.front().first][m.front().second] = v[m.front().first][m.front().second];
		return false;
	}
	while (!m.empty()) {
		tmp[m.front().first][m.front().second] = p / cnt;
		m.pop();
	}
	return true;
}
void printv() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << v[i][j] << ' ';
		cout << '\n';
	}
}
int main() {
	FAST_IO;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
	bool flag;
	int ans = -1;
	do {
		visited = vector<vector<bool>>(n, vector<bool>(n));
		flag = false;
		ans++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!flag) flag = populate(i, j);
				else populate(i, j);
			}
		}
		v = tmp;
	} while (flag);
	cout << ans;
}