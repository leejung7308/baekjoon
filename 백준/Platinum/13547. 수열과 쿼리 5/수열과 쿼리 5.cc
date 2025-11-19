#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
#define DIR8 const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
#define MOD 1000000007
#define LL long long
//#define pii pair<int, int>
using namespace std;
struct pii {
	int first, second, idx;
};
unordered_map<int, int> cnt;
vector<int> v, ans;
vector<pii> q;
int n, m;
bool cmp(const pii& a, const pii& b) {
	if ((int)(a.first / sqrt(n)) < (int)(b.first / sqrt(n))) return true;
	if ((int)(a.first / sqrt(n)) == (int)(b.first / sqrt(n))) return a.second < b.second;
	return false;
}
void Input() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	cin >> m;
	q.resize(m);
	ans.resize(m);
	for (int i = 0; i < m; i++) cin >> q[i].first >> q[i].second, q[i].idx = i;
	sort(q.begin(), q.end(), cmp);
}
void Solution() {
	int s = q[0].first, e = q[0].second, c = 0;
	for (int i = s; i <= e; i++) if (++cnt[v[i]] == 1) ++c;
	ans[q[0].idx] = cnt.size();
	for (int i = 1; i < m; i++) {
		while (s > q[i].first) if (++cnt[v[--s]] == 1) ++c;
		while (e < q[i].second) if (++cnt[v[++e]] == 1) ++c;
		while (s < q[i].first) if (--cnt[v[s++]] == 0) --c;
		while (e > q[i].second) if (--cnt[v[e--]] == 0) --c;
		ans[q[i].idx] = c;
	}
	for (int i : ans) cout << i << '\n';
}
int main() {
	int t = 1;
	while (t--) {
		Input();
		Solution();
	}
}