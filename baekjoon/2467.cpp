//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	int l = 0, r = n-1;
//	pair<int, int> ans;
//	int min = 2000000000;
//	while (l < r) {
//		int tmp = v[l] + v[r];
//		if (min > abs(tmp)) {
//			ans = { v[l],v[r] };
//			min = abs(tmp);
//		}
//		if (tmp == 0) break;
//		if (tmp > 0) r--;
//		else l++;
//	}
//	cout << ans.first << ' ' << ans.second;
//}