#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define DIR8 const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
bool cmp(const pii& a, const pii& b) { return a.first > b.first; }
int n;
vector<pii> v;
vector<int> fen;
void update(int idx) {
	while (idx <= n) {
		fen[idx]++;
		idx += idx & -idx;
	}
}
int sum(int idx) {
	int ret = 0;
	while (idx >= 1) {
		ret += fen[idx];
		idx -= idx & -idx;
	}
	return ret;
}
int main() {
	FAST_IO;
	cin >> n;
	fen.resize(n + 1);
	vector<int> ans(n + 1);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) v[i].second = i, cin >> v[i].first;
	sort(v.begin() + 1, v.end());
	for (int i = 1; i <= n; i++) {
		int tmp = sum(v[i].second - 1);
		ans[v[i].second] = v[i].second - tmp;
		update(v[i].second);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}