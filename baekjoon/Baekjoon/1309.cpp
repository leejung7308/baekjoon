//#include<bits/stdc++.h>
//using namespace std;
//#define MAX 100001
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	long long n, dp[MAX];
//	dp[0] = 0;
//	dp[1] = 3;
//	dp[2] = 7;
//	cin >> n;
//	for (int i = 3; i <= n; i++) {
//		dp[i] = (dp[i - 1] * 2 + dp[i - 2])%9901;
//	}
//	cout << dp[n] << endl;
//}