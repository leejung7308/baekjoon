//#include<bits/stdc++.h>
//using namespace std;
//#define MAX 502
//int main() {
//	int n, dp[MAX-1][MAX];
//	int cnt = 2, ans = -1, tmp;
//	dp[0][0] = 0;
//	cin >> n >> tmp;
//	dp[1][1] = tmp;
//	dp[1][0] = dp[1][2] = -1;
//	for(int i=2; i<= n; i++){
//		for (int j = 0; j <= cnt+1; j++) {
//			if (j == 0 || j == cnt + 1) {
//				dp[i][j] = -1;
//				continue;
//			}
//			cin >> tmp;
//			dp[i][j] = tmp + max(dp[i - 1][j - 1], dp[i - 1][j]);
//			if (i == n) {
//				ans = max(ans, dp[i][j]);
//			}
//		}
//		cnt++;
//	}
//	if (n == 1) cout << dp[1][1];
//	else cout << ans << endl;
//}