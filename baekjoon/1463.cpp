//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	vector<int> dp(n + 1,INF);
//	dp[n] = 0;
//	for (int i = n; i > 0; i--) {
//		if (i % 3 == 0) dp[i / 3] = min(dp[i / 3], dp[i] + 1);
//		if (i % 2 == 0)dp[i / 2] = min(dp[i / 2], dp[i] + 1);
//		dp[i - 1] = min(dp[i - 1], dp[i] + 1);
//	}
//	cout << dp[1];
//}