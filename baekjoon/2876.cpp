//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n;
//	cin >> n;
//	int a, b, ans = -1, ansId = 0;
//	int dp[6] = { 0 };
//	int prevNode[6] = { 0 };
//	for (int i = 1; i < n+1; i++) {
//		cin >> a >> b;
//		for (int j = 1; j < 6; j++) {
//			if (a == j) {
//				dp[a] = ++prevNode[a];
//				if (dp[a] > ans) {
//					ans = dp[a];
//					ansId = a;
//				}
//			}
//			else if (b == j && a != b) {
//				dp[b] = ++prevNode[b];
//				if (dp[b] > ans) {
//					ans = dp[b];
//					ansId = b;
//				}
//			}
//			else {
//				prevNode[j] = 0;
//			}
//		}
//	}
//	cout << ans << " " << ansId;
//}