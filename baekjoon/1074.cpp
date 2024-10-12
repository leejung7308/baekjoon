//#include<bits/stdc++.h>
//using namespace std;
//int ans = 0, n, r, c;
//void travel(int a, bool isX) {
//	for (int i = n - 1; i >= 0; i--) {
//		if (pow(2, i) <= a) {
//			if (isX) ans += pow(4, i) * 2;
//			else ans += pow(4, i);
//			travel(a - pow(2, i), isX);
//			return;
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> r >> c;
//	travel(r, true);
//	travel(c, false);
//	cout << ans << endl;
//}