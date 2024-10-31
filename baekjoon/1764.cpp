//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	map<string, int> mp;
//	for (int i = 0; i < n+m; i++) {
//		string tmp;
//		cin >> tmp;
//		mp[tmp]++;
//	}
//	vector<string> ans;
//	int cnt = 0;
//	for (auto i : mp) {
//		if (i.second == 2) {
//			ans.push_back(i.first);
//			cnt++;
//		}
//	}
//	cout << cnt << '\n';
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << '\n';
//	}
//}