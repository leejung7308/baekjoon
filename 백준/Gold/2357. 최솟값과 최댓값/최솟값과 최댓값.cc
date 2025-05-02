#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<int> mintree(400000,INF), maxtree(400000, -1);
void update(int s, int e, int n, int idx, int cur) {
	if (idx < s || e < idx) {
		return;
	}
	mintree[n] = min(mintree[n], cur);
	maxtree[n] = max(maxtree[n], cur);
	if (s == e) return;
	int mid = (s + e) / 2;
	update(s, mid, n * 2, idx, cur);
	update(mid + 1, e, n * 2 + 1, idx, cur);
}
int searchmin(int s, int e, int n, int l, int r) {
	if (r < s || e < l) return INF;
	if (l <= s && e <= r) return mintree[n];
	int mid = (s + e) / 2;
	return min(searchmin(s, mid, n * 2, l, r), searchmin(mid + 1, e, n * 2 + 1, l, r));
}
int searchmax(int s, int e, int n, int l, int r) {
	if (r < s || e < l) return -1;
	if (l <= s && e <= r) return maxtree[n];
	int mid = (s + e) / 2;
	return max(searchmax(s, mid, n * 2, l, r), searchmax(mid + 1, e, n * 2 + 1, l, r));
}
int main() {
	FAST_IO;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		update(0, n - 1, 1, i, tmp);
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cout << searchmin(0, n - 1, 1, a, b) << ' ' << searchmax(0, n - 1, 1, a, b) << '\n';
	}
}