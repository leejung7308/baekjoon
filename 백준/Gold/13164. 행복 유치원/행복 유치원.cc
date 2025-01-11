#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> v(n),m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i == 0) continue;
		m.push_back(v[i] - v[i - 1]);
	}
	sort(m.begin(), m.end());
	int ans = 0;
	for (int i = 0; i < n - 1 - (k - 1); i++) {
		ans += m[i];
	}
	cout << ans;
}