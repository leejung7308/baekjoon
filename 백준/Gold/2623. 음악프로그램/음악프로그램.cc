#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n, m;
	cin >> n >> m;
	vector<int> indegree(n + 1);
	vector<bool> visited(n + 1);
	vector<vector<int>> graph(n + 1);
	string tmp;
	getline(cin, tmp);
	while (m--) {
		int k, prev = 0;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int cur;
			cin >> cur;
			if (prev != 0) {
				graph[prev].push_back(cur);
				indegree[cur]++;
			}
			prev = cur;
		}
	}
	queue<int> q;
	vector<int> ans;
	for (int i = 1; i <= n; i++) if (indegree[i] == 0) {
		q.push(i);
		visited[i] = true;
	}
	while (!q.empty()) {
		int cur = q.front();
		ans.push_back(cur);
		q.pop();
		for (int i : graph[cur]) indegree[i]--;
		for (int i = 1; i <= n; i++) if (indegree[i] == 0) {
			if (visited[i]) continue;
			visited[i] = true;
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			cout << 0;
			return 0;
		}
	}
	for (int i : ans) cout << i << '\n';
}