//#include <string>
//#include <vector>
//#include <bits/stdc++.h>
//using namespace std;
//
//int solution(vector<int> topping) {
//    int answer = 0;
//
//    bool flag = false;
//    vector<int> fv(10001), bv(100001);
//    int fn = 0, bn = 0;
//    for (int i = 0; i < topping.size(); i++) {
//        if (bv[topping[i]] == 0) {
//            bn++;
//            bv[topping[i]]++;
//        }
//        else bv[topping[i]]++;
//    }
//    for (int i = 0; i < topping.size() - 1; i++) {
//        if (fv[topping[i]] == 0) {
//            fn++;
//            fv[topping[i]]++;
//        }
//        else fv[topping[i]]++;
//        bv[topping[i]]--;
//        if (bv[topping[i]] == 0) bn--;
//        if (fn == bn) answer++;
//    }
//    return answer;
//}