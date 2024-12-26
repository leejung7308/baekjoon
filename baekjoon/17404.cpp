//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	vector<vector<int>> cost(n, vector<int>(3));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < 3; j++) {
//			cin >> cost[i][j];
//		}
//	}
//	int ans = INF;
//	for (int i = 0; i < 3; i++) {
//		vector<vector<int>> dp(n, vector<int>(3, INF));
//		dp[0][i] = cost[0][i];
//		for (int j = 1; j < n; j++) {
//			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
//			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
//			dp[j][2] = min(dp[j - 1][1], dp[j - 1][0]) + cost[j][2];
//		}
//		for (int j = 0; j < 3; j++) {
//			if (j == i) continue;
//			ans = min(ans, dp[n - 1][j]);
//		}
//	}
//	cout << ans;
//}