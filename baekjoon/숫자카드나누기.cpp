//#include <bits/stdc++.h>
//using namespace std;
//int gcd(int a, int b) {
//    if (b == 0) return a;
//    else return gcd(b, a % b);
//}
//int solution(vector<int> arrayA, vector<int> arrayB) {
//    int answer = 0;
//    int n = 0;
//    bool flag = false;
//    for (int i = 0; i < arrayA.size(); i++) {
//        if (arrayA[i] > n) n = gcd(arrayA[i], n);
//        else n = gcd(n, arrayA[i]);
//    }
//    for (int i = 0; i < arrayB.size(); i++) {
//        if (arrayB[i] % n == 0) flag = true;
//    }
//    if (!flag) {
//        answer = n;
//    }
//    n = 0;
//    flag = false;
//    for (int i = 0; i < arrayB.size(); i++) {
//        if (arrayB[i] > n) n = gcd(arrayB[i], n);
//        else n = gcd(n, arrayB[i]);
//    }
//    for (int i = 0; i < arrayA.size(); i++) {
//        if (arrayA[i] % n == 0) flag = true;
//    }
//    if (!flag) {
//        answer = max(answer, n);
//    }
//    return answer;
//}