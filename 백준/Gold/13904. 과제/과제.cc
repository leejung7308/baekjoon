#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	priority_queue<pair<int, int>> pq;
	while (n--) {
		int a, b;
		cin >> a >> b;
		pq.push({b, a});
	}
	int ans = 0, len = 0, mn = -1;
	vector<int> d(1001);
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cur <= mn) continue;
		ans += cost;
		for (int i = cur; i < 1001; i++) {
			if (++d[i] == i) mn = max(mn, i);
		}
	}
	cout << ans;
}