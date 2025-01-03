//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int t, n, ans = 0;
//vector<int> v;
//vector<bool> vis;
//vector<bool> done;
//void dfs(int x) {
//	vis[x] = true;
//	int next = v[x];
//	if (!vis[next]) dfs(next);
//	else if (!done[next]) {
//		for (int i = next; i != x; i = v[i]) {
//			ans++;
//		}
//		ans++;
//	}
//	done[x] = true;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> t;
//	while (t--) {
//		ans = 0;
//		cin >> n;
//		v = vector<int>(n + 1);
//		vis = vector<bool>(n + 1);
//		done = vector<bool>(n + 1);
//		for (int i = 1; i <= n; i++) {
//			cin >> v[i];
//		}
//		for (int i = 1; i <= n; i++) {
//			if(!vis[i]) dfs(i);
//		}
//		cout << n - ans << '\n';
//	}
//}