//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int storey) {
//    int answer = 0;
//    while (storey != 0) {
//        int cur = storey % 10;
//        int next = storey % 100;
//        if (cur >= 6) {
//            answer += 10 - cur;
//            storey /= 10;
//            storey += 1;
//        }
//        else if (cur == 5) {
//            if (next > 50) {
//                answer += 10 - cur;
//                storey /= 10;
//                storey += 1;
//            }
//            else {
//                answer += cur;
//                storey /= 10;
//            }
//        }
//        else {
//            answer += cur;
//            storey /= 10;
//        }
//
//    }
//    return answer;
//}