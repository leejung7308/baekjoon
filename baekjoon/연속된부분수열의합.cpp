//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//vector<int> solution(vector<int> sequence, int k) {
//    vector<int> answer;
//    answer.push_back(0);
//    answer.push_back(0);
//    int minimum = 1000001;
//    pair<int, int> ans;
//    int sum = 0;
//    sum += sequence[0];
//
//    while (true) {
//        if (sum == k) {
//            if (minimum > answer[1] - answer[0] + 1) {
//                minimum = answer[1] - answer[0] + 1;
//                ans = { answer[0],answer[1] };
//            }
//        }
//        if (sum < k) {
//            if (answer[1] == sequence.size() - 1) break;
//            sum += sequence[++answer[1]];
//        }
//        else {
//            if (answer[0] == sequence.size() - 1) break;
//            sum -= sequence[answer[0]++];
//        }
//    }
//    answer[0] = ans.first;
//    answer[1] = ans.second;
//    return answer;
//}