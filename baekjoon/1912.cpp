//#include<iostream>
//#include<algorithm>
//using namespace std;
//#define MAX 100001
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n, dp[MAX], ans = -1001;
//	cin >> n;
//	dp[0] = 0;
//	for (int i = 1; i <= n; i++) {
//		int tmp;
//		cin >> tmp;
//		dp[i] = max(tmp, dp[i - 1] + tmp);
//		ans = max(ans, dp[i]);
//	}
//	cout << ans << endl;
//}