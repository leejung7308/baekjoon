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
		long long n, ans = 0, m = -1;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = n-1; i >= 0; i--) {
			if (m < v[i]) m = v[i];
			else {
				ans += m - v[i];
			}
		}
		cout << ans << '\n';
	}
}