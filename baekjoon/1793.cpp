//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n;
//	string dp[251] = { "1","1","3" };
//	for (int i = 3; i < 251; i++) {
//		string tmp = "", n1 = dp[i - 2], n2 = dp[i - 2], n3 = dp[i - 1];
//		int sum = 0;
//		while (!n1.empty() || !n2.empty() || !n3.empty() || sum) {
//			if (n1 != "") {
//				sum += n1.back() - '0';
//				n1.pop_back();
//			}
//			if (n2 != "") {
//				sum += n2.back() - '0';
//				n2.pop_back();
//			}
//			if(n3 != ""){
//				sum += n3.back() - '0';
//				n3.pop_back();
//			}
//			tmp.push_back((sum % 10) + '0');
//			sum /= 10;
//		}
//		reverse(tmp.begin(), tmp.end());
//		dp[i] = tmp;
//	}
//	while (cin >> n) {
//		cout << dp[n] << endl;
//	}
//}