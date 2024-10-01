//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//    cout.tie(0);
//	long long n, m, k, cnt = 1;
//	cin >> n >> m >> k;
//	vector<vector<long long>> b;
//	vector<vector<long long>> dp(m+1, vector<long long>(n+1));
//	for (int i = 0; i < k; i++) {
//		long long x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		b.push_back({ x1, y1, x2, y2 });
//	}
//	dp[0][0] = 1;
//	for (int i = 0; i <= m; i++) {
//		for (int j = 0; j <= n; j++) {
//			bool found1 = false;
//			bool found2 = false;
//			for (auto v : b) {
//				if ((v[0] == j - 1 && v[1] == i && v[2] == j && v[3] == i) || (v[0] == j && v[1] == i && v[2] == j - 1 && v[3] == i)) {
//					found1 = true;
//				}
//				if ((v[0] == j && v[1] == i - 1 && v[2] == j && v[3] == i) || (v[0] == j && v[1] == i && v[2] == j && v[3] == i - 1)) {
//					found2 = true;
//				}
//			}
//			if (i != 0 && !found2) dp[i][j] += dp[i - 1][j];
//			if (j != 0 && !found1) dp[i][j] += dp[i][j - 1];
//		}
//	}
//	cout << dp[m][n];
//}