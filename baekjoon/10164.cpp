//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int n, m, k;
//vector<vector<int>> v;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m >> k;
//	v = vector<vector<int>>(n, vector<int>(m));
//	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
//	int ky, kx;
//	if (k == 0) {
//		ky = 1;
//		kx = 1;
//	}
//	else {
//		k--;
//		ky = k / m + 1;
//		kx = k % m + 1;
//	}
//	dp[1][1] = 1;
//	for (int i = 1; i < n+1; i++) {
//		for (int j = 1; j < m+1; j++) {
//			if (i > ky && j < kx) continue;
//			if (i < ky && j > kx) continue;
//			dp[i][j] += dp[i - 1][j];
//			dp[i][j] += dp[i][j-1];
//		}
//	}
//	cout << dp[n][m];
//}