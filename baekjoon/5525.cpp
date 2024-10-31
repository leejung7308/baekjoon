//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	string s, io;
//	cin >> n >> m >> s;
//	if (m < 2 * n + 1) {
//		cout << 0;
//		return 0;
//	}
//	int ans = 0;
//	for (int i = 0; i < m; i++) {
//		if (s[i] == 'O') continue;
//		int k = 0;
//		while (s[i + 1] == 'O' && s[i + 2] == 'I') {
//			k++;
//			if (k >= n) {
//				ans++;
//			}
//			i += 2;
//			if (i > s.size() - 3) break;
//		}
//	}
//	cout << ans;
//}