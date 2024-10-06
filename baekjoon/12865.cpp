//#include<bits/stdc++.h>
//#include<map>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, k;
//	cin >> n >> k;
//	vector<int> dp(k+1, -1);
//	dp[0] = 0;
//	for (int i = 0; i < n; i++) {
//		int w, v;
//		cin >> w >> v;
//		for (int j = k; j >= 0; j--) {
//			if (dp[j] == -1) continue;
//			if (j + w <= k) {
//				dp[j + w] = max(dp[j + w], dp[j] + v);
//			}
//		}
//	}
//	sort(dp.rbegin(), dp.rend());
//	cout << dp[0] << endl;
//}