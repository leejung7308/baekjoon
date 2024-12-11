//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//map<long long, long long> memo;
//long long power(long long b, long long x) {
//	if (x == 1) return b;
//	if (memo.find(x) != memo.end()) return memo[x];
//	if (x % 2 == 0) {
//		memo[x] = power(b, x / 2) % 1000000007 * power(b, x / 2) % 1000000007;
//		return memo[x];
//	}
//	else {
//		memo[x] = power(b, x / 2) % 1000000007 * power(b, x / 2 + 1) % 1000000007;
//		return memo[x];
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	long long m, n, s, ans = 0, mod=1000000007;
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> n >> s;
//		long long bi;
//		memo = map<long long, long long>();
//		bi = power(n, mod-2) % mod;
//		ans += s * bi % mod;
//		ans %= mod;
//	}
//	cout << ans;
//}