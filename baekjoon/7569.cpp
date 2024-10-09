//#include<bits/stdc++.h>
//using namespace std;
//struct hnm {
//	int h;
//	int n;
//	int m;
//};
//int t[100][100][100];
//bool v[100][100][100];
//int N, M, H, ans = -1, cnt = 0;
//queue<hnm> q;
//void bfs(int h, int n, int m, int day) {
//	if (h < 0 || n < 0 || m < 0) return;
//	if (h >= H || n >= N || m >= M) return;
//	if (t[h][n][m] == -1) return;
//	if (v[h][n][m] == true) return;
//	if (t[h][n][m] != 0) return;
//	v[h][n][m] = true;
//	t[h][n][m] = day;
//	ans = max(day, ans);
//	hnm tmp = { h,n,m };
//	q.push(tmp);
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> M >> N >> H;
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < N; j++) {
//			for (int k = 0; k < M; k++) {
//				cin >> t[i][j][k];
//				if (t[i][j][k] == 1) {
//					t[i][j][k] = 10;
//					hnm tmp = { i,j,k };
//					q.push(tmp);
//				}
//				if (t[i][j][k] == 0) cnt++;
//			}
//		}
//	}
//	if (cnt == 0) {
//		cout << "0" << endl;
//		return 0;
//	}
//	while (!q.empty()) {
//		hnm tmp = q.front();
//		q.pop();
//		int h = tmp.h, n = tmp.n, m = tmp.m;
//		bfs(h + 1, n, m, t[h][n][m] + 1);
//		bfs(h - 1, n, m, t[h][n][m] + 1);
//		bfs(h, n + 1, m, t[h][n][m] + 1);
//		bfs(h, n - 1, m, t[h][n][m] + 1);
//		bfs(h, n, m + 1, t[h][n][m] + 1);
//		bfs(h, n, m - 1, t[h][n][m] + 1);
//	}
//	bool found = false;
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < N; j++) {
//			for (int k = 0; k < M; k++) {
//				if (t[i][j][k] == 0) {
//					found = true;
//					break;
//				}
//			}
//			if (found) break;
//		}
//		if (found) break;
//	}
//	if (found) cout << "-1" << endl;
//	else cout << ans - 10 << endl;
//}