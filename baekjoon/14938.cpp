//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int n, m, r, ans=-1;
//vector<int> item(101);
//vector<vector<pair<int,int>>> edges(101);
//vector<bool> v(101);
//vector<int> dist(101,INF);
//void dijkstra(int x) {
//	priority_queue<pair<int, int>> q;
//	q.push({ 0,x });
//	v[x] = true;
//	int tmp=0;
//	tmp += item[x];
//	while (!q.empty()) {
//		int cur = q.top().second;
//		int cost = -q.top().first;
//		q.pop();
//		for (auto& edge : edges[cur]) {
//			int next = edge.second;
//			int ncost = edge.first + cost;
//			if (ncost > m) continue;
//			if (dist[next] > ncost) {
//				if (!v[next]) {
//					tmp += item[next];
//					v[next] = true;
//				}
//				dist[next] = ncost;
//;				q.push({ -ncost,next });
//			}
//		}
//	}
//	ans = max(ans, tmp);
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m >> r;
//	for (int i = 1; i <= n; i++) {
//		cin >> item[i];
//	}
//	for (int i = 0; i < r; i++) {
//		int a, b, l;
//		cin >> a >> b >> l;
//		edges[a].push_back({ l,b });
//		edges[b].push_back({ l,a });
//	}
//	for (int i = 1; i <= n; i++) {
//		v = vector<bool>(101);
//		dist = vector<int>(101,INF);
//		dijkstra(i);
//	}
//	cout << ans;
//}