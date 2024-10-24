//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//
//int n, m;
//vector<vector<int>> dist;
//vector<vector<pair<int, int>>> edge;
//
//void dijkstra() {
//	priority_queue<pair<int, int>> pq;
//	for (int i = 1; i <= n; i++) {
//		dist[i][i] = 0;
//		pq.push({ 0, i });
//		while (!pq.empty()) {
//			int cur = pq.top().second;
//			int ccost = -pq.top().first;
//			pq.pop();
//			for (int j = 0; j < edge[cur].size(); j++) {
//				int next = edge[cur][j].first;
//				int ncost = edge[cur][j].second + ccost;
//				if (ncost < dist[i][next]) {
//					dist[i][next] = ncost;
//					pq.push({ -ncost,next });
//				}
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m;
//	dist = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
//	edge = vector<vector<pair<int, int>>>(n + 1);
//	for (int i = 0; i < m; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		edge[a].push_back({ b,c });
//	}
//	dijkstra();
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (dist[i][j] != INF) cout << dist[i][j] << ' ';
//			else cout << 0 << ' ';
//		}
//		cout << '\n';
//	}
//}