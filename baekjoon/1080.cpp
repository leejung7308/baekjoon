//#include<bits/stdc++.h>
//using namespace std;
//int n, m, cnt = 0;
//vector<vector<int>> from;
//vector<vector<int>> to;
//void flip(int y, int x) {
//	cnt++;
//	for (int i = y - 1; i <= y + 1; i++) {
//		for (int j = x - 1; j <= x + 1; j++) {
//			if (from[i][j] == 1) from[i][j] = 0;
//			else from[i][j] = 1;
//		}
//	}
//}
//bool check() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (from[i][j] != to[i][j]) {
//				return false;
//			}
//		}
//	}
//	return true;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m;
//	vector<vector<int>> tmp(n, vector<int>(m));
//	from = to = tmp;
//	string in;
//	for (int i = 0; i < n; i++) {
//		cin >> in;
//		for (int j = 0; j < in.length(); j++) {
//			from[i][j]=in[j]-'0';
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> in;
//		for (int j = 0; j < in.length(); j++) {
//			to[i][j] = in[j]-'0';
//		}
//	}
//	if (n < 3 || m < 3) {
//		if (check()) cout << "0" << endl;
//		else cout << "-1" << endl;
//		return 0;
//	}
//	for (int i = 1; i < n - 1; i++) {
//		for (int j = 1; j < m - 1; j++) {
//			if (from[i - 1][j - 1] != to[i - 1][j - 1]) flip(i, j);
//		}
//	}
//	if (check()) cout << cnt << endl;
//	else cout << "-1" << endl;
//}