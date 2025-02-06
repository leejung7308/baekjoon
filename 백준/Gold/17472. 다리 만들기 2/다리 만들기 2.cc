#include<bits/stdc++.h>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0);
using namespace std;
int n, m, continent = 0, ans = 0;
vector<int> parent;
vector<vector<int>> v;
vector<vector<pair<int, int>>> pos;
vector<vector<bool>> visited;
vector<pair<int, int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
priority_queue<pair<int, pair<int, int>>> pq;
void checkcontinent(int y, int x) {
	if (v[y][x] == 0) return;
	if (visited[y][x]) return;
	continent++;
	visited[y][x] = true;
	v[y][x] = continent;
	pos[continent].push_back({y,x});
	queue<pair<int, int>> q;
	q.push({ y,x });
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (pair<int,int>& d : dir) {
			int ny = cy + d.first;
			int nx = cx + d.second;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (v[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			v[ny][nx] = continent;
			pos[continent].push_back({ ny,nx });
			q.push({ ny,nx });
		}
	}
}
void checkbridge(int curcontinent) {
	visited = vector<vector<bool>>(n, vector<bool>(m));
	queue<pair<int, int>> q;
	for (auto& p : pos[curcontinent]) q.push(p);
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (auto& d : dir) {
			int dy = d.first, dx = d.second;
			int ny = cy + dy, nx = cx + dx;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (v[ny][nx] == curcontinent) continue;
			int length = 0;
			while (!(ny < 0 || ny >= n || nx < 0 || nx >= m)) {
				if (v[ny][nx] == 0) length++;
				else if (v[ny][nx] != curcontinent) {
					if (length > 1) {
						pq.push({ -length,{curcontinent,v[ny][nx]} });
					}
					break;
				}
				else break;
				ny += dy;
				nx += dx;
			}
		}
	}
}
int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa < pb) parent[pb] = pa;
	else parent[pa] = pb;
}
bool iscycle(int a, int b) {
	return find(a) == find(b);
}
void kruskal() {
	while (!pq.empty()) {
		int length = -pq.top().first;
		int from = pq.top().second.first;
		int to = pq.top().second.second;
		pq.pop();
		if (iscycle(from, to)) continue;
		ans += length;
		Union(from, to);
	}
}
int main() {
	FAST_IO;
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<bool>>(n, vector<bool>(m));
	pos = vector<vector<pair<int,int>>>(7);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			checkcontinent(i, j);
		}
	}
	parent = vector<int>(continent + 1);
	for (int i = 1; i <= continent; i++) {
		parent[i] = i;
		checkbridge(i);
	}
	kruskal();
	bool flag = true;
	for (int i = 1; i <= continent; i++) find(i);
	int p = parent[1];
	for (int i = 2; i <= continent; i++) if (parent[i] != p) flag = false;
	if (flag) cout << ans;
	else cout << -1;
}