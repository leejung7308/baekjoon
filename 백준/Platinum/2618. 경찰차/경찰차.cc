#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
int n, m;
vector<pii> w(1002);
vector<vector<int>> dp(1002, vector<int>(1002)), trace(1002, vector<int>(1002));
int md(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int dfs(int a, int b) {
	if (dp[a][b] != 0) return dp[a][b];
	int next = max(a, b) + 1;
	if (next == m + 2) return 0;
	int second = dfs(a, next) + md(w[b], w[next]), first = dfs(next, b) + md(w[a], w[next]);
	if (first < second) {
		dp[a][b] = first;
		trace[a][b] = 1;
	}
	else {
		dp[a][b] = second;
		trace[a][b] = 2;
	}
	return dp[a][b];
}
void printt(int a,int b) {
	cout << trace[a][b] << '\n';
	int next = max(a, b) + 1;
	if (next == m + 2) return;
	if (trace[a][b] == 1) printt(next, b);
	else printt(a, next);
}
int main() {
	FAST_IO;
	cin >> n >> m;
	w[0] = { 1,1 };
	w[1] = { n,n };
	for (int i = 2; i < m + 2; i++) cin >> w[i].first >> w[i].second;
	cout << dfs(0, 1) << '\n';
	printt(0, 1);
}