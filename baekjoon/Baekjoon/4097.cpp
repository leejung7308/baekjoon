//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n = -1;
//	while (true) {
//		cin >> n;
//		if (n == 0) break;
//		vector<int> dp(n + 1, 0);
//		int ans = -10001;
//		for (int i = 1; i <= n; i++) {
//			int tmp;
//			cin >> tmp;
//			dp[i] = max(dp[i - 1] + tmp, tmp);
//			ans = max(dp[i], ans);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}