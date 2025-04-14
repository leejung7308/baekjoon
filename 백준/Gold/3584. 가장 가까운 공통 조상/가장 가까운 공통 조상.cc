#include<bits/stdc++.h>
#include<unordered_map>
#define INF 2000000001
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
void bfs(const vector<vector<int>>& g, vector<int>& d, int start) {
	d[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (const int& i : g[cur]) {
			d[i] = d[cur] + 1;
			q.push(i);
		}
	}
}
void solve(const vector<vector<int>>& st, const vector<int>& d, int a, int b) {
	if (d[a] < d[b]) swap(a, b);
	int dd = d[a] - d[b];
	int k = 0;
	while (dd != 0) {
		if (dd % 2) a = st[k][a];
		k++;
		dd >>= 1;
	}
	if (a == b) {
		cout << a << '\n';
		return;
	}
	while (a != b) {
		if (st[0][a] == st[0][b]) {
			cout << st[0][a] << '\n';
			return;
		}
		for (int i = 1; i < 15; i++) {
			if (st[i][a] == st[i][b]) {
				a = st[i - 1][a];
				b = st[i - 1][b];
				break;
			}
		}
	}
}
int main() {
	FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n;
		vector<vector<int>> g(n + 1);
		vector<vector<int>> st(15, vector<int>(n + 1));
		vector<int> d(n + 1);
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			g[a].push_back(b);
			st[0][b] = a;
		}
		for (int k = 1; k < 15; k++) for (int i = 1; i <= n; i++) st[k][i] = st[k - 1][st[k - 1][i]];
		int start = 0;
		for (int i = 1; i <= n; i++) if (st[0][i] == 0) start = i;
		bfs(g, d, start);
		cin >> a >> b;
		solve(st, d, a, b);
	}
}