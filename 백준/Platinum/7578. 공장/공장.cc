#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<int> seg(2000000);
long long sum(int s, int e, int n, int l, int r) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return seg[n];
	int mid = (s + e) / 2;
	return sum(s, mid, n * 2, l, r) + sum(mid + 1, e, n * 2 + 1, l, r);
}
void update(int s, int e, int n, int idx) {
	if (idx < s || e < idx) return;
	seg[n]++;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(s, mid, n * 2, idx);
	update(mid + 1, e, n * 2 + 1, idx);
}
int main() {
	FAST_IO;
	int n;
	long long ans = 0;
	cin >> n;
	unordered_map<int, int> m;
	vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		m[tmp] = i;
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v[i] = { m[tmp],i };
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		ans += sum(0, n - 1, 1, v[i].second, n - 1);
		update(0, n - 1, 1, v[i].second);
	}
	cout << ans;
}