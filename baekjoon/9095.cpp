//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n;
//	cin >> n;
//	vector<int> dp(12, 0);
//	dp[1] = 1;
//	dp[2] = 2;
//	dp[3] = 4;
//
//	for (int i = 4; i < 11; i++) {
//		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//	}
//	for (int i = 0; i < n; i++) {
//		int tmp;
//		cin >> tmp;
//		cout << dp[tmp] << endl;
//	}
//}