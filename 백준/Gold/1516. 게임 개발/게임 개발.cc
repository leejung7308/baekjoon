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
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<int> indegree(n + 1), times(n + 1), ans(n + 1), prev(n + 1);
	vector<bool> visited(n + 1);
	vector<vector<int>> graph(n + 1);
	for (int i = 1; i <= n; i++) {
		int tmp = 0, time;
		cin >> time;
		times[i] = time;
		while (true) {
			cin >> tmp;
			if (tmp == -1) break;
			indegree[i]++;
			graph[tmp].push_back(i);
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) if (indegree[i] == 0) {
		q.push(i);
		visited[i] = true;
	}
	while (!q.empty()) {
		int cur = q.front();
		int time = prev[cur] + times[cur];
		ans[cur] = time;
		q.pop();
		for (int next : graph[cur]) {
			indegree[next]--;
			prev[next] = max(prev[next], time);
			if (indegree[next] == 0) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}