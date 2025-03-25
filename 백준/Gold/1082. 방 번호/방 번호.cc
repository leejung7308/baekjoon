#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
string dfs(int m, map<int,int> & p, vector<string>& dp, bool isFirst) {
	if (dp[m] != "") return dp[m];
	string ret, cur;
	for (const auto& t:p) {
		int money = t.first;
		int num = t.second;
		if (isFirst && num == 0) continue;
		if (m - money < 0) continue;
		cur = to_string(num) + dfs(m - money, p, dp, false);
		if (ret.size() < cur.size()) ret = cur;
		else if (ret.size() == cur.size()) ret = max(ret, cur);
	}
	dp[m] = ret;
	return ret;
}
int main() {
	FAST_IO;
	int n, m;
	string ans = "";
	cin >> n;
	map<int, int> p;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		p[tmp] = i;
	}
	cin >> m;
	vector<string> dp(m + 1);
	dfs(m, p, dp, true);
	if(dp[m] == "") cout << 0;
	else cout << dp[m];
}