//#include<bits/stdc++.h>
//using namespace std;
//int gcd(int a, int b) {
//	int c;
//	while (b != 0) {
//		c = a % b;
//		a = b;
//		b = c;
//	}
//	return a;
//}
//int lcm(int a, int b) {
//	return a * b / gcd(a, b);
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t, m, n, x, y;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		cin >> m >> n >> x >> y;
//		int tm = 0, lc = lcm(m,n);
//		while (tm <= lc) {
//			if ((tm + x - y) % n == 0) {
//				cout << tm + x << '\n';
//				break;
//			}
//			tm += m;
//		}
//		if (tm > lc) cout << "-1\n";
//	}
//}