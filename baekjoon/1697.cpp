//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, k;
//	cin >> n >> k;
//	vector<int> dp(100001,INF);
//	dp[n] = 0;
//	for (int i = n - 1; i >= 0; i--) {
//		dp[i] = min(dp[i], dp[i + 1] + 1);
//	}
//	for (int i = 1; i < 100000; i++) {
//		if (i % 2 == 0) dp[i] = min({ dp[i],dp[i - 1] + 1,dp[i + 1] + 1,dp[i / 2] + 1 });
//		else dp[i] = min({ dp[i],dp[i - 1] + 1,dp[i + 1] + 1 });
//		if (i <= 50000) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
//	}
//	dp[100000] = min({ dp[100000],dp[50000] + 1,dp[99999] + 1 });
//	cout << dp[k];
//}