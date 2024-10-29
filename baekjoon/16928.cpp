//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	vector<int> dp(101, INF), ladder(101,0);
//	dp[1] = 0;
//	for (int i = 0; i < n; i++) {
//		int a, b;
//		cin >> a >> b;
//		ladder[a] = b;
//	}
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		cin >> a >> b;
//		ladder[a] = b;
//	}
//	priority_queue<pair<int, int>> q;
//	q.push({ 0,1 });
//	while (!q.empty()) {
//		int cur = q.top().second;
//		int cost = -q.top().first;
//		q.pop();
//		if (cur > 100) continue;
//		if (ladder[cur] > 0) {
//			if (dp[ladder[cur]] > cost) {
//				dp[ladder[cur]] = cost;
//				q.push({ -cost, ladder[cur]});
//			}
//			continue;
//		}
//		for (int i = 1; i <= 6; i++) {
//			int next = cur + i;
//			int ncost = cost + 1;
//			if (next > 100) break;
//			if (dp[next] > ncost) {
//				dp[next] = ncost;
//				q.push({ -ncost,next });
//			}
//		}
//	}
//	cout << dp[100];
//}