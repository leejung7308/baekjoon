//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	long long n, m = 2000000001;
//	cin >> n;
//	vector<long long> v;
//	pair<long long, long long> ans;
//	for (int i = 0; i < n; i++) {
//		int tmp;
//		cin >> tmp;
//		v.push_back(tmp);
//	}
//	sort(v.begin(), v.end());
//	int s = 0, e = v.size()-1;
//	while (s != e) {
//		if (abs(v[s] + v[e]) < m) {
//			m = abs(v[s] + v[e]);
//			ans = make_pair(v[s], v[e]);
//		}
//		if (v[s] + v[e] < 0) s++;
//		else if (v[s] + v[e] == 0) {
//			ans = make_pair(v[s], v[e]);
//			break;
//		}
//		else e--;
//	}
//
//	cout << ans.first << " " << ans.second << endl;
//}