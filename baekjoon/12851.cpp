//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int n, k;
//void dijkstra() {
//	vector<int> t(100001,INF);
//	queue<pair<int, int>> q;
//	q.push({ 0,n });
//	t[n] = 0;
//	int ans = 0, answer = INF;
//	while (!q.empty()) {
//		int cur = q.front().second;
//		int cost = q.front().first;
//		q.pop();
//		if (cost > answer) continue;
//		if (cur == k) {
//			ans++;
//			answer = cost;
//		}
//		int next, ncost = cost + 1;
//		next = cur - 1;
//		if (next >= 0)
//		if (t[next] >= ncost) {
//			t[next] = ncost;
//			q.push({ ncost,next });
//		}
//
//		next = cur + 1;
//		if (next <= 100000)
//		if (t[next] >= ncost) {
//			t[next] = ncost;
//			q.push({ ncost,next });
//		}
//
//		next = cur * 2;
//		if (next <= 100000) 
//		if (t[next] >= ncost) {
//			t[next] = ncost;
//			q.push({ ncost,next });
//		}
//	}
//	cout << answer << '\n' << ans;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> k;
//	dijkstra();
//}