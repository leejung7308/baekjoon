//#include<bits/stdc++.h>
//#include<map>
//using namespace std;
//long long n, p, q;
//map<long long, long long> dp;
//long long s(long long a) {
//	if (a == 0) return 1;
//	if (dp.find(a) == dp.end()) {
//		dp[a] = s(a / p) + s(a / q);
//	}
//	return dp[a];
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> p >> q;
//	dp[0] = 1;
//	if (n == 0) cout << 1 << endl;
//	else cout << s(n/p)+s(n/q);
//}