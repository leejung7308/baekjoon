//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	vector<vector<int>> dp(2, vector<int>(100001));
//	vector<vector<int>> sticker(2, vector<int>(100001));
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		for (int i = 0; i < 2; i++) {
//			for (int j = 1; j <= n; j++) {
//				cin >> sticker[i][j];
//			}
//		}
//		dp[0][1] = sticker[0][1];
//		dp[1][1] = sticker[1][1];
//		for (int i = 2; i <= n; i++) {
//			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
//			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
//		}
//		cout << max(dp[0][n], dp[1][n]) << '\n';
//	}
//}