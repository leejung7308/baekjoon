//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int blue = 0, white = 0;
//void divide(int sy, int sx, int n, vector<vector<int>> v) {
//	bool isBlue = v[sy][sx];
//	for (int i = sy; i < sy + n; i++) {
//		for (int j = sx; j < sx + n; j++) {
//			if ((isBlue && v[i][j] == 0) || (!isBlue && v[i][j] == 1)) {
//				divide(sy, sx, n / 2, v);
//				divide(sy, sx + n / 2, n / 2, v);
//				divide(sy + n / 2, sx, n / 2, v);
//				divide(sy + n / 2, sx + n / 2, n / 2, v);
//				return;
//			}
//		}
//	}
//	if (isBlue) {
//		blue++;
//	}
//	else {
//		white++;
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	vector<vector<int>> v(n, vector<int>(n));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> v[i][j];
//		}
//	}
//	divide(0, 0, n, v);
//	cout << white << '\n' << blue;
//}