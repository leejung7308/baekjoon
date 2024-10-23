//#include<bits/stdc++.h>
//using namespace std;
//int n, m;
//vector<vector<int>> area;
//vector<vector<int>> dist;
//vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//void dijkstra(int sy, int sx) {
//	dist[sy][sx] = 0;
//	priority_queue<pair<int,pair<int,int>>> pq;
//	pq.push({ 0,{sy,sx} });
//	while (!pq.empty()) {
//		pair<int,pair<int,int>> cur = pq.top();
//		int cy = cur.second.first, cx = cur.second.second;
//		int ccost = -cur.first;
//		pq.pop();
//		for (int i = 0; i < dir.size(); i++) {
//			int ny = cy + dir[i].first, nx = cx + dir[i].second;
//			int ncost = ccost;
//			if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
//			if (area[ny][nx] == 1) ncost++;
//			if (ncost < dist[ny][nx]) {
//				dist[ny][nx] = ncost;
//				pq.push({ -ncost,{ny,nx} });
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> m >> n;
//	area = vector<vector<int>>(n + 1, vector<int>(m + 1));
//	dist = vector<vector<int>>(n + 1, vector<int>(m + 1, 987654321));
//	for (int i = 1; i <= n; i++) {
//		string tmp;
//		cin >> tmp;
//		for (int j = 1; j <= tmp.size(); j++) {
//			area[i][j] = tmp[j-1]-'0';
//		}
//	}
//	dijkstra(1, 1);
//	cout << dist[n][m];
//}