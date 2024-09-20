//#include<iostream>
//#include<algorithm>
//using namespace std;
//#pragma warning(disable:6385)
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int dp[6][6][3];
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			int tmp;
//			cin >> tmp;
//			if (i == 0) {
//				dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = tmp;
//				if (j == 0) dp[i][j][0] = 99999;
//				if (j == m - 1) dp[i][j][2] = 99999;
//			}
//			else {
//				if (j != 0)
//					dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + tmp;
//
//				dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + tmp;
//
//				if (j != m - 1)
//					dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + tmp;
//
//
//				if (j == 0) dp[i][j][0] = 99999;
//				if (j == m - 1) dp[i][j][2] = 99999;
//			}
//		}
//	}
//	int ans = 99999;
//	for (int j = 0; j < m; j++) {
//		for (int k = 0; k < 3; k++) {
//			ans = min(ans, dp[n - 1][j][k]);
//		}
//	}
//	cout << ans;
//}