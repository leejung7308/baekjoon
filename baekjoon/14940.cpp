//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//void dijkstra(vector<vector<int>>& dist, vector<vector<int>> mp, int sy, int sx) {
//	priority_queue<pair<int, pair<int, int>>> pq;
//	vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//	dist[sy][sx] = 0;
//	pq.push({ 0,{sy,sx} });
//	while (!pq.empty()) {
//		int cy = pq.top().second.first;
//		int cx = pq.top().second.second;
//		int ccost = -pq.top().first;
//		pq.pop();
//		for (auto i : dir) {
//			int ny = cy + i.first;
//			int nx = cx + i.second;
//			int ncost = ccost + 1;
//			if (ny < 0 || nx < 0 || ny >= dist.size() || nx >= dist[0].size()) continue;
//			if (mp[ny][nx] == 0) continue;
//			if (dist[ny][nx] > ncost) {
//				dist[ny][nx] = ncost;
//				pq.push({ -ncost,{ny,nx} });
//			}
//		}
//	}
//}
//void print(vector<vector<int>> dist, vector<vector<int>> mp) {
//	for (int i = 0; i < dist.size(); i++) {
//		for (int j = 0; j < dist[i].size(); j++) {
//			if (dist[i][j] == INF) {
//				if (mp[i][j] == 0) cout << "0 ";
//				else cout << "-1 ";
//			}
//			else cout << dist[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> dist(n, vector<int>(m, INF)), mp(n, vector<int>(m));
//	int sy, sx;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> mp[i][j];
//			if (mp[i][j] == 2) {
//				sy = i;
//				sx = j;
//			}
//		}
//	}
//
//	dijkstra(dist, mp, sy, sx);
//	print(dist,mp);
//}