//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int minimum = 987654321, sum = 0;
//vector<int> picks;
//vector<string> minerals;
//int cost(int pick, string mineral) {
//    switch (pick) {
//    case 0:
//        return 1;
//    case 1:
//        if (mineral == "diamond") return 5;
//        else return 1;
//    case 2:
//        if (mineral == "diamond") return 25;
//        else if (mineral == "iron") return 5;
//        else return 1;
//    }
//}
//void brute(int idx) {
//    if (idx == minerals.size()) {
//        minimum = min(minimum, sum);
//        return;
//    }
//    if (picks[0] == 0 && picks[1] == 0 && picks[2] == 0) {
//        minimum = min(minimum, sum);
//        return;
//    }
//    for (int i = 0; i < picks.size(); i++) {
//        if (picks[i] != 0) picks[i]--;
//        else continue;
//        int tmp = 0, end = idx + 5;
//        for (int j = idx; j < end; j++) {
//            tmp += cost(i, minerals[j]);
//            if (j == minerals.size() - 1) {
//                end = j + 1;
//                break;
//            }
//        }
//        sum += tmp;
//        brute(end);
//        sum -= tmp;
//        picks[i]++;
//    }
//}
//
//int solution(vector<int> pick, vector<string> mineral) {
//    int answer = 0;
//    picks = pick;
//    minerals = mineral;
//    brute(0);
//    answer = minimum;
//    return answer;
//}