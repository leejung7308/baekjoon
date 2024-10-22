//#include <string>
//#include <vector>
//#include <cmath>
//#include <iostream>
//using namespace std;
//
//long long solution(int r1, int r2) {
//    long long answer = 0;
//    for (int i = -r2; i <= r2; i++) {
//        double yb = floor(sqrt(pow(r2, 2) - pow(i, 2)));
//        double ys = ceil(sqrt(pow(r1, 2) - pow(i, 2)));
//        int cnt = 0;
//        if (abs(i) <= r1) cnt = yb - ys + 1;
//        else {
//            ys = 0;
//            cnt = yb + 1;
//        }
//        if (yb == 0 || ys == 0) cnt += cnt - 1;
//        else cnt *= 2;
//        answer += cnt;
//    }
//    return answer;
//}