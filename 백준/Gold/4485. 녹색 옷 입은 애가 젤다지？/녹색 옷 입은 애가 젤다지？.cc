#include<bits/stdc++.h>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0);
using namespace std;
int n;
vector<vector<int>> v, dist;
vector<pair<int, int>> dir = { {0,1},{1,0},{-1,0},{0,-1} };
void dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -v[0][0],{0,0}});
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cy = pq.top().second.first;
		int cx = pq.top().second.second;
		pq.pop();
		for (auto& d : dir) {
			int ny = cy + d.first;
			int nx = cx + d.second;
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			int ncost = cost + v[ny][nx];
			if (dist[ny][nx] > ncost) {
				dist[ny][nx] = ncost;
				pq.push({ -ncost,{ny,nx} });
			}
		}
	}
}
int main() {
	FAST_IO;
	int pidx = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;
		v = vector<vector<int>>(n, vector<int>(n));
		dist = vector<vector<int>>(n, vector<int>(n, INF));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		dijkstra();
		cout << "Problem " << pidx << ": " << dist[n - 1][n - 1] << '\n';
		pidx++;
	}
}