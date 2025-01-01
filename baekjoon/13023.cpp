//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//vector<vector<int>> v;
//vector<bool> visited;
//bool flag = false;
//void dfs(int a, int cnt) {
//	if (cnt == 5) {
//		flag = true;
//		return;
//	}
//	visited[a] = true;
//	for (auto& i : v[a]) {
//		if (visited[i]) continue;
//		dfs(i,cnt+1);
//		if (flag) return;
//	}
//	visited[a] = false;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	v = vector<vector<int>>(n);
//	visited = vector<bool>(n);
//	while (m--) {
//		int a, b;
//		cin >> a >> b;
//		v[a].push_back(b);
//		v[b].push_back(a);
//	}
//	for (int i = 0; i < n; i++) {
//		dfs(i, 1);
//	}
//	if (flag) cout << 1;
//	else cout << 0;
//}