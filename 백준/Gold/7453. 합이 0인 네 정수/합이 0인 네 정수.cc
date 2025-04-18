#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n;
	long long ans = 0;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	vector<long long> e, f;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) e.push_back(a[i] + b[j]);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) f.push_back(c[i] + d[j]);
	sort(e.begin(), e.end());
	sort(f.begin(), f.end());
	for (int i = 0; i < e.size(); i++) {
		auto it = lower_bound(f.begin(), f.end(), -e[i]);
		if (-e[i] == *it) ans += upper_bound(f.begin(), f.end(), -e[i]) - it;
	}
	cout << ans;
}