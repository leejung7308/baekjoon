//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int n, e;
//vector<int> dist;
//vector<vector<pair<int, int>>> edge;
//void dijkstra(int start) {
//	dist[start] = 0;
//	priority_queue<pair<int, int>> pq;
//	pq.push({ 0,start });
//	while (!pq.empty()) {
//		int cur = pq.top().second;
//		int ccost = -pq.top().first;
//		pq.pop();
//		for (int i = 0; i < edge[cur].size(); i++) {
//			int next = edge[cur][i].first;
//			int ncost = edge[cur][i].second + ccost;
//			if (ncost < dist[next]) {
//				dist[next] = ncost;
//				pq.push({ -ncost,next });
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> e;
//	dist = vector<int>(n + 1,INF);
//	edge = vector<vector<pair<int, int>>>(n + 1);
//	for (int i = 0; i < e; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		edge[a].push_back({ b,c });
//		edge[b].push_back({ a,c });
//	}
//	int a, b;
//	cin >> a >> b;
//	int f2a, a2b, f2b, a2n, b2n;
//	dijkstra(1);
//	f2a = dist[a];
//	f2b = dist[b];
//	dist = vector<int>(n + 1, INF);
//	dijkstra(a);
//	a2b = dist[b];
//	a2n = dist[n];
//	dist = vector<int>(n + 1, INF);
//	dijkstra(b);
//	b2n = dist[n];
//	int res;
//	if (f2a == INF || a2b == INF || b2n == INF) res = INF;
//	else res = f2a + a2b + b2n;
//	if (!(f2b == INF || a2b == INF || a2n == INF)) res = min(res, f2b + a2b + a2n);
//	if (res >= INF) cout << -1;
//	else cout << res;
//}