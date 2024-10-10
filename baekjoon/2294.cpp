//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, k;
//	cin >> n >> k;
//	vector<int> v(n);
//	vector<int> dp(k + 1, 999999);
//	dp[0] = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	for (int i = 1; i <= k; i++) {
//		for (int j = 0; j < n; j++) {
//			if(v[j]<=i)
//				dp[i] = min(dp[i - v[j]] + 1, dp[i]);
//		}
//	}
//	if (dp[k] == 999999) cout << -1 << endl;
//	else cout << dp[k] << endl;
//}