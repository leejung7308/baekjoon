//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	vector<int> v(n + 1), dist(n + 1, INF);
//	for (int i = 1; i <= n; i++) {
//		cin >> v[i];
//	}
//	int a, b;
//	cin >> a >> b;
//	priority_queue<pair<int, int>> pq;
//	dist[a] = 0;
//	pq.push({0,a});
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int cur = pq.top().second;
//		pq.pop();
//		for (int i = (1 - cur) / v[cur]; i <= (n - cur) / v[cur]; i++) {
//			int next = cur + v[cur] * i;
//			int ncost = cost + 1;
//			if (dist[next] > ncost) {
//				pq.push({ -ncost,next });	
//				dist[next] = ncost;
//			}
//		}
//	}
//	if (dist[b] == INF) cout << -1;
//	else cout << dist[b];
//}