//#include<bits/stdc++.h>
//using namespace std;
//#define MAX 10001
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n, d, dp[MAX] = { 0 };
//	vector<pair<int, int>> v[MAX];
//	cin >> n >> d;
//	for (int i = 0; i < n; i++) {
//		int s, e, l;
//		cin >> s >> e >> l;
//		if (e > d) continue;
//		if (l >= e - s) continue;
//		v[e].push_back({ s,l });
//	}
//	dp[0] = 0;
//	for (int i = 1; i <= d; i++) {
//		dp[i] = dp[i - 1] + 1;
//		for (int j = 0; j < (int)v[i].size(); j++) {
//			dp[i] = min(dp[i], dp[v[i][j].first] + v[i][j].second);
//		}
//	}
//	cout << dp[d] << endl;
//}