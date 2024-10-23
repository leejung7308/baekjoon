//#include<bits/stdc++.h>
//using namespace std;
//struct item {
//	int y;
//	int x;
//	int prev;
//};
//vector<vector<int>> dp(501,vector<int>(501)), area(501,vector<int>(501));
//vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//deque<item> q;
//int n, m;
//void bfs(int y, int x, int prev) {
//	for (int i = 0; i < dir.size(); i++) {
//		int ny = y + dir[i].first, nx = x + dir[i].second;
//		if (ny < 0 || nx < 0 || ny>500 || nx>500) continue;
//		if (dp[ny][nx] == 1)continue;
//		dp[ny][nx] = 1;
//		if (area[ny][nx] == 2)continue;
//		else if (area[ny][nx] == 1)q.push_back({ ny,nx,prev + 1 });
//		else q.push_front({ ny,nx,prev });
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		for (int x = min(x1, x2); x <= max(x1, x2); x++) {
//			for (int y = min(y1, y2); y <= max(y1, y2); y++) {
//				area[y][x] = 1;
//			}
//		}
//	}
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		for (int x = min(x1, x2); x <= max(x1, x2); x++) {
//			for (int y = min(y1, y2); y <= max(y1, y2); y++) {
//				area[y][x] = 2;
//			}
//		}
//	}
//	q.push_back({ 0,0,0 });
//	while (!q.empty()) {
//		item tmp = q.front();
//		q.pop_front();
//		if (tmp.y == 500 && tmp.x == 500) {
//			cout << tmp.prev;
//			return 0;
//		}
//		bfs(tmp.y, tmp.x, tmp.prev);
//	}
//	cout << -1;
//}