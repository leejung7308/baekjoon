//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//vector<vector<int>> edge;
//vector<bool> vd, vb;
//int n,m,s;
//void dfs(int s) {
//	cout << s << ' ';
//	for (int i = 0; i < edge[s].size(); i++) {
//		int next = edge[s][i];
//		if (vd[next]) continue;
//		vd[next] = true;
//		dfs(next);
//	}
//}
//void bfs(int s) {
//	queue<int> q;
//	q.push(s);
//	vb[s] = true;
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		cout << cur << ' ';
//		for (int i = 0; i < edge[cur].size(); i++) {
//			int next = edge[cur][i];
//			if (vb[next]) continue;
//			vb[next] = true;
//			q.push(next);
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m >> s;
//	vd = vb = vector<bool>(n + 1);
//	edge = vector<vector<int>>(n + 1);
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		cin >> a >> b;
//		edge[a].push_back(b);
//		edge[b].push_back(a);
//	}
//	for (int i = 1; i < n+1; i++) {
//		sort(edge[i].begin(), edge[i].end());
//	}
//	vd[s] = true;
//	dfs(s);
//	cout << '\n';
//	bfs(s);
//}