//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, tmp;
//	cin >> n;
//	vector<vector<int>> ans(n, vector<int>(3));
//	cin >> ans[0][0] >> ans[0][1] >> ans[0][2];
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j < 3; j++) {
//			cin >> tmp;
//			ans[i][j] = tmp + min(ans[i - 1][j - 1 < 0 ? j + 2 : j - 1], ans[i - 1][j - 2 < 0 ? j + 1 : j - 2]);
//		}
//	}
//	cout << min({ ans[n - 1][0], ans[n - 1][1], ans[n - 1][2] }) << endl;
//}