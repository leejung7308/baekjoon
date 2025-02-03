#include<bits/stdc++.h>
#include<unordered_map>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define LL long long
#define LD long double
using namespace std;
int n, m, ans = 0;
priority_queue<pair<int,pair<int,int>>> pq;
vector<int> parent;
int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}
void Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	parent[pb] = pa;
}
bool check(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	return pa == pb;
}
void kruskal() {
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int ca = pq.top().second.first;
		int cb = pq.top().second.second;
		pq.pop();
		if (check(ca, cb)) continue;
		ans += cost;
		Union(ca, cb);
	}
}
int main() {
	FAST_IO;
	cin >> n >> m;
	parent = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ -c,{a,b} });
	}
	kruskal();
	cout << ans;
}