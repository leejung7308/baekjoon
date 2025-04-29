#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<long long> seg;
void update(int n, int s, int e, int idx, long long diff) {
	if (idx < s || e < idx) return;
	seg[n] += diff;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(n * 2, s, mid, idx, diff);
	update(n * 2 + 1, mid + 1, e, idx, diff);
}
long long sum(int n, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int mid = (s + e) / 2;
	return sum(n * 2, s, mid, l, r) + sum(n * 2 + 1, mid + 1, e, l, r);
}
int main() {
	FAST_IO;
	int n, m, k;
	cin >> n >> m >> k;
	seg = vector<long long>(n * 4);
	vector<long long> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		update(1, 1, n, i, v[i]);
	}
	while (m != 0 || k != 0) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c - v[b];
			v[b] = c;
			update(1, 1, n, b, diff);
			m--;
		}
		else {
			cout << sum(1, 1, n, b, c) << '\n';
			k--;
		}
	}
}