//#include<bits/stdc++.h>
//using namespace std;
//int n, m, ans = 0;
//vector<vector<int>> v;
//vector<pair<int, int>> D = { {-1,0},{0,1},{1,0},{0,-1} };
//bool isValid(int y, int x) {
//	if (x < 0 || y < 0 || x >= m || y >= n) return false;
//	if (v[y][x] == 1) return false;
//	if (v[y][x] == 2) return false;
//	if (v[y][x] == 0) return true;
//	return false;
//}
//bool isNotWall(int y, int x) {
//	if (x < 0 || y < 0 || x >= m || y >= n) return false;
//	if (v[y][x] == 1) return false;
//	if (v[y][x] == 2 || v[y][x] == 0) return true;
//	return false;
//}
//void clean(int y, int x, int d) {
//	if (v[y][x] == 0) {
//		v[y][x] = 2;
//		ans++;
//	}
//	for (int i = 0; i < 4; i++) {
//		d--;
//		d = d < 0 ? d + 4 : d;
//		if (isValid(y + D[d].first, x + D[d].second)) {
//			clean(y + D[d].first, x + D[d].second, d);
//			return;
//		}
//	}
//	switch (d) {
//	case 0:
//		if (isNotWall(y + 1, x)) clean(y + 1, x, d);
//		else return;
//		break;
//	case 1:
//		if (isNotWall(y, x - 1)) clean(y, x - 1, d);
//		else return;
//		break;
//	case 2:
//		if (isNotWall(y - 1, x)) clean(y - 1, x, d);
//		else return;
//		break;
//	case 3:
//		if (isNotWall(y, x + 1)) clean(y, x + 1, d);
//		else return;
//		break;
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int y, x, d;
//	cin >> n >> m;
//	cin >> y >> x >> d;
//	v = vector<vector<int>>(n, vector<int>(m));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> v[i][j];
//		}
//	}
//	clean(y, x, d);
//	cout << ans << endl;
//}