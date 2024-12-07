//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//pair<int, int> dfs(int x, stack<pair<int,int>>& st, vector<bool>& visited, vector<vector<pair<int,int>>> edges) {
//	st.push({ x,0 });
//	visited[x] = true;
//	int v, dist = -1;
//	while (!st.empty()) {
//		int cur = st.top().first;
//		int cost = st.top().second;
//		st.pop();
//		bool flag = false;
//		for (auto& edge : edges[cur]) {
//			int next = edge.first;
//			int ncost = cost + edge.second;
//			if (visited[next] == true) continue;
//			visited[next] = true;
//			flag = true;
//			st.push({ next,ncost });
//		}
//		if (flag == false) {
//			if (dist < cost) {
//				v = cur;
//				dist = cost;
//			}
//		}
//	}
//	return { v,dist };
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	vector<vector<pair<int, int>>> edges(n+1);
//	vector<bool> visited(n + 1);
//	stack<pair<int, int>> st;
//	for (int i = 0; i < n; i++) {
//		int s;
//		cin >> s;
//		while (true) {
//			int e, c;
//			cin >> e;
//			if (e == -1) break;
//			cin >> c;
//			edges[s].push_back({ e,c });
//			edges[e].push_back({ s,c });
//		}
//	}
//	pair<int, int> f = dfs(1, st, visited, edges);
//	visited = vector<bool>(n + 1);
//	pair<int, int> ans = dfs(f.first, st, visited, edges);
//	cout << ans.second;
//}