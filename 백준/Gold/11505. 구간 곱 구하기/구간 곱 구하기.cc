#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define MOD 1000000007
using namespace std;
int n, m, k;
vector<long long> seg(2100000, 1);
void update(int s, int e, int n, int idx, int diff) {
	if (idx < s || e < idx) return;
	if (s == e) {
		seg[n] = diff;
		return;
	}
	int mid = (s + e) / 2;
	update(s, mid, n * 2, idx, diff);
	update(mid + 1, e, n * 2 + 1, idx, diff);
	seg[n] = (seg[n * 2] * seg[n * 2 + 1]) % MOD;
}
long long getnum(int s, int e, int n, int l, int r) {
	if (e < l || r < s) return 1;
	if (l <= s && e <= r) return seg[n];
	int mid = (s + e) / 2;
	return (getnum(s, mid, n * 2, l, r) * getnum(mid + 1, e, n * 2 + 1, l, r)) % MOD;
}
int main() {
	FAST_IO;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		update(1, n, 1, i, tmp);
	}
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, n, 1, b, c);
		else cout << getnum(1, n, 1, b, c) << '\n';
	}
}