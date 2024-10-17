//#include<bits/stdc++.h>
//using namespace std;
//int n, k;
//vector<int> dp(100001, 987654321);
//queue<int> q;
//void bfs(int i) {
//	if (i < 0 || i>100000) return;
//	if (i > 0) {
//		if (dp[i - 1] > dp[i] + 1) {
//			dp[i - 1] = dp[i] + 1;
//			q.push(i - 1);
//		}
//	}
//	if (i < 100000) {
//		if (dp[i + 1] > dp[i] + 1) {
//			dp[i + 1] = dp[i] + 1;
//			q.push(i + 1);
//		}
//	}
//	if (i * 2 <= 100000) {
//		if (dp[i * 2] > dp[i]) {
//			dp[i * 2] = dp[i];
//			q.push(i * 2);
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> k;
//	dp[n] = 0;
//	q.push(n);
//	while (!q.empty()) {
//		int tmp = q.front();
//		q.pop();
//		bfs(tmp);
//	}
//	/*for (int i = 0; i <= k; i++) cout << dp[i] << ' ';
//	cout << '\n';*/
//	cout << dp[k] << '\n';
//}