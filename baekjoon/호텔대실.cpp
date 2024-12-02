//#include <string>
//#include <vector>
//#include <queue>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<vector<string>> book_time) {
//    int answer = 0;
//    priority_queue<pair<int, int>> pq;
//    vector<int> endTimes;
//    for (auto& s : book_time) {
//        string start = s[0];
//        string end = s[1];
//        string h, m;
//        int stime, etime;
//        h = start.substr(0, 2);
//        m = start.substr(3);
//        stime = stoi(h) * 60 + stoi(m);
//        h = end.substr(0, 2);
//        m = end.substr(3);
//        etime = stoi(h) * 60 + stoi(m);
//        pq.push({ -stime,-etime });
//    }
//    while (!pq.empty()) {
//        int stime = -pq.top().first;
//        int etime = -pq.top().second;
//        pq.pop();
//        if (endTimes.size() == 0) {
//            endTimes.push_back(etime + 10);
//            continue;
//        }
//        bool flag = false;
//        for (int i = 0; i < endTimes.size(); i++) {
//            if (endTimes[i] <= stime) {
//                endTimes[i] = etime + 10;
//                flag = true;
//                break;
//            }
//        }
//        if (!flag) {
//            endTimes.push_back(etime + 10);
//            sort(endTimes.begin(), endTimes.end());
//        }
//    }
//    answer = endTimes.size();
//    return answer;
//}