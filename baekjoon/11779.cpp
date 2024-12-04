//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//vector<vector<pair<int, int>>> edges;
//vector<int> dist, path;
//int start, dest;
//void dijkstra() {
//	priority_queue<pair<int, int>> pq;
//	pq.push({ 0,start });
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int cur = pq.top().second;
//		pq.pop();
//		if (dist[cur] < cost) continue;
//		for (auto& t : edges[cur]) {
//			int ncost = -t.first + cost;
//			int next = t.second;
//			if (dist[next] > ncost) {
//				dist[next] = ncost;
//				pq.push({-ncost,next});
//				path[next] = cur;
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	edges = vector<vector<pair<int, int>>>(n + 1);
//	path = dist = vector<int>(n + 1, INF);
//	for (int i = 0; i < m; i++) {
//		int s, e, c;
//		cin >> s >> e >> c;
//		edges[s].push_back({ -c,e });
//	}
//	cin >> start >> dest;
//	dijkstra();
//	cout << dist[dest] << '\n';
//	stack<int> answer;
//	answer.push(dest);
//	for (int i = dest; i != start;) {
//		answer.push(path[i]);
//		i = path[i];
//	}
//	cout << answer.size() << '\n';
//	while (!answer.empty()) {
//		cout << answer.top() << ' ';
//		answer.pop();
//	}
//}