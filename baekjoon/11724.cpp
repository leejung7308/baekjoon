//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> edge(n + 1);
//	vector<bool> visited(n + 1);
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		cin >> a >> b;
//		edge[a].push_back(b);
//		edge[b].push_back(a);
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (!visited[i]) {
//			queue<int> q;
//			q.push(i);
//			visited[i];
//			while (!q.empty()) {
//				int cur = q.front();
//				q.pop();
//				for (int j = 0; j < edge[cur].size(); j++) {
//					int next = edge[cur][j];
//					if (visited[next]) continue;
//					visited[next] = true;
//					q.push(next);
//				}
//			}
//			ans++;
//		}
//	}
//	cout << ans;
//}