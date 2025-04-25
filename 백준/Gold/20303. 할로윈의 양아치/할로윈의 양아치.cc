#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int ans = 0;
int n, m, k;
const pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
	return { a.first + b.first,a.second + b.second };
}
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first < b.first) return true;
	else if (a.first > b.first) return false;
	else return a.second > b.second;
}
void dfs(const vector<pair<int, int>>& g, int cur, int kids, int candies) {
	if (cur == g.size() || kids + g[cur].first >= k) {
		ans = max(ans, candies);
		return;
	}
	dfs(g, cur + 1, kids, candies);
	dfs(g, cur + 1, kids + g[cur].first, candies + g[cur].second);
}
int main() {
	FAST_IO;
	cin >> n >> m >> k;
	vector<int> candy(n);
	vector<bool> visited(n);
	vector<vector<int>> friends(n + 1);
	vector<pair<int, int>> groups;
	queue<int> q;
	for (int i = 0; i < n; i++) cin >> candy[i];
	for(int i=0;i<m;i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		int kidcount = 1;
		int candycount = candy[i];
		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : friends[cur]) {
				if (visited[next]) continue;
				visited[next] = true;
				kidcount++;
				candycount += candy[next];
				q.push(next);
			}
		}
		groups.push_back({ kidcount,candycount });
	}
	vector<int> dp(k);
	for (int i = 0; i < groups.size(); i++) {
		for (int j = k - 1; j >= groups[i].first; j--) {
			dp[j] = max(dp[j], dp[j - groups[i].first] + groups[i].second);
		}
	}
	cout << dp[k-1];
}