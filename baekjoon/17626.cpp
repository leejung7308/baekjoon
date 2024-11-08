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
//	dp[0] = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j * j <= i; j++) {
//			dp[i] = min(dp[i], dp[i - j * j] + 1);
//		}
//	}
//	cout << dp[n];
//}