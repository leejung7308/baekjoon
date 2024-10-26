//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
//    long long answer = 0;
//	int d = 0, p = 0, cnt = 0;
//    for (int i = n - 1; i >= 0; i--) {
//		d -= deliveries[i];
//		p -= pickups[i];
//        while (d < 0 || p < 0) {
//			d += cap;
//			p += cap;
//			cnt++;
//        }
//		answer += (i + 1) * 2 * cnt;
//		cnt = 0;
//    }
//    return answer;
//}
//int main() {
//    vector<int> deliveries = { 1,0,3,1,2 };
//    vector<int> pickups = { 0,3,0,4,0 };
//    cout << solution(4, 5, deliveries, pickups);
//}