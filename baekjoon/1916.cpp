//#include<bits/stdc++.h>
//using namespace std;
//int n, m, from, to;
//queue<int> q;
//vector<long long> c;
//vector<vector<pair<int, int>>> v;
//vector<bool> inQ;
//void daikstra() {
//	priority_queue<pair<int, int>> pq;
//	pq.push({ 0,from });
//	c[from] = 0;
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int cur = pq.top().second;
//		pq.pop();
//		if (c[cur] < cost) continue;
//		for (auto i : v[cur]) {
//			int ncost = cost + i.second;
//			int next = i.first;
//			if (c[next] > ncost) {
//				c[next] = ncost;
//				pq.push({ -ncost,next });
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m;
//	v.resize(n + 1);
//	inQ.resize(n + 1);
//	c = vector<long long>(n + 1, 100000000000);
//	for (int i = 0; i < m; i++) {
//		int t1, t2, t3;
//		cin >> t1 >> t2 >> t3;
//		v[t1].push_back({ t2,t3 });
// 	}
//	cin >> from >> to;
//	daikstra();
//	cout << c[to] << endl;
//}