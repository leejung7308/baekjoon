//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//vector<vector<bool>> visited(100, vector<bool>(100));
//vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//int bfs(pair<int, int> s, vector<string> maps) {
//    queue<pair<int, int>> q;
//    q.push(s);
//    visited[s.first][s.second] = true;
//    int ret = 0;
//    while (!q.empty()) {
//        int curY = q.front().first;
//        int curX = q.front().second;
//        q.pop();
//        ret += maps[curY][curX] - '0';
//        for (auto d : dir) {
//            int nextY = curY + d.first;
//            int nextX = curX + d.second;
//            if (nextY < 0 || nextY >= maps.size() || nextX < 0 || nextX >= maps[0].size()) continue;
//            if (visited[nextY][nextX]) continue;
//            if (maps[nextY][nextX] == 'X') continue;
//            visited[nextY][nextX] = true;
//            q.push({ nextY,nextX });
//        }
//    }
//    return ret;
//}
//vector<int> solution(vector<string> maps) {
//    vector<int> answer;
//    for (int i = 0; i < maps.size(); i++) {
//        for (int j = 0; j < maps[0].size(); j++) {
//            if (maps[i][j] != 'X' && !visited[i][j]) answer.push_back(bfs({ i,j }, maps));
//        }
//    }
//    if (answer.size() == 0) answer.push_back(-1);
//    else sort(answer.begin(), answer.end());
//    return answer;
//}