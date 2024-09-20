//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	vector<pair<int, int>> dp[4][4][16];
//	vector<vector<int>> answer;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			dp[i][j][1].push_back(make_pair(i, j));
//		}
//	}
//	int n;
//	cin >> n;
//	for (int i = 2; i <= n; i++) {
//		dp[1][2][i] = dp[1][3][i - 1];
//		dp[1][2][i].push_back(make_pair(1, 2));
//		for (int j = 0; j < (int)dp[3][2][i - 1].size(); j++) {
//			dp[1][2][i].push_back(dp[3][2][i - 1][j]);
//		}
//		dp[1][3][i] = dp[1][2][i - 1];
//		dp[1][3][i].push_back(make_pair(1, 3));
//		for (int j = 0; j < (int)dp[2][3][i - 1].size(); j++) {
//			dp[1][3][i].push_back(dp[2][3][i - 1][j]);
//		}
//		dp[2][3][i] = dp[2][1][i - 1];
//		dp[2][3][i].push_back(make_pair(2, 3));
//		for (int j = 0; j < (int)dp[1][3][i - 1].size(); j++) {
//			dp[2][3][i].push_back(dp[1][3][i - 1][j]);
//		}
//		dp[3][2][i] = dp[3][1][i - 1];
//		dp[3][2][i].push_back(make_pair(3, 2));
//		for (int j = 0; j < (int)dp[1][2][i - 1].size(); j++) {
//			dp[3][2][i].push_back(dp[1][2][i - 1][j]);
//		}
//		dp[3][1][i] = dp[3][2][i - 1];
//		dp[3][1][i].push_back(make_pair(3, 1));
//		for (int j = 0; j < (int)dp[2][1][i - 1].size(); j++) {
//			dp[3][1][i].push_back(dp[2][1][i - 1][j]);
//		}
//		dp[2][1][i] = dp[2][3][i - 1];
//		dp[2][1][i].push_back(make_pair(2, 1));
//		for (int j = 0; j < (int)dp[3][1][i - 1].size(); j++) {
//			dp[2][1][i].push_back(dp[3][1][i - 1][j]);
//		}
//	}
//	for (int i = 0; i < (int)dp[1][3][n].size(); i++) {
//		vector<int> tmp;
//		tmp.push_back(dp[1][3][n][i].first);
//		tmp.push_back(dp[1][3][n][i].second);
//		answer.push_back(tmp);
//	}
//}