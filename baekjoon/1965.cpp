//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n,dp[1001];
//	int a[1001];
//	int ans = 0;
//	dp[0] = 0;
//	dp[1] = 1;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		dp[i] = 1;
//		for (int j = i-1; j > 0; j--) {
//			if (a[i] > a[j]) dp[i] = max(dp[j] + 1, dp[i]);
//		}
//		ans = max(ans, dp[i]);
//	}
//	cout << ans << endl;
//}