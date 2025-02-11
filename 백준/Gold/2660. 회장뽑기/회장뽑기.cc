#include<bits/stdc++.h>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0);
using namespace std;
int n;
vector<pair<int,int>> maxnum;
vector<vector<int>> friends;
void bfs(int s) {
	queue<pair<int, int>> q;
	vector<bool> visited(n + 1);
	visited[s] = true;
	q.push({s,0});
	int maxdist = -1;
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		maxdist = max(dist, maxdist);
		q.pop();
		for (auto& next : friends[cur]) {
			if (visited[next]) continue;
			visited[next] = true;
			q.push({ next,dist + 1 });
		}
	}
	maxnum.push_back({ maxdist,s });
}
bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first < p2.first;
}
int main() {
	FAST_IO;
	cin >> n;
	friends = vector<vector<int>>(n + 1);
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) bfs(i);
	sort(maxnum.begin(), maxnum.end(), compare);
	int minnum = maxnum[0].first;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (maxnum[i].first > minnum) break;
		cnt++;
	}
	cout << minnum << ' ' << cnt << '\n';
	for (int i = 0; i < n; i++) {
		if (maxnum[i].first > minnum) break;
		cout << maxnum[i].second << ' ';
	}
}