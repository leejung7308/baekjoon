//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n;
//	long long ans = 0;
//	cin >> n;
//	vector<int> v(n+1);
//	vector<int> dp(n + 1);
//	dp[0] = 0;
//	v[0] = 0;
//	for (int i = 1; i < n+1; i++) {
//		cin >> v[i];
//	}
//	dp[1] = v[1];
//	dp[2] = v[1] + v[2];
//	for (int i = 3; i < n + 1; i++) {
//		dp[i] = max({ dp[i - 3] + v[i - 1] + v[i],dp[i - 2] + v[i],dp[i - 1] });
//	}
//	cout << dp[n] << endl;
//}