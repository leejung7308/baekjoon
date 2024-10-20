//#include <string>
//#include <vector>
//#include<iostream>
//
//using namespace std;
//vector<int> idx;
//vector<int> answer(2);
//void brute(int num, int end, vector<vector<int>> users, vector<vector<int>> saleCost) {
//    if (num == end) {
//        int buyCost = 0, sum = 0, cnt = 0;
//        for (int i = 0; i < users.size(); i++) {
//            for (int j = 0; j < idx.size(); j++) {
//                if ((idx[j] + 1) * 10 >= users[i][0]) {
//                    buyCost += saleCost[j][idx[j]];
//                }
//            }
//            if (buyCost >= users[i][1]) {
//                cnt++;
//            }
//            else {
//                sum += buyCost;
//            }
//            buyCost = 0;
//        }
//        if (answer[0] < cnt) {
//            answer[0] = cnt;
//            answer[1] = sum;
//        }
//        else if (answer[0] == cnt && answer[1] < sum) {
//            answer[1] = sum;
//        }
//        return;
//    }
//    for (int i = 0; i < 4; i++) {
//        idx[num] = i;
//        brute(num + 1, end, users, saleCost);
//    }
//}
//vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
//    vector<vector<int>> saleCost(emoticons.size());
//    vector<int> buyCost(users.size());
//    idx = vector<int>(emoticons.size());
//
//    for (int i = 0; i < emoticons.size(); i++) {
//        for (int j = 1; j < 5; j++) {
//            saleCost[i].push_back(emoticons[i] / 100 * (100 - j * 10));
//        }
//    }
//    brute(0, emoticons.size(), users, saleCost);
//    return answer;
//}