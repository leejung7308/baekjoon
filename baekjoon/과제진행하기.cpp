//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <map>
//using namespace std;
//
//vector<string> answer;
//map<string, int> mp;
//priority_queue<pair<int, string>> pq;
//stack<pair<int, string>> st, lefts;
//
//void doLeft(int et, int nt) {
//    if (et == nt) return;
//    if (lefts.empty()) return;
//    pair<int, string> task = lefts.top();
//    lefts.pop();
//    int lt = nt - et;
//    if (task.first <= lt) {
//        answer.push_back(task.second);
//        et += task.first;
//        doLeft(et, nt);
//    }
//    else {
//        task = { task.first - lt,task.second };
//        lefts.push(task);
//    }
//    return;
//}
//vector<string> solution(vector<vector<string>> plans) {
//    for (int i = 0; i < plans.size(); i++) {
//        int startTime = stoi(plans[i][1].substr(0, 2)) * 60 + stoi(plans[i][1].substr(3, 2));
//        pq.push({ startTime,plans[i][0] });
//        mp[plans[i][0]] = stoi(plans[i][2]);
//    }
//    while (!pq.empty()) {
//        st.push(pq.top());
//        pq.pop();
//    }
//    pair<int, string> cur, next;
//    int et, nt;
//    while (!st.empty()) {
//        cur = st.top();
//        st.pop();
//        if (st.empty()) {
//            answer.push_back(cur.second);
//            while (!lefts.empty()) {
//                answer.push_back(lefts.top().second);
//                lefts.pop();
//            }
//            break;
//        }
//        next = st.top();
//        et = cur.first + mp[cur.second];
//        nt = next.first;
//        if (et < nt) {
//            answer.push_back(cur.second);
//            doLeft(et, nt);
//        }
//        else if (et == nt) {
//            answer.push_back(cur.second);
//        }
//        else {
//            lefts.push({ et - nt,cur.second });
//        }
//    }
//    return answer;
//}