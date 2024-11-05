//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, s=0, e=1;
//	cin >> n;
//	vector<int> v(n+1);
//	vector<int> se;
//	for (int i = 1; i <= n; i++) {
//		cin >> v[i];
//	}
//	se.push_back(v[1]);
//	int cnt = 1, ans = 0;
//	while (true) {
//		if (e == v.size() - 1) {
//			ans = max(ans, cnt);
//			break;
//		}
//		if (se.size() == 1 && v[e + 1] != se[0]) {
//			e++;
//			cnt++;
//			se.push_back(v[e]);
//			continue;
//		}
//		if (se.size() == 1 && v[e + 1] == se[0]) {
//			e++;
//			cnt++;
//			continue;
//		}
//		if (se.size() == 2 && (v[e + 1] == se[0] || v[e + 1] == se[1])) {
//			e++;
//			cnt++;
//			continue;
//		}
//		if (se.size() == 2 && !(v[e + 1] == se[0] || v[e + 1] == se[1])) {
//			ans = max(ans, cnt);
//			cnt = 2;
//			s = e;
//			e++;
//			se.clear();
//			se.push_back(v[s]);
//			se.push_back(v[e]);
//			while (true) {
//				if (v[s - 1] == v[s]) {
//					cnt++;
//					s--;
//				}
//				else break;
//			}
//			continue;
//		}
//	}
//	cout << ans;
//}