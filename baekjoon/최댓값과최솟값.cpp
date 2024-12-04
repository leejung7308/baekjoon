//#include <string>
//#include <vector>
//#include <bits/stdc++.h>
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//    vector<int> v;
//    string tmp = "";
//    for (auto& c : s) {
//        if (c == ' ') {
//            if (tmp != "") {
//                v.push_back(stoi(tmp));
//                tmp = "";
//            }
//        }
//        else {
//            tmp.push_back(c);
//        }
//    }
//    v.push_back(stoi(tmp));
//    int Min = *min_element(v.begin(), v.end());
//    int Max = *max_element(v.begin(), v.end());
//    answer = to_string(Min) + " " + to_string(Max);
//    return answer;
//}