#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
DIR;
vector<string> v(1500);
vector<vector<bool>> visited(1500, vector<bool>(1500));
vector<vector<int>> graph(1500, vector<int>(1500));
int r, c;
pair<int, int> swan;
void melt() {
	queue<pair<int,pair<int, int>>> q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (v[i][j] == 'X') {
				for (const auto& d : dir) {
					int y = i + d.first, x = j + d.second;
					if (y < 0 || y >= r || x < 0 || x >= c)continue;
					if (v[y][x] == '.' || v[y][x] == 'L') {
						q.push({ 1,{ i,j } });
						visited[i][j] = true;
					}
				}
			}
		}
	}
	while (!q.empty()) {
		int cy = q.front().second.first, cx = q.front().second.second, date = q.front().first;
		q.pop();
		graph[cy][cx] = date;
		for (const auto& d : dir) {
			int ny = cy + d.first, nx = cx + d.second;
			if (ny < 0 || ny >= r || nx < 0 || nx >= c)continue;
			if (visited[ny][nx]) continue;
			if (v[ny][nx] == 'X') {
				visited[ny][nx] = true;
				q.push({ date + 1,{ny,nx} });
			}
		}
	}
}
int tryswan() {
	visited = vector<vector<bool>>(r, vector<bool>(c));
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,swan });
	visited[swan.first][swan.second] = true;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cy = pq.top().second.first, cx = pq.top().second.second;
		pq.pop();
		for (const auto& d : dir) {
			int ny = cy + d.first, nx = cx + d.second;
			if (ny < 0 || ny >= r || nx < 0 || nx >= c)continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			pq.push({ -max(cost,graph[ny][nx]),{ny,nx} });
			if (v[ny][nx] == 'L') return cost;
		}
	}
	return INF;
}
void printv() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) cout << graph[i][j] << ' ';
		cout << '\n';
	}
}
int main() {
	FAST_IO;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> v[i];
		for (int j = 0; j < c; j++) if (v[i][j] == 'L') swan = { i,j };
	}
	melt();
	cout << tryswan();
}