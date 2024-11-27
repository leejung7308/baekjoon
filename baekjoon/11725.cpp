//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//vector<vector<int>> v(100001);
//vector<bool> visited(100001);
//vector<int> ans(100001);
//void dfs(int x, int prev) {
//	if (visited[x]) return;
//	visited[x] = true;
//	ans[x] = prev;
//	for (int i = 0; i < v[x].size(); i++) {
//		dfs(v[x][i], x);
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int  n;
//	cin >> n;
//	for (int i = 0; i < n-1; i++) {
//		int a, b;
//		cin >> a >> b;
//		v[a].push_back(b);
//		v[b].push_back(a);
//	}
//	dfs(1, 0);
//	for (int i = 2; i <= n; i++) cout << ans[i] << '\n';
//}