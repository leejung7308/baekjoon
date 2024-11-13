//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//map<long long, long long> m;
//long long fib(long long n) {
//	if (n == 0)return 0;
//	if (n == 1)return 1;
//	if (m[n] > 0) return m[n];
//	if (n % 2 == 0) {
//		long long fib1 = fib(n / 2), fib2 = fib(n / 2 - 1);
//		m[n] = (fib1 * (fib1 + 2 * fib2))%1000000007;
//		return m[n];
//	}
//	else {
//		long long fib1 = fib(n / 2), fib2 = fib(n / 2 + 1);
//		m[n] = (fib1 * fib1 + fib2 * fib2) % 1000000007;
//		return m[n];
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	long long n;
//	cin >> n;
//	cout << fib(n);
//}