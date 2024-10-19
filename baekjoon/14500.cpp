//#include<bits/stdc++.h>
//using namespace std;
//int n, m, sum = 0, ans = -1;
//vector<vector<bool>> vst;
//vector<vector<int>> v;
//vector<pair<int, int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
//void dfs(int y, int x, int num) {
//	if (y < 0 || x < 0 || y >= n || x >= m) return;
//	if (vst[y][x]) return;
//	if (num == 4) {
//		ans = max(ans, sum);
//		return;
//	}
//	vst[y][x] = true;
//	sum += v[y][x];
//	for (int i = 0; i < dir.size(); i++) {
//		dfs(y + dir[i].first, x + dir[i].second, num + 1);
//	}
//	sum -= v[y][x];
//	vst[y][x] = false;
//}
//bool valid(int y, int x) {
//	if (y < 0 || x < 0 || y >= n || x >= m) return false;
//	return true;
//}
//void T(int y, int x) {
//	int cnt = 0;
//	sum += v[y][x];
//	if (valid(y - 1, x)) {
//		sum += v[y - 1][x];
//		cnt++;
//	}
//	if (valid(y + 1, x)) {
//		sum += v[y + 1][x];
//		cnt++;
//	}
//	if (valid(y, x - 1)) {
//		sum += v[y][x - 1];
//		cnt++;
//	}
//	if (valid(y, x + 1)) {
//		sum += v[y][x + 1];
//		cnt++;
//	}
//	if (cnt == 3) {
//		ans = max(ans, sum);
//		sum = 0;
//	}
//	else if (cnt < 3) {
//		sum = 0;
//		return;
//	}
//	else {
//		for (int i = 0; i < dir.size(); i++) {
//			sum -= v[y + dir[i].first][x + dir[i].second];
//			ans = max(sum, ans);
//			sum += v[y + dir[i].first][x + dir[i].second];
//		}
//		sum = 0;
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m;
//	v = vector<vector<int>>(n, vector<int>(m));
//	vst = vector<vector<bool>>(n, vector<bool>(m));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> v[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			dfs(i, j, 0);
//			T(i, j);
//		}
//	}
//	cout << ans;
//}