#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
vector<pair<int, pair<int, int>>> edges;
vector<int> parent;
int n, m, ans = 0, cnt = 0;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	parent[y] = x;
}
bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}
void mst() {
	int last = 0;
	for (auto& edge : edges) {
		int cost = edge.first;
		int f = edge.second.first;
		int s = edge.second.second;
		if (!sameparent(f, s)) {
			uni(f, s);
			ans += cost;
			last = cost;
		}
	}
	ans -= last;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	parent = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });
	}
	sort(edges.begin(), edges.end());
	mst();
	cout << ans;
}