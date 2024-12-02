//#include <string>
//#include <vector>
//#include <map>
//#include <set>
//using namespace std;
//long long solution(vector<int> weights) {
//    long long answer = 0;
//    map<int, int> w;
//    for (int t : weights) {
//        answer += w[t] + w[t * 2];
//        if (t % 2 == 0) {
//            answer += w[t / 2] + w[t * 3 / 2];
//        }
//        if (t % 3 == 0) {
//            answer += w[t * 2 / 3] + w[t * 4 / 3];
//        }
//        if (t % 4 == 0) {
//            answer += w[t * 3 / 4];
//        }
//        w[t]++;
//    }
//    return answer;
//}