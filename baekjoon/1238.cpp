//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int n, m, x, a, b, t, ans=-1;
//vector<vector<pair<int, int>>> edges;
//vector<int> dist;
//void dijkstra() {
//	priority_queue<pair<int, int>> pq;
//	pq.push({ 0, x });
//	while (!pq.empty()) {
//		int cur = pq.top().second;
//		int cost = -pq.top().first;
//		pq.pop();
//		for (auto& edge : edges[cur]) {
//			int next = edge.second;
//			int ncost = cost + edge.first;
//			if (dist[next] > ncost) {
//				dist[next] = ncost;
//				pq.push({ -ncost,next });
//			}
//		}
//	}
//}
//void distance(int s) {
//	vector<int> tmp(n + 1, INF);
//	priority_queue<pair<int, int>> pq;
//	pq.push({ 0, s });
//	while (!pq.empty()) {
//		int cur = pq.top().second;
//		int cost = -pq.top().first;
//		pq.pop();
//		for (auto& edge : edges[cur]) {
//			int next = edge.second;
//			int ncost = cost + edge.first;
//			if (tmp[next] > ncost) {
//				tmp[next] = ncost;
//				pq.push({ -ncost,next });
//			}
//		}
//	}
//	ans = max(ans, dist[s] + tmp[x]);
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m >> x;
//	edges = vector<vector<pair<int, int>>>(n+1);
//	dist = vector<int>(n + 1, INF);
//	while (m--) {
//		cin >> a >> b >> t;
//		edges[a].push_back({ t,b });
//	}
//	dijkstra();
//	for (int i = 1; i <= n; i++) {
//		if (i == x) continue;
//		distance(i);
//	}
//	cout << ans;
//}