//#include<bits/stdc++.h>
//using namespace std;
//int count(int a) {
//	string tmp = to_string(a);
//	return tmp.size();
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	vector<bool> broken(10, false);
//	int cur = 100, n, m;
//	int under = -1, upper = -1, ans;
//	cin >> n >> m;
//	ans = abs(n - cur);
//	for (int i = 0; i < m; i++) {
//		int tmp;
//		cin >> tmp;
//		broken[tmp] = true;
//	}
//	for (int i = n; i >= 0; i--) {
//		bool found = false;
//		string tmp = to_string(i);
//		for (int j = 0; j < tmp.size(); j++) {
//			if (broken[tmp[j] - '0']) {
//				found = true;
//				break;
//			}
//		}
//		if (!found) {
//			under = i;
//			break;
//		}
//	}
//	int i = n;
//	if (!(m == 10 || (m == 9 && broken[0] == false))) {
//		while (true) {
//			bool found = false;
//			string tmp = to_string(i);
//			for (int j = 0; j < tmp.size(); j++) {
//				if (broken[tmp[j] - '0']) {
//					found = true;
//					break;
//				}
//			}
//			if (!found) {
//				upper = i;
//				break;
//			}
//			i++;
//		}
//	}
//	if (under != -1) ans = min(ans, n - under + count(under));
//	if (upper != -1) ans = min(ans, upper - n + count(upper));
//	cout << ans << '\n';
//}