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
#define pii pair<int, int>
using namespace std;
struct edge {
	double dist;
	int from, to;
};
vector<pii> pos;
vector<edge> edges;
vector<vector<bool>> has;
vector<int> parent;
int n, m, cnt = 0;
double ans = 0;
bool cmp(const edge& a, const edge& b) { return a.dist < b.dist; }
double dist(const pii& a, const pii& b) { return sqrt(pow((double)a.first - b.first, 2) + pow((double)a.second - b.second, 2)); }
int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}
bool Union(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a > b) swap(a, b);
	if (a == b) return false;
	parent[b] = a;
	return true;
}
void Input() {
	cin >> n >> m;
	pos.resize(n + 1);
	has.resize(n + 1, vector<bool>(n + 1));
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		cin >> pos[i].first >> pos[i].second;
		for (int j = 1; j < i; j++) edges.push_back({ dist(pos[i],pos[j]),i,j });
	}
	while (m--) {
		int from, to;
		cin >> from >> to;
		has[from][to] = true;
		has[to][from] = true;
		Union(from, to);
	}
}
void Solution() {
	sort(edges.begin(), edges.end(), cmp);
	for (auto& [d, f, t] : edges) {
		if (cnt == n - 1) break;
		if (Union(f, t)) {
			if (!(has[f][t] || has[t][f])) ans += d;
			cnt++;
		}
	}
	cout.precision(2);
	cout << fixed;
	cout << ans;
}
int main() {
	int t = 1;
	while (t--) {
		Input();
		Solution();
	}
}