//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int solution(vector<int> diffs, vector<int> times, long long limit) {
//    int answer = 0;
//    long long used = 0;
//    int MIN = 0, MAX = 100000;
//    while (true) {
//        answer = (MIN + MAX) / 2;
//        if (answer == MIN) break;
//        used += times[0];
//        for (int i = 1; i < diffs.size(); i++) {
//            if (diffs[i] > answer) used += (times[i - 1] + times[i]) * (diffs[i] - answer) + times[i];
//            else used += times[i];
//            if (used > limit) {
//                MIN = answer;
//                break;
//            }
//        }
//        if (used <= limit) {
//            MAX = answer;
//        }
//        used = 0;
//    }
//    answer = MAX;
//    return answer;
//}