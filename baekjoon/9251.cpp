//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	string a, b;
//	int ans = -1;
//	cin >> a >> b;
//	vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1));
//	for (int i = 1; i <= a.length(); i++) {
//		for (int j = 1; j <= b.length(); j++) {
//			if (a[i-1] == b[j-1]) {
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			}
//			else {
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//		}
//	}
//	cout << dp[a.length()][b.length()] << endl;
//}