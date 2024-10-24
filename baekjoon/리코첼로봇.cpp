//#include <string>
//#include <vector>
//#include <queue>
//#include <iostream>
//#define INF 987654321
//using namespace std;
//int ey, ex;
//vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//vector<vector<int>> dist;
//void dijkstra(int y, int x, vector<string> board) {
//    dist[y][x] = 0;
//    priority_queue<pair<int, pair<int, int>>> pq;
//    pq.push({ 0,{y,x} });
//    while (!pq.empty()) {
//        pair<int, int> cur = pq.top().second;
//        int ccost = -pq.top().first;
//        pq.pop();
//        for (int i = 0; i < dir.size(); i++) {
//            pair<int, int> tmp = cur;
//            int ncost = ccost + 1;
//            while (true) {
//                pair<int, int> next = { tmp.first + dir[i].first,tmp.second + dir[i].second };
//                if (next.first < 0 || next.second < 0 || next.first >= board.size() || next.second >= board[0].size()
//                    || board[next.first][next.second] == 'D') {
//                    if (ncost < dist[tmp.first][tmp.second]) {
//                        dist[tmp.first][tmp.second] = ncost;
//                        pq.push({ -(ncost),{tmp.first,tmp.second} });
//                    }
//                    break;
//                }
//                tmp = next;
//            }
//        }
//    }
//}
//void print() {
//    for (int i = 0; i < dist.size(); i++) {
//        for (int j = 0; j < dist[i].size(); j++) {
//            cout << dist[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//}
//int solution(vector<string> board) {
//    int answer = 0;
//    int sy, sx;
//    dist = vector<vector<int>>(board.size(), vector<int>(board[0].size(), INF));
//    for (int i = 0; i < board.size(); i++) {
//        for (int j = 0; j < board[i].size(); j++) {
//            if (board[i][j] == 'R') {
//                sy = i;
//                sx = j;
//            }
//            else if (board[i][j] == 'G') {
//                ey = i;
//                ex = j;
//            }
//        }
//    }
//    dijkstra(sy, sx, board);
//    //print();
//    if (dist[ey][ex] == INF) answer = -1;
//    else answer = dist[ey][ex];
//    return answer;
//}