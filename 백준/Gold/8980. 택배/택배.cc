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
struct node {
	int from, to, cnt;
};
bool cmp(const node& a, const node& b) {
	if (a.to == b.to) return a.from < b.from;
	else return a.to < b.to;
}
int main() {
	FAST_IO;
	int n, c, m;
	cin >> n >> c >> m;
	vector<node> v(m);
	vector<int> truck(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, cnt;
		cin >> from >> to >> cnt;
		if (from > to) continue;
		v[i] = { from,to,cnt };
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int from = v[i].from, to = v[i].to, cnt = v[i].cnt;
		int maxn = 0;
		for (int j = from; j < to; j++) maxn = max(maxn, truck[j]);
		int add = min(cnt, c - maxn);
		for (int j = from; j < to; j++) truck[j] += add;
		ans += add;
	}
	cout << ans;
}