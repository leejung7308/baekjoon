//#include<bits/stdc++.h>
//using namespace std;
//vector<vector<int>> arr;
//pair<int, int> shark;
//int sharkSize = 2;
//vector<pair<int, int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
//vector<vector<bool>> visited;
//priority_queue<pair<int, pair<int, int>>> pq;
//void bfs() {
//	visited = vector<vector<bool>>(arr.size(), vector<bool>(arr[0].size()));
//	queue<pair<pair<int, int>,int>> q;
//	q.push({shark,0});
//	while (!q.empty()) {
//		int y = q.front().first.first;
//		int x = q.front().first.second;
//		int dist = q.front().second;
//		q.pop();
//		for (auto d : dir) {
//			int ny = y + d.first;
//			int nx = x + d.second;
//			if (nx < 0 || nx >= arr[0].size() || ny < 0 || ny >= arr.size() || arr[ny][nx] > sharkSize) continue;
//			if (visited[ny][nx]) continue;
//			visited[ny][nx] = true;
//			if (arr[ny][nx] == 0 || arr[ny][nx]==sharkSize) {
//				q.push({ { ny,nx },dist + 1 });
//			}
//			else if (arr[ny][nx] < sharkSize) {
//				pq.push({ -dist - 1,{-ny,-nx} });
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, cnt=0, ans=0;
//	cin >> n;
//	arr = vector<vector<int>>(n, vector<int>(n));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> arr[i][j];
//			if (arr[i][j] == 9) shark = { i,j }, arr[i][j]=0;
//		}
//	}
//	bfs();
//	while (!pq.empty()) {
//		shark = { -pq.top().second.first,-pq.top().second.second };
//		ans -= pq.top().first;
//		pq.pop();
//		arr[shark.first][shark.second] = 0;
//		if (++cnt == sharkSize) {
//			sharkSize++;
//			cnt = 0;
//		}
//		pq = priority_queue<pair<int, pair<int, int>>>();
//		bfs();
//	}
//	cout << ans;
//}