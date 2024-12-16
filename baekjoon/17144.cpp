//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int r, c, t, ans = 0;
//	vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//	cin >> r >> c >> t;
//	vector<pair<int, int>> ac;
//	vector<vector<int>> v(r, vector<int>(c));
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			cin >> v[i][j];
//			if (v[i][j] == -1) ac.push_back({ i,j });
//		}
//	}
//	stack<pair<pair<int, int>, int>> st;
//	while (t--) {
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < c; j++) {
//				if (v[i][j] >= 5) {
//					int cnt = 0;
//					int dif = v[i][j] / 5;
//					for (auto& d : dir) {
//						int dy = d.first;
//						int dx = d.second;
//						int ny = i + dy;
//						int nx = j + dx;
//						if (ny < 0 || ny >= r || nx < 0 || nx >= c || v[ny][nx] == -1) continue;
//						cnt++;
//						if (make_pair(ny, nx) == ac[0] || make_pair(ny, nx) == ac[1]) continue;
//						st.push({ {ny,nx},dif });
//					}
//					v[i][j] -= dif * cnt;
//				}
//			}
//		}
//		while (!st.empty()) {
//			int y = st.top().first.first;
//			int x = st.top().first.second;
//			int c = st.top().second;
//			st.pop();
//			v[y][x] += c;
//		}
//		int y = ac[0].first-1;
//		int x = ac[0].second;
//		while (true) {
//			if (y == 0) {
//				v[y][x] = v[y][x + 1];
//				x++;
//				break;
//			}
//			else {
//				v[y][x] = v[y - 1][x];
//			}
//			y--;
//		}
//		while (true) {
//			if (x == c - 1) {
//				v[y][x] = v[y + 1][x];
//				y++;
//				break;
//			}
//			else {
//				v[y][x] = v[y][x + 1];
//			}
//			x++;
//		}
//		while (true) {
//			if (y == ac[0].first) {
//				v[y][x] = v[y][x - 1];
//				x--;
//				break;
//			}
//			else {
//				v[y][x] = v[y + 1][x];
//			}
//			y++;
//		}
//		while (true) {
//			if (x == 1) {
//				v[y][x] = 0;
//				break;
//			}
//			else {
//				v[y][x] = v[y][x - 1];
//			}
//			x--;
//		}
//		y = ac[1].first + 1;
//		x = ac[1].second;
//		while (true) {
//			if (y == r-1) {
//				v[y][x] = v[y][x + 1];
//				x++;
//				break;
//			}
//			else {
//				v[y][x] = v[y + 1][x];
//			}
//			y++;
//		}
//		while (true) {
//			if (x == c - 1) {
//				v[y][x] = v[y - 1][x];
//				y--;
//				break;
//			}
//			else {
//				v[y][x] = v[y][x + 1];
//			}
//			x++;
//		}
//		while (true) {
//			if (y == ac[1].first) {
//				v[y][x] = v[y][x - 1];
//				x--;
//				break;
//			}
//			else {
//				v[y][x] = v[y - 1][x];
//			}
//			y--;
//		}
//		while (true) {
//			if (x == 1) {
//				v[y][x] = 0;
//				break;
//			}
//			else {
//				v[y][x] = v[y][x - 1];
//			}
//			x--;
//		}
//	}
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			if (v[i][j] == -1) continue;
//			ans += v[i][j];
//		}
//	}
//	cout << ans;
//}