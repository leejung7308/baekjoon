//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//vector<vector<int>> v;
//vector<pair<int, int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
//vector<vector<bool>> visited;
//int ans = 0;
//int n, m, cnt = 0;
//int block = 0;
//void bfs(int y, int x) {
//	if (visited[y][x]) return;
//	block++;
//	queue<pair<int, int>> q;
//	q.push({ y,x });
//	visited[y][x] = true;
//	while (!q.empty()) {
//		int cy = q.front().first;
//		int cx = q.front().second;
//		q.pop();
//		for (auto& d : dir) {
//			int ny = cy + d.first;
//			int nx = cx + d.second;
//			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
//			if (visited[ny][nx]) continue;
//			if (v[ny][nx] == 0) continue;
//			visited[ny][nx] = true;
//			q.push({ ny,nx });
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	bool flag = false;
//	cin >> n >> m;
//	v = vector<vector<int>>(n, vector<int>(m));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> v[i][j];
//			if (v[i][j] != 0) cnt++;
//		}
//	}
//	while (cnt) {
//		ans++;
//		block = 0;
//		visited = vector<vector<bool>>(n, vector<bool>(m));
//		vector<pair<pair<int, int>, int>> p;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (v[i][j] != 0) {
//					int tmp = 0;
//					for (auto& d : dir) {
//						int ny = i + d.first;
//						int nx = j + d.second;
//						if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
//						if (v[ny][nx] == 0) tmp++;
//					}
//					p.push_back({ {i,j},tmp });
//				}
//			}
//		}
//		for (auto& i : p) {
//			int y = i.first.first;
//			int x = i.first.second;
//			int cost = i.second;
//			v[y][x] -= cost;
//			if (v[y][x] < 0 || v[y][x] == 0) {
//				v[y][x] = 0;
//				cnt--;
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (v[i][j] != 0) bfs(i, j);
//			}
//		}
//		if (block > 1) {
//			flag = true;
//			break;
//		}
//	}
//	if (flag) cout << ans;
//	else cout << 0;
//}