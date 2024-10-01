//#include<bits/stdc++.h>
//#include<map>
//using namespace std;
//long long n, p, q, x, y;
//map<long long, long long> dp;
//long long s(long long a) {
//	if (a <= 0) return 1;
//	if (dp.find(a) == dp.end()) {
//		dp[a] = s(a / p - x) + s(a / q - y);
//	}
//	return dp[a];
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> p >> q >> x >> y;
//	dp[0] = 1;
//	if (n == 0) cout << 1 << endl;
//	else cout << s(n / p - x) + s(n / q - y);
//}