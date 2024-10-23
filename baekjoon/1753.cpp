//#include<bits/stdc++.h>
//using namespace std;
//int v, e, k;
//vector<int> dist;
//vector<vector<pair<int,int>>> edge;
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
//	cin >> v >> e >> k;
//	dist = vector<int>(v + 1, 987654321);
//	edge = vector<vector<pair<int, int>>>(v + 1);
//	for (int i = 0; i < e; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		edge[a].push_back({ b,c });
//	}
//	dijkstra(k);
//	for (int i = 1; i <= v; i++) {
//		if (dist[i] == 987654321) cout << "INF\n";
//		else cout << dist[i] << '\n';
//	}
//}