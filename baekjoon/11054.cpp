//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, ans = 1;
//	cin >> n;
//	vector<int> v(n);
//	vector<vector<int>> dp(n, vector<int>(2, 1));
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//		for (int j = 0; j < i; j++) {
//			if (v[i] > v[j]) {
//				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
//				ans = max(dp[i][0], ans);
//			}
//			if (v[i] < v[j]) {
//				dp[i][1] = max({ dp[i][1],dp[j][0] + 1,dp[j][1] + 1 });
//				ans = max(ans, dp[i][1]);
//			}
//		}
//	}
//	if (n == 1) {
//		cout << 1;
//		return 0;
//	}
//	cout << ans;
//}