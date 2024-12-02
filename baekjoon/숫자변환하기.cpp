//#include <string>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <map>
//#include <iostream>
//using namespace std;
//int solution(int x, int y, int n) {
//    int answer = -1;
//    map<int, bool> visited;
//    queue<pair<int, int>> q;
//    q.push({ y,0 });
//    while (!q.empty()) {
//        int t = q.front().first;
//        int cost = q.front().second;
//        q.pop();
//        if (t == x) {
//            answer = cost;
//            break;
//        }
//        int next;
//        if (t % 2 == 0) {
//            next = t / 2;
//            if (next >= x && !visited[next]) {
//                visited[next] = true;
//                q.push({ next,cost + 1 });
//            }
//        }
//        if (t % 3 == 0) {
//            next = t / 3;
//            if (next >= x && !visited[next]) {
//                visited[next] = true;
//                q.push({ next,cost + 1 });
//            }
//        }
//        next = t - n;
//        if (next >= x && !visited[next]) {
//            visited[next] = true;
//            q.push({ next,cost + 1 });
//        }
//    }
//    return answer;
//}