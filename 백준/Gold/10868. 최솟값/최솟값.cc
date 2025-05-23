#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int n, m;
vector<int> seg(400000, INF);
void update(int s, int e, int n, int idx, int num) {
	if (idx < s || e < idx) return;
	seg[n] = min(seg[n], num);
	if (s == e) return;
	int mid = (s + e) / 2;
	update(s, mid, n * 2, idx, num);
	update(mid + 1, e, n * 2 + 1, idx, num);
}
int getmin(int s, int e, int n, int l, int r) {
	if (e < l || r < s) return INF;
	if (l <= s && e <= r) return seg[n];
	int mid = (s + e) / 2;
	return min(getmin(s, mid, n * 2, l, r), getmin(mid + 1, e, n * 2 + 1, l, r));
}
int main() {
	FAST_IO;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		update(1, n, 1, i, tmp);
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << getmin(1, n, 1, a, b) << '\n';
	}
}