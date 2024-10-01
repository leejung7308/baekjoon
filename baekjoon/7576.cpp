//#include<bits/stdc++.h>
//using namespace std;
//vector<vector<int>> v;
//vector<vector<int>> vst;
//queue<vector<int>> q;
//int cnt = 0, day = 0;
//int n, m;
//void seek(int x, int y, int d) {
//	if (x < 0 || y < 0 || x > n - 1 || y > m - 1) return;
//	if (vst[x][y] == 1) return;
//	if (v[x][y] == -1) return;
//	if (d == 0) v[x][y] = 1;
//	else v[x][y] = d;
//	vst[x][y] = 1;
//	day = max(day, d);
//	q.push({ x + 1,y,d + 1 });
//	q.push({ x - 1,y,d + 1 });
//	q.push({ x,y + 1,d + 1 });
//	q.push({ x,y - 1,d + 1 });
//	
//	return;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> m >> n;
//	vector<vector<int>> tmp(n, vector<int>(m));
//	v = vst = tmp;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> v[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (v[i][j] == 1) q.push({ i,j,0 });
//		}
//	}
//	while (!q.empty()) {
//		vector<int> tmp = q.front();
//		q.pop();
//		seek(tmp[0], tmp[1], tmp[2]);
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (v[i][j] == 0) {
//				cnt++;
//			}
//		}
//	}
//	if (cnt == 0) cout << day << endl;
//	else cout << "-1" << endl;
//}