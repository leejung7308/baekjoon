#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n;
	cin >> n;
	int sp = 0, mp, ep = n-1;
	long long m = 1e18;
	vector<long long> v(n);
	vector<long long> ans(3);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	if (v[0] >= 0) {
		cout << v[0] << ' ' << v[1] << ' ' << v[2];
		return 0;
	}
	if (v.back() <= 0) {
		cout << v[n - 3] << ' ' << v[n - 2] << ' ' << v[n - 1];
		return 0;
	}
	for (; sp < n - 2; sp++) {
		mp = sp + 1;
		ep = n - 1;
		while (mp < ep) {
			long long  sum = v[sp] + v[mp] + v[ep];
			if (sum == 0) {
				cout << v[sp] << ' ' << v[mp] << ' ' << v[ep];
				return 0;
			}
			if (abs(sum) < m) {
				ans = { v[sp],v[mp],v[ep] };
				m = abs(sum);
			}
			if (sum < 0) mp++;
			else ep--;
		}
	}
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}