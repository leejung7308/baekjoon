//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int solution(vector<string> maps) {
//    int answer = 0;
//    pair<int, int> s, l, e;
//    for (int i = 0; i < maps.size(); i++) {
//        for (int j = 0; j < maps[i].size(); j++) {
//            if (maps[i][j] == 'S') s = { i,j };
//            else if (maps[i][j] == 'L') l = { i,j };
//            else if (maps[i][j] == 'E') e = { i,j };
//        }
//    }
//    vector<pair<int, int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
//    queue<pair<int, pair<int, int>>> q;
//    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size()));
//    visited[s.first][s.second] = true;
//    q.push({ 0,s });
//    bool flag = false;
//    while (!q.empty()) {
//        int time = q.front().first;
//        int curY = q.front().second.first;
//        int curX = q.front().second.second;
//        q.pop();
//        if (l.first == curY && l.second == curX) {
//            flag = true;
//            answer += time;
//            break;
//        }
//        for (int i = 0; i < dir.size(); i++) {
//            int nextY = curY + dir[i].first;
//            int nextX = curX + dir[i].second;
//            int nextTime = time + 1;
//            if (nextX < 0 || nextX >= maps[0].size() || nextY < 0 || nextY >= maps.size()) continue;
//            if (visited[nextY][nextX]) continue;
//            if (maps[nextY][nextX] == 'X') continue;
//            visited[nextY][nextX] = true;
//            q.push({ nextTime,{nextY,nextX} });
//        }
//    }
//    if (flag == false) {
//        return -1;
//    }
//    q = queue<pair<int, pair<int, int>>>();
//    visited = vector<vector<bool>>(maps.size(), vector<bool>(maps[0].size()));
//    visited[l.first][l.second] = true;
//    q.push({ 0,l });
//    flag = false;
//    while (!q.empty()) {
//        int time = q.front().first;
//        int curY = q.front().second.first;
//        int curX = q.front().second.second;
//        q.pop();
//        if (e.first == curY && e.second == curX) {
//            flag = true;
//            answer += time;
//            break;
//        }
//        for (int i = 0; i < dir.size(); i++) {
//            int nextY = curY + dir[i].first;
//            int nextX = curX + dir[i].second;
//            int nextTime = time + 1;
//            if (nextX < 0 || nextX >= maps[0].size() || nextY < 0 || nextY >= maps.size()) continue;
//            if (visited[nextY][nextX]) continue;
//            if (maps[nextY][nextX] == 'X') continue;
//            visited[nextY][nextX] = true;
//            q.push({ nextTime,{nextY,nextX} });
//        }
//    }
//    if (flag == false) return -1;
//    return answer;
//}