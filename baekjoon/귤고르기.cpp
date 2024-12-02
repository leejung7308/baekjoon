//#include <string>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <iostream>
//using namespace std;
//
//int solution(int k, vector<int> tangerine) {
//    int answer = 0;
//    sort(tangerine.begin(), tangerine.end());
//    int prev = -1;
//    int cnt = 0;
//    vector<int> v;
//    for (int i = 0; i < tangerine.size(); i++) {
//        if (prev != tangerine[i]) {
//            v.push_back(cnt);
//            prev = tangerine[i];
//            cnt = 1;
//        }
//        else cnt++;
//        if (i == tangerine.size() - 1) {
//            v.push_back(cnt);
//        }
//    }
//    sort(v.rbegin(), v.rend());
//    for (int i = 0; i < v.size(); i++) {
//        k -= v[i];
//        answer++;
//        if (k <= 0) break;
//    }
//    return answer;
//}