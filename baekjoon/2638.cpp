//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int n, m, ans=0, chz=0;
//vector<vector<int>> v(100, vector<int>(100));
//vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//void bfs(pair<int, int> s) {
//	queue<pair<int, int>> q, save;
//	vector<vector<bool>> vis(n, vector<bool>(m));
//	bool isClosed = true;
//	save.push(s);
//	q.push(s);
//	vis[s.first][s.second] = true;
//	while (!q.empty()) {
//		int y = q.front().first;
//		int x = q.front().second;
//		q.pop();
//		if (y == 0 || x == 0 || y == n - 1 || x == m - 1) {
//			isClosed = false;
//			break;
//		}
//		for (auto& d : dir) {
//			int ny = y + d.first;
//			int nx = x + d.second;
//			if (ny < 0 || ny >= n || nx < 0 || nx >= m || v[ny][nx] == 1) continue;
//			if (vis[ny][nx]) continue;
//			vis[ny][nx] = true;
//			save.push({ ny,nx });
//			q.push({ ny,nx });
//		}
//	}
//	if (isClosed) {
//		while (!save.empty()) {
//			int y = save.front().first, x = save.front().second;
//			save.pop();
//			v[y][x] = -1;
//		}
//	}
//	else {
//		while (!save.empty()) {
//			int y = save.front().first, x = save.front().second;
//			save.pop();
//			v[y][x] = 0;
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> v[i][j];
//			if (v[i][j] == 1) chz++;
//		}
//	}
//	for (int i = 2; i < n-2; i++) {
//		for (int j = 2; j < m-2; j++) {
//			if (v[i][j] == 0) bfs({ i,j });
//		}
//	}
//	queue<pair<int, int>> q;
//	while (chz) {
//		ans++;
//		for (int i = 1; i < n-1; i++) {
//			for (int j = 1; j < m-1; j++) {
//				if (v[i][j] == 1) {
//					int cnt = 0;
//					for (auto& d : dir) {
//						int ny = i + d.first, nx = j + d.second;
//						if (v[ny][nx] == 0) cnt++;
//					}
//					if (cnt >= 2) q.push({ i,j });
//				}
//			}
//		}
//		while (!q.empty()) {
//			int dy = q.front().first, dx = q.front().second;
//			q.pop();
//			v[dy][dx] = 0;
//			chz--;
//		}
//
//		for (int i = 2; i < n - 2; i++) {
//			for (int j = 2; j < m - 2; j++) {
//				if (v[i][j] == -1) bfs({ i,j });
//			}
//		}
//	}
//	cout << ans;
//}