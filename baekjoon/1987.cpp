//#include<bits/stdc++.h>
//using namespace std;
//struct t {
//	int y, x, cnt;
//};
//int r, c, ans=0;
//vector<vector<int>> v;
//vector<string> m;
//vector<char> vst;
//vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//void dfs(int y, int x, int cnt) {
//	if (y < 0 || x < 0 || y >= r || x >= c) return;
//	if (find(vst.begin(), vst.end(), m[y][x]) != vst.end()) return;
//	vst.push_back(m[y][x]);
//	v[y][x] = cnt;
//	ans = max(ans, cnt);
//	for (int i = 0; i < dir.size(); i++) {
//		dfs(y + dir[i].first, x + dir[i].second, cnt + 1);
//	}
//	vst.pop_back();
//}
//void print() {
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			cout << v[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> r >> c;
//	v = vector<vector<int>>(r, vector<int>(c));
//	m = vector<string>(r);
//	for (int i = 0; i < r; i++) {
//		cin >> m[i];
//	}
//	dfs(0, 0, 1);
//	//print();
//	cout << ans;
//}