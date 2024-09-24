//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, m;
//	vector<vector<int>> dp;
//	cin >> n >> m;
//	for (int i = 0; i <= n; i++) {
//		vector<int> v;
//		for (int j = 0; j <= m; j++) {
//			if (i == 0 || j == 0) {
//				v.push_back(0);
//				continue;
//			}
//			int tmp;
//			cin >> tmp;
//			v.push_back(tmp + max({ dp[i - 1][j], dp[i - 1][j - 1], v[j - 1] }));
//		}
//		dp.push_back(v);
//		v.clear();
//	}
//	cout << dp[n][m] << endl;
//}