//#include<bits/stdc++.h>
//using namespace std;
//vector<vector<int>> v;
//vector<vector<int>> tmp;
//vector<pair<int, int>> pos;
//queue<pair<int, int>> q;
//int n, m, ans = 0;
//void solve();
//void bfs(int, int);
//void print() {
//	cout << '\n';
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << tmp[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
//void bruteForce(int y, int x, int num) {
//	if (num == 3) {
//		//print();
//		solve();
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		if (i < y) continue;
//		for (int j = 0; j < m; j++) {
//			if (i == y && j <= x) continue;
//			if (tmp[i][j] == 0) {
//				tmp[i][j] = 1;
//				bruteForce(i, j, num + 1);
//				tmp[i][j] = 0;
//			}
//		}
//	}
//}
//void solve() {
//	vector<vector<int>> temp = tmp;
//	for (auto i : pos) q.push(i);
//	while (!q.empty()) {
//		pair<int, int> t = q.front();
//		q.pop();
//		bfs(t.first, t.second);
//	}
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (tmp[i][j] == 0) cnt++;
//		}
//	}
//	ans = max(ans, cnt);
//	tmp = temp;
//}
//void bfs(int y, int x) {
//	if (y < 0 || x < 0 || y >= n || x >= m) return;
//	if (tmp[y][x] == 1 || tmp[y][x] == 3) return;
//	tmp[y][x] = 3;
//	q.push({ y - 1,x });
//	q.push({ y + 1,x });
//	q.push({ y,x - 1 });
//	q.push({ y,x + 1 });
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m;
//	v = tmp = vector<vector<int>>(n, vector<int>(m));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> v[i][j];
//			if (v[i][j] == 2) pos.push_back({ i,j });
//		}
//	}
//	tmp = v;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (tmp[i][j] == 0) {
//				tmp[i][j] = 1;
//				bruteForce(i, j, 1);
//				tmp[i][j] = 0;
//			}
//		}
//	}
//	cout << ans;
//}