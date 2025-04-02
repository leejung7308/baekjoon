#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int calpow(int x, bool iszero) {
	if (iszero) return 2;
	if (x == 0) return 1;
	if (x == 2) return 4;
	else return 3;
}
int dfs(const vector<int>& seq, vector<vector<vector<int>>>& dp, int cur, pair<int,int> pos) {
	if (cur == seq.size()) return 0;
	if (pos.first != 0 && pos.first == pos.second) return INF;
	if (dp[cur][pos.first][pos.second] != INF) return dp[cur][pos.first][pos.second];
	int next = seq[cur];
	int lp = calpow(abs(next - pos.first), pos.first == 0);
	int rp = calpow(abs(next - pos.second), pos.second == 0);
	dp[cur][pos.first][pos.second] = min(dfs(seq, dp, cur + 1, { next,pos.second }) + lp, dfs(seq, dp, cur + 1, { pos.first,next }) + rp);
	return dp[cur][pos.first][pos.second];
}
int main() {
	FAST_IO;
	vector<int> seq;
	while (true) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) break;
		seq.push_back(tmp);
	}
	vector<vector<vector<int>>> dp(seq.size(), vector<vector<int>>(5, vector<int>(5, INF)));
	cout << dfs(seq, dp, 0, { 0,0 });
}