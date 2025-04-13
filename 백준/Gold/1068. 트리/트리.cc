#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	vector<int> indegree(n), parent(n);
	for (int i = 0; i < n; i++) {
		cin >> parent[i];
		if (parent[i] == -1) continue;
		v[parent[i]].push_back(i);
		indegree[parent[i]]++;
	}
	int m;
	cin >> m;
	if (parent[m] == -1) {
		cout << 0;
		return 0;
	}
	indegree[parent[m]]--;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			ans++;
		}
	}
	queue<int> q;
	q.push(m);
	while (!q.empty()) {
		int cur = q.front();
		if (indegree[cur] == 0) ans--;
		q.pop();
		for (const int& i : v[cur]) q.push(i);
	}
	cout << ans;
}