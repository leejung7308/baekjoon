#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
DIR;
LL seg[400000];
LL sum(int start, int end, int n, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return seg[n];
	int mid = (start + end) / 2;
	return sum(start, mid, n * 2, left, right) + sum(mid + 1, end, n * 2 + 1, left, right);
}
void update(int start, int end, int n, int idx, LL diff) {
	if (idx < start || end < idx) return;
	seg[n] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, n * 2, idx, diff);
	update(mid + 1, end, n * 2 + 1, idx, diff);
}
int main() {
	FAST_IO;
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		update(1, n, 1, i, v[i]);
	}
	while (q--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << sum(1, n, 1, x, y) << '\n';
		update(1, n, 1, a, (LL)b - v[a]);
		v[a] = b;
	}
}