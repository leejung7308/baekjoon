//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n, cnt = 1, tri = 1;
//	vector<int> dp;
//	cin >> n;
//	dp.push_back(0);
//	dp.push_back(1);
//	while (true) {
//		tri += ++cnt;
//		dp.push_back(dp[cnt - 1] + tri);
//		if (dp[cnt - 1] + tri > n) {
//			break;
//		}
//	}
//	vector<int> ans(n+1);
//	ans[0] = 0;
//	ans[1] = 1;
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; dp[j] <= i; j++) {
//			if (ans[i] == 0)
//				ans[i] = min(ans[i - dp[j]] + 1, ans[i - 1] + 1);
//			else
//				ans[i] = min(ans[i - dp[j]] + 1, ans[i]);
//		}
//	}
//	cout << ans[n];
//}