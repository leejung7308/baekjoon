//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	vector<int> dp(n + 1);
//	dp[1] = 1;
//	dp[2] = 2;
//	for (int i = 3; i <= n; i++) {
//		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
//	}
//	cout << dp[n];
//}