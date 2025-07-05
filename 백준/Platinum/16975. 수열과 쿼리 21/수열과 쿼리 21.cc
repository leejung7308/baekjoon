#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
int n, m;
vector<LL> v;
vector<LL> seg(400000);
void update(int start, int end, int n, int left, int right, int diff) {
	if (end < left || right < start) return;
	if (left <= start && end <= right) {
		seg[n] += diff;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, n * 2, left, right, diff);
	update(mid + 1, end, n * 2 + 1, left, right, diff);
}
LL get(int start, int end, int n, int idx) {
	if (start == end) return seg[n];
	if (seg[n] != 0) {
		seg[n * 2] += seg[n];
		seg[n * 2 + 1] += seg[n];
		seg[n] = 0;
	}
	int mid = (start + end) / 2;
	if (start <= idx && idx <= mid) return get(start, mid, n * 2, idx);
	else return get(mid + 1, end, n * 2 + 1, idx);
}
int main() {
	FAST_IO;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		update(1, n, 1, i, i, tmp);
	}
	cin >> m;
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, j, k;
			cin >> i >> j >> k;
			update(1, n, 1, i, j, k);
		}
		else {
			int x;
			cin >> x;
			cout << get(1, n, 1, x) << '\n';
		}
	}
}