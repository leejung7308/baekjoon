//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int t, n;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> t;
//	while (t--) {
//		int ans = 0;
//		cin >> n;
//		vector<int> p(n + 1) , i(n + 1);
//		while (n--) {
//			int a, b;
//			cin >> a >> b;
//			p[a] = b;
//			i[b] = a;
//		}
//		int tmp = 1;
//		ans++;
//		for (int k = 2; k < p.size(); k++) {
//			if (p[tmp] > p[k]) {
//				ans++;
//				tmp = k;
//				if (p[k] == 1) break;
//			}
//		}
//		cout << ans << '\n';
//	}
//}