#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<vector<int>> g;
vector<int> p;
vector<bool> s;
int ans = INF;
bool checkconnection(const bool state, const int start, const int size) {
	queue<int> q;
	vector<bool> visited(g.size());
	int cnt = 1;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (const int& next : g[cur]) {
			if (visited[next] || s[next] != state) continue;
			cnt++;
			visited[next] = true;
			q.push(next);
		}
	}
	if (size == cnt) return true;
	else return false;
}
bool check() {
	vector<int> a, b;
	for (int i = 1; i < g.size(); i++) {
		if (s[i]) a.push_back(i);
		else b.push_back(i);
	}
	if (a.size() == 0 || b.size() == 0) return false;
	if (checkconnection(true, a[0], a.size()) == false) return false;
	if (checkconnection(false, b[0], b.size()) == false) return false;
	return true;
}
void cal() {
	int a = 0, b = 0;
	for (int i = 1; i < g.size(); i++) {
		if (s[i]) a += p[i];
		else b += p[i];
	}
	ans = min(ans, abs(a - b));
}
void dfs(int cur, int cnt) {
	if (cnt > 0 && check()) {
		cal();
	}
	for (int i = cur; i < g.size(); i++) {
		if (s[i]) continue;
		s[i] = true;
		dfs(i, cnt + 1);
		s[i] = false;
	}
}
int main() {
	FAST_IO;
	int n, sum = 0;
	cin >> n;
	g = vector<vector<int>>(n + 1);
	p = vector<int>(n + 1);
	s = vector<bool>(n + 1);
	for (int i = 1; i <= n; i++) cin >> p[i], sum += p[i];
	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int tmp;
			cin >> tmp;
			g[i].push_back(tmp);
		}
	}
	dfs(1,0);
	if (ans == INF) cout << -1;
	else cout << ans;
}