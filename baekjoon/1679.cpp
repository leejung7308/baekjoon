//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n, k;
//	vector<int> v;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int tmp;
//		cin >> tmp;
//		v.push_back(tmp);
//	}
//	cin >> k;
//	int cnt=2;
//	vector<int> dp(50001);
//	dp[0] = 0;
//	dp[1] = 1;
//	while (true) {
//		for (int i = 0; i < (int)v.size(); i++) {
//			if (cnt >= v[i]) {
//				if (dp[cnt] == 0) {
//					dp[cnt] = min(dp[cnt - 1] + 1, dp[cnt - v[i]] + 1);
//				}
//				else {
//					dp[cnt] = min(dp[cnt], dp[cnt - v[i]] + 1);
//				}
//			}
//		}
//		if (dp[cnt] > k) break;
//		cnt++;
//	}
//	if (cnt % 2 == 0) {
//		cout << "holsoon win at " << cnt << endl;
//	}
//	else {
//		cout << "jjaksoon win at " << cnt << endl;
//	}
//}