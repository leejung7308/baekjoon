#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int findp(vector<int>& p, int x) {
	if (x == p[x]) return x;
	return p[x] = findp(p, p[x]);
}
void uni(vector<int>& p, int a, int b) {
	if (a == b) return;
	a = findp(p, a);
	b = findp(p, b);
	a < b ? p[b] = a : p[a] = b;
}
int main() {
	FAST_IO;
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	vector<vector<int>> visited(n, vector<int>(m));
	vector<int> parent(1);
	parent[0] = -1;
	int p = 1;
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;
			parent.push_back(p);
			visited[i][j] = p;
			queue<pair<int, int>> q;
			q.push({ i,j });
			while (!q.empty()) {
				int cy = q.front().first;
				int cx = q.front().second;
				char c = v[cy][cx];
				q.pop();
				int ny, nx;
				switch (c) {
				case 'D':
					ny = cy + 1;
					nx = cx;
					break;
				case 'U':
					ny = cy - 1;
					nx = cx;
					break;
				case 'L':
					ny = cy;
					nx = cx - 1;
					break;
				case 'R':
					ny = cy;
					nx = cx + 1;
				}
				int np = visited[ny][nx];
				if (np) {
					uni(parent, np, p);
					continue;
				}
				visited[ny][nx] = p;
				q.push({ ny,nx });
			}
			p++;
		}
	}
	int ans = 0;
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)cout << visited[i][j] << ' ';
		cout << '\n';
	}*/
	for (int i = 1; i < parent.size(); i++) if (i == findp(parent, i)) ans++;
	cout << ans;
}