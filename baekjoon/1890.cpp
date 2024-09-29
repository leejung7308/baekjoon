//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n;
//	cin >> n;
//	vector<vector<int>> map(n, vector<int>(n));
//	vector<vector<long long>> dp(n, vector<long long>(n));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//		}
//	}
//	dp[0][0] = 1;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (map[i][j] == 0) continue;
//			if (dp[i][j] != 0 && i + map[i][j] < n) {
//				bool found = false;
//				for (int k = i; k < i + map[i][j]; k++) {
//					if (map[k][j] == 0) {
//						found = true;
//						break;
//					}
//				}
//				if(!found) dp[i + map[i][j]][j] += dp[i][j];
//			}
//			if (dp[i][j] != 0 && j + map[i][j] < n) {
//				bool found = false;
//				for (int k = j; k < j + map[i][j]; k++) {
//					if (map[i][k] == 0) {
//						found = true;
//						break;
//					}
//				}
//				if(!found) dp[i][j + map[i][j]] += dp[i][j];
//			}
//		}
//	}
//	cout << dp[n-1][n-1] << endl;
//}