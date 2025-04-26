#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<int> tree(2000000);
long long sum(int s, int e, int n, int l, int r) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[n];
	int mid = (s + e) / 2;
	return sum(s, mid, n * 2, l, r) + sum(mid + 1, e, n * 2 + 1, l, r);
}
void update(int s, int e, int n, int i) {
 	if (i < s || e < i) return;
	tree[n] += 1;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(s, mid, n * 2, i);
	update(mid + 1, e, n * 2 + 1, i);
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].first, v[i].second = i;
	sort(v.begin(), v.end());
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sum(0, n - 1, 1, v[i].second + 1, n - 1);
		update(0, n - 1, 1, v[i].second);
	}
	cout << ans;
}