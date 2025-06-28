#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
int v, e, cnt = 0;
vector<vector<int>> graph;
vector<int> visited;
set<int> ans;
int dfs(int cur, bool isroot) {
	visited[cur] = ++cnt;
	int ret = visited[cur];
	int child = 0;
	for (int next : graph[cur]) {
		if (visited[next] == 0) {
			child++;
			int subtree = dfs(next, false);
			if (!isroot && subtree >= visited[cur]) ans.insert(cur);
			ret = min(ret, subtree);
		}
		else ret = min(ret, visited[next]);
	}
	if (isroot && child >= 2) ans.insert(cur);
	return ret;
}
int main() {
	FAST_IO;
	cin >> v >> e;
	graph.resize(v + 1);
	visited.resize(v + 1);
	while (e--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) if (visited[i] == 0) dfs(i, true);
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
}