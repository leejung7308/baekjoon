//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> dp(n + 1, vector<int>(n+1));
//	vector<int> tmp(n + 1);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			int t;
//			cin >> t;
//			tmp[j] = tmp[j - 1] + t;
//			dp[i][j] = tmp[j] + dp[i-1][j];
//		}
//	}
//	for (int i = 0; i < m; i++) {
//		int a, b, c, d;
//		cin >> a >> b >> c >> d;
//		cout << dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1] << '\n';
//	}
//}