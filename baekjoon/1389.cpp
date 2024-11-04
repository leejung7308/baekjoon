//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> v(n + 1, vector<int>(n + 1));
//	vector<vector<int>> edge(n + 1);
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		cin >> a >> b;
//		edge[a].push_back(b);
//		edge[b].push_back(a);
//	}
//	for (int i = 1; i <= n; i++) {
//		queue<pair<int, int>> q;
//		vector<bool> visited(n + 1);
//		q.push({ i, 0 });
//		while (!q.empty()) {
//			int cur = q.front().first;
//			int cost = q.front().second;
//			q.pop();
//			if (visited[cur]) continue;
//			visited[cur] = true;
//			v[i][cur] = cost;
//			for (int j = 0; j < edge[cur].size(); j++) {
//				int next = edge[cur][j];
//				int ncost = cost + 1;
//				q.push({ next, ncost});
//			}
//		}
//	}
//	priority_queue<pair<int, int>> sum;
//	for (int i = 1; i <= n; i++) {
//		sum.push({ -accumulate(v[i].begin(),v[i].end(),0),-i });
//	}
//	cout << -sum.top().second;
//}