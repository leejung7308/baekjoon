#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.rbegin(), v.rend());
	if (n == 1) {
		cout << v[0];
		return 0;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] < 0) break;
		if (i == n - 1) {
			ans += v[i];
			continue;
		}
		if (v[i] >= 0 && v[i + 1] < 2 && v[i + 1] >= 0){
			ans += v[i] + v[i + 1];
			i++;
			continue;
		}
		if (v[i] >= 0 && v[i + 1] < 0) {
			ans += v[i];
			continue;
		}
		ans += v[i] * v[i + 1];
		i++;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] >= 0) break;
		if (i == 0) {
			ans += v[i];
			continue;
		}
		if (v[i] < 0 && v[i - 1]>0) {
			ans += v[i];
			continue;
		}
		ans += v[i] * v[i - 1];
		i--;
	}
	cout << ans;
}