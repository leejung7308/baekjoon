//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m, sy, sx;
//	cin >> n >> m;
//	vector<string> mp;
//	vector<vector<bool>> visited(n, vector<bool>(m));
//	for (int i = 0; i < n; i++) {
//		string tmp;
//		cin >> tmp;
//		for (int j = 0; j < tmp.size(); j++) {
//			if (tmp[j] == 'I') {
//				sy = i;
//				sx = j;
//				break;
//			}
//		}
//		mp.push_back(tmp);
//	}
//	vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//	queue<pair<int, int>> q;
//	q.push({ sy,sx });
//	visited[sy][sx] = true;
//	int ans = 0;
//	while (!q.empty()) {
//		int cy = q.front().first;
//		int cx = q.front().second;
//		q.pop();
//		for (int i = 0; i < dir.size(); i++) {
//			int ny = cy + dir[i].first;
//			int nx = cx + dir[i].second;
//			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
//			if (visited[ny][nx]) continue;
//			if (mp[ny][nx] == 'X') continue;
//			visited[ny][nx] = true;
//			if (mp[ny][nx] == 'P') ans++;
//			q.push({ ny,nx });
//		}
//	}
//	if (ans == 0) {
//		cout << "TT";
//		return 0;
//	}
//	cout << ans;
//}