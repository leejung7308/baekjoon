//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	vector<pair<int, int>> v;
//	for (int i = 0; i < n; i++) {
//		int a, b;
//		cin >> a >> b;
//		v.push_back({ b,a });
//	}
//	sort(v.begin(), v.end());
//	int t = v[0].first;
//	int ans = 1;
//	for (int i = 1; i < n; i++) {
//		if (t <= v[i].second) {
//			ans++;
//			t = v[i].first;
//		}
//	}
//	cout << ans;
//}