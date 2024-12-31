//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//pair<int, int> s, e;
//vector<pair<int, int>> dir = { {1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1} };
//void bfs(int l) {
//	vector<vector<bool>> v(l, vector<bool>(l,false));
//	queue<pair<int, pair<int, int>>> q;
//	q.push({ 0,s });
//	v[s.first][s.second] = true;
//	while (!q.empty()) {
//		int cy = q.front().second.first;
//		int cx = q.front().second.second;
//		int cost = q.front().first;
//		q.pop();
//		if (e == make_pair(cy, cx)) {
//			cout << cost << '\n';
//			return;
//		}
//		for (auto& d : dir) {
//			int ny = cy + d.first;
//			int nx = cx + d.second;
//			int ncost = cost + 1;
//			if (ny < 0 || ny >= l || nx < 0 || nx >= l) continue;
//			if (v[ny][nx]) continue;
//			v[ny][nx] = true;
//			q.push({ ncost,{ny,nx} });
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t, l;
//	cin >> t;
//	while (t--) {
//		cin >> l;
//		int a, b;
//		cin >> a >> b;
//		s = { a,b };
//		cin >> a >> b;
//		e = { a,b };
//		bfs(l);
//	}
//}