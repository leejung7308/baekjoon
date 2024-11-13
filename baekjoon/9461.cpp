//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n,t;
//	cin >> t;
//	vector<long long> dp(101);
//	dp[0] = 0;
//	dp[1] = 1;
//	dp[2] = 1;
//	dp[3] = 1;
//	dp[4] = 2;
//	dp[5] = 2;
//	for (int i = 6; i < 101; i++) {
//		dp[i] = dp[i - 1] + dp[i - 5];
//	}
//	for (int j = 0; j < t; j++) {
//		cin >> n;
//		cout << dp[n] << '\n';
//	}
//}