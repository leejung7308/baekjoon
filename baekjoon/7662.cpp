//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t, k;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		multiset<long long> s;
//		cin >> k;
//		for (int j = 0; j < k; j++) {
//			char op;
//			int n;
//			cin >> op >> n;
//			if (op == 'I') {
//				s.insert(n);
//			}
//			else {
//				if (s.size() == 0) continue;
//				if (n == 1) {
//					s.erase(--s.end());
//				}
//				else {
//					s.erase(s.begin());
//				}
//			}
//		}
//		if (s.size() == 0) {
//			cout << "EMPTY\n";
//			continue;
//		}
//		else {
//			cout << *s.rbegin() << ' ' << *s.begin() << '\n';
//		}
//	}
//}