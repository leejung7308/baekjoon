//#include<bits/stdc++.h>
//using namespace std;
//#define MAX 1001
//int main() {
//	int dp[MAX][MAX]={0}, n, k;
//	cin >> n >> k;
//	dp[0][0] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= n; j++) {
//			if (j == 0 || j == n) dp[i][j] = 1;
//			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
//		}
//	}
//	cout << dp[n][k];
//}