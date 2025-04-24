#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int ans = INF;
int getans(const vector<vector<bool>>& dp, vector<vector<int>>& ans, int from, int to) {
	if (dp[from][to]) return 1;
	if (ans[from][to]) return ans[from][to];
	int ret = INF;
	for (int i = from + 1; i <= to; i++) {
		if (dp[i][to]) ret = min(ret, getans(dp, ans, from, i - 1) + 1);
	}
	return ans[from][to] = ret;
}
int main() {
	FAST_IO;
	string s;
	cin >> s;
	vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
	for (int i = 0; i < s.size(); i++) {
		dp[i][i] = true;
		if (i == s.size() - 1) continue;
		dp[i][i + 1] = s[i] == s[i + 1];
	}
	for (int length = 2; length < s.size(); length++) {
		for (int i = 0; i < s.size() - length; i++) {
			dp[i][i + length] = (dp[i + 1][i + length - 1] && s[i] == s[i + length]);
		}
	}
	vector<vector<int>> ans(s.size(), vector<int>(s.size()));
	cout << getans(dp, ans, 0, s.size() - 1);
}