//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//pair<int,int> dfs(int x, stack<pair<int, int>>& st, vector<vector<pair<int, int>>>& edges, vector<bool>& visited){
//	st.push({ x,0 });
//	visited[x] = true;
//	int v=-1, dist=-1;
//	while (!st.empty()) {
//		int cur = st.top().first;
//		int cost = st.top().second;
//		st.pop();
//		bool flag = false;
//		for (int i = 0; i < edges[cur].size(); i++) {
//			int next = edges[cur][i].first;
//			int ncost = cost + edges[cur][i].second;
//			if (visited[next]) continue;
//			flag = true;
//			visited[next] = true;
//			st.push({ next,ncost });
//		}
//		if (flag == false) {
//			if (dist < cost) {
//				dist = cost;
//				v = cur;
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
//	vector<vector<pair<int, int>>> edges(n + 1);
//	vector<bool> visited(n+1);
//	stack<pair<int, int>> st;
//	for (int i = 0; i < n-1; i++) {
//		int p, c, d;
//		cin >> p >> c >> d;
//		edges[p].push_back({ c,d });
//		edges[c].push_back({ p,d });
//	}
//	pair<int, int> f = dfs(1, st, edges, visited);
//	visited = vector<bool>(n + 1);
//	pair<int, int> ans = dfs(f.first, st, edges, visited);
//	cout << ans.second;
//}