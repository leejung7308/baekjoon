#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		deque<int> dq;
		int i = 0;
		while (i < n) {
			dq.push_front(v[i++]);
			if (i == n) break;
			dq.push_back(v[i++]);
		}
		int first = dq.front();
		int last = dq.back();
		int ans = abs(first - last);
		int prev = first;
		dq.pop_front();
		while (!dq.empty()) {
			int cur = dq.front();
			dq.pop_front();
			ans = max(ans, abs(cur - prev));
			prev = cur;
		}
		cout << ans << '\n';
	}
}