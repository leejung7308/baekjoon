//#include<bits/stdc++.h>
//using namespace std;
//vector<int> v;
//int divide(int num) {
//	v.clear();
//	int k = 2;
//	while (num != 1) {
//		if (num % k == 0) {
//			num /= k;
//			v.push_back(k);
//		}
//		else {
//			k++;
//		}
//	}
//	return v.size();
//}
//bool isPrime(int num) {
//	return divide(num) == 1;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int a, b, cnt = 0;
//	cin >> a >> b;
//	for (int i = a; i <= b; i++) {
//		if (isPrime(divide(i))) cnt++;
//	}
//	cout << cnt;
//}