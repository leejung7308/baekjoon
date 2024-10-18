//#include<bits/stdc++.h>
//using namespace std;
//int n, k;
//vector<int> dp;
//vector<int> v;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> k;
//	dp = vector<int>(k + 1, 0);
//	v = vector<int>(n);
//	dp[0] = 1;
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//	for (int i = 0; i < v.size(); i++) {
//		for (int j = 1; j <= k; j++) {
//			if (j - v[i] < 0) continue;
//			dp[j] += dp[j - v[i]];
//		}
//	}
//	cout << dp[k];
//}