#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> pos(n), dist;
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}
	sort(pos.begin(), pos.end());
	for (int i = 1; i < n; i++) {
		dist.push_back(pos[i] - pos[i - 1]);
	}
	sort(dist.begin(), dist.end());
	k--;
	while (k--) {
		if (dist.empty()) continue;
		dist.pop_back();
	}
	int ans = accumulate(dist.begin(), dist.end(), 0);
	cout << ans;
}