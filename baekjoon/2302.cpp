//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m, ans = 1;
//	cin >> n >> m;
//	vector<int> dp(45);
//	vector<int> vip;
//	while (m--) {
//		int tmp;
//		cin >> tmp;
//		vip.push_back(tmp);
//	}
//	dp[0] = 1;
//	dp[1] = 1;
//	for (int i = 2; i <= n; i++) {
//		dp[i] = dp[i - 1] + dp[i - 2];
//	}
//	int s = 0;
//	for (auto& i : vip) {
//		int e = i;
//		ans *= dp[e - s - 1];
//		s = e;
//	}
//	ans *= dp[n - s];
//	cout << ans;
//}