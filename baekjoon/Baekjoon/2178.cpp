//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<queue>
//using namespace std;
//#define MAX 101
//int main() {
//	int n, m;
//	int map[MAX][MAX], dist[MAX][MAX];
//	bool visited[MAX][MAX];
//	queue<pair<int, int>> q;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		string row;
//		cin >> row;
//		for (int j = 0; j < m; j++) {
//			map[i][j] = row[j] - '0';
//			dist[i][j] = 0;
//			visited[i][j] = false;
//		}
//	}
//	int dx[4] = { -1, 1, 0, 0 };
//	int dy[4] = { 0, 0, -1, 1 };
//	visited[0][0] = true;
//	q.push(make_pair(0, 0));
//	dist[0][0]++;
//	while (!q.empty()) {
//		int x = q.front().first;
//		int y = q.front().second;
//
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if ((0 <= nx && nx < n) && (0 <= ny && ny < m) && (!visited[nx][ny]) && (map[nx][ny] == 1)) {
//				dist[nx][ny] = dist[x][y] + 1;
//				q.push(make_pair(nx, ny));
//				visited[nx][ny] = true;
//			}
//		}
//	}
//	cout << dist[n - 1][m - 1];
//}