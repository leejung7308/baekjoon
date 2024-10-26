//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//vector<vector<int>> arr, dist, bdist;
//queue<pair<int, int>> q;
//vector<pair<int, int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
//void dijkstra(pair<int, int> start) {
//	priority_queue<pair<int, pair<pair<int,int>, bool>>> pq;
//	dist[start.first][start.second] = 1;
//	pq.push({ -1,{start,false} });
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		pair<int, int> cur = pq.top().second.first;
//		bool broken = pq.top().second.second;
//		pq.pop();
//		for (auto d : dir) {
//			int ny = cur.first + d.first;
//			int nx = cur.second + d.second;
//			int ncost = cost + 1;
//			if (nx < 0 || nx >= arr[0].size() || ny < 0 || ny >= arr.size()) continue;
//			if (broken) {
//				if (arr[ny][nx] == 0 && bdist[ny][nx] > ncost) {
//					bdist[ny][nx] = ncost;
//					pq.push({ -ncost,{{ny,nx},true} });
//				}
//			}
//			else {
//				if (arr[ny][nx] == 0 && dist[ny][nx] > ncost) {
//					dist[ny][nx] = ncost;
//					pq.push({ -ncost,{{ny,nx},false} });
//				}
//				else if (arr[ny][nx] == 1 && bdist[ny][nx] > ncost) {
//					bdist[ny][nx] = ncost;
//					pq.push({ -ncost,{{ny,nx},true} });
//				}
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	arr = vector<vector<int>>(n, vector<int>(m));
//	dist = bdist = vector<vector<int>>(n, vector<int>(m, INF));
//	dist[0][0] = 0;
//	for (int i = 0; i < n; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < m; j++) {
//			arr[i][j] = s[j] - '0';
//		}
//	}
//	dijkstra({ 0,0 });
//	int ans = min(dist[n - 1][m - 1], bdist[n - 1][m - 1]);
//	if (ans == INF) cout << -1;
//	else cout << ans;
//}