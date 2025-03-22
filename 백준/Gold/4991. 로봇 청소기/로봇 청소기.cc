#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
bool bfs(const vector<string>& v, vector<vector<int>>& dist, unordered_map<int,int>& p, const int& pos, int cnt) {
	DIR;
	queue<pair<int, int>> q;
	q.push({ pos,0 });
	int w = v[0].size(), h = v.size();
	vector<vector<bool>> visited(h, vector<bool>(w));
	visited[pos / w][pos % w] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cy = cur / w;
		int cx = cur % w;
		int cost = q.front().second;
		q.pop();
		for (const auto& d : dir) {
			int ny = cy + d.first;
			int nx = cx + d.second;
			int next = ny * w + nx;
			int ncost = cost + 1;
			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (visited[ny][nx]) continue;
			if (v[ny][nx] == 'x') continue;
			visited[ny][nx] = true;
			if (v[ny][nx] == '*') {
				cnt--;
				int from = p[pos], to = p[next];
				dist[from][to] = dist[to][from] = min(dist[from][to], ncost);
			}
			q.push({ next, ncost });
		}
	}
	return cnt;
}
int dfs(const vector<vector<int>>& dist, vector<bool>& visited, int cur, int cost, int cnt) {
	int ret = INF;
	if (cnt == visited.size() - 1) return cost;
	visited[cur] = true;
	for (int i = 0; i < visited.size(); i++) {
		if (visited[i]) continue;
		ret = min(ret,dfs(dist, visited, i, cost + dist[cur][i], cnt + 1));
	}
	visited[cur] = false;
	return ret;
}
int main() {
	FAST_IO;
	int w = -1, h = -1;
	int start = 0;
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		int cnt = 0;
		vector<string> v(h);
		unordered_map<int, int> pos;
		bool flag = true;
		for (int i = 0; i < h; i++) cin >> v[i];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (v[i][j] == 'o') {
					start = cnt;
					pos[i * w + j] = cnt++;
					v[i][j] = '*';
				}
				else if (v[i][j] == '*') pos[i * w + j] = cnt++;
			}
		}
		vector<bool> visited(cnt);
		vector<vector<int>> dist(cnt, vector<int>(cnt, INF));
		for (int i = 0; i < cnt; i++) dist[i][i] = 0;
		for (const auto& p : pos) {
			int cur = p.first;
			int num = p.second;
			v[cur / w][cur % w] = '.';
			cnt--;
			if (bfs(v, dist, pos, cur, cnt)) {
				flag = false;
				break;
			}
		}
		if (flag == false) {
			cout << -1 << '\n';
			continue;
		}
		cout << dfs(dist, visited, start, 0, 0) << '\n';
	}
}