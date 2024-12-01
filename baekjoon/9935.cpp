//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	string n, b;
//	cin >> n >> b;
//	string t;
//	for (int i = 0; i < n.size(); i++) {
//		t += n[i];
//		if (t.size() < b.size()) continue;
//		bool flag = true;
//		for (int j = 1; j <= b.size(); j++) {
//			if (t[t.size() - j] != b[b.size()-j]) flag = false;
//		}
//		if (flag) {
//			for (int j = 0; j < b.size(); j++) {
//				t.pop_back();
//			}
//		}
//	}
//	if (t.size() == 0) cout << "FRULA";
//	else cout << t;
//}