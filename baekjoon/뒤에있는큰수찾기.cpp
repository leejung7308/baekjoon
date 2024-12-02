//#include <string>
//#include <vector>
//#include <algorithm>
//#include <stack>
//
//using namespace std;
//
//vector<int> solution(vector<int> numbers) {
//    int n = numbers.size();
//    vector<int> answer(n, -1);
//    stack<int> stack;
//    for (int i = 0; i < numbers.size(); i++) {
//        while (!stack.empty() && numbers[stack.top()] < numbers[i]) {
//            answer[stack.top()] = numbers[i];
//            stack.pop();
//        }
//        stack.push(i);
//    }
//    return answer;
//}