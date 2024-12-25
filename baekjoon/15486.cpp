//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	vector<int> dp(n+1);
//	int cmax = 0;
//	for (int i = 0; i < n; i++) {
//		int t, p;
//		cin >> t >> p;
//		cmax = max(cmax, dp[i]);
//		if (i + t > n) continue;
//		dp[i + t] = max(cmax + p, dp[i + t]);
//	}
//	cmax = max(cmax, dp[n]);
//	cout << cmax;
//}