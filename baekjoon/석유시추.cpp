//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//vector<vector<bool>> vst;
//int solution(vector<vector<int>> land) {
//    vst = vector<vector<bool>>(land.size(), vector<bool>(land[0].size()));
//    vector<bool> check(land[0].size());
//    vector<int> col;
//    vector<int> area(land[0].size());
//    queue<pair<int, int>> q;
//    vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
//    int answer = 0;
//    for (int i = 0; i < land[0].size(); i++) {
//        for (int j = land.size() - 1; j >= 0; j--) {
//            int tmp = 0;
//            col.clear();
//            check = vector<bool>(land[0].size());
//            if (land[j][i] == 1 && !vst[j][i]) {
//                q.push({ j,i });
//            }
//            while (!q.empty()) {
//                int y = q.front().first, x = q.front().second;
//                q.pop();
//                if (y < 0 || x < 0 || y >= land.size() || x >= land[0].size()) continue;
//                if (vst[y][x]) continue;
//                if (land[y][x] == 0)continue;
//                if (!check[x]) {
//                    check[x] = true;
//                    col.push_back(x);
//                }
//                vst[y][x] = true;
//                tmp++;
//                for (int k = 0; k < dir.size(); k++) {
//                    q.push({ y + dir[k].first, x + dir[k].second });
//                }
//            }
//            for (int k = 0; k < col.size(); k++) {
//                area[col[k]] += tmp;
//            }
//        }
//    }
//    for (int i = 0; i < area.size(); i++) {
//        answer = max(area[i], answer);
//    }
//    return answer;
//}