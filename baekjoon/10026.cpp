//#include<bits/stdc++.h>
//using namespace std;
//int n;
//vector<vector<char>> v;
//vector<vector<bool>> vst;
//vector<vector<bool>> vstB;
//vector<pair<int, int>> chk = { {0,1},{1,0},{-1,0},{0,-1} };
//int cnt1 = 0, cnt2 = 0;
//void seek(int x, int y, bool isStart, char prev) {
//	if (x < 0 || y < 0) return;
//	if (x >= n || y >= n) return;
//	if (v[x][y] != prev) return;
//	if (vst[x][y] == true) return;
//	vst[x][y] = true;
//	if (isStart == true) cnt1++;
//	seek(x + 1, y, false, v[x][y]);
//	seek(x, y + 1, false, v[x][y]);
//	seek(x - 1, y, false, v[x][y]);
//	seek(x, y - 1, false, v[x][y]);
//}
//void seekBlind(int x, int y, bool isStart, char prev) {
//	if (x < 0 || y < 0) return;
//	if (x >= n || y >= n) return;
//	if (!((v[x][y] == 'R' && prev == 'G') || (v[x][y] == 'G' && prev == 'R') || v[x][y] == prev)) return;
//	if (vstB[x][y] == true) return;
//	vstB[x][y] = true;
//	if (isStart == true) {
//		cnt2++;
//	}
//	seekBlind(x + 1, y, false, v[x][y]);
//	seekBlind(x, y + 1, false, v[x][y]);
//	seekBlind(x - 1, y, false, v[x][y]);
//	seekBlind(x, y - 1, false, v[x][y]);
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n;
//	vector<vector<char>> a(n, vector<char>(n));
//	vector<vector<bool>> b(n, vector<bool>(n, false));
//	v = a;
//	vst = vstB = b;
//	for (int i = 0; i < n; i++) {
//		string tmp;
//		cin >> tmp;
//		for (int j = 0; j < tmp.length(); j++) {
//			v[i][j] = tmp[j];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			seek(i, j, true, v[i][j]);
//			seekBlind(i, j, true, v[i][j]);
//		}
//	}
//	cout << cnt1 << " " << cnt2 << endl;
//}