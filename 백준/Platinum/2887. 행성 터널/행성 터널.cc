#include<bits/stdc++.h>
#include<unordered_map>
#define INF 2000000001
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<int> parent;
int findp(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findp(parent[x]);
}
void uni(int a, int b) {
	a = findp(a);
	b = findp(b);
	a < b ? parent[b] = a : parent[a] = b;
}
struct pos {int x, y, z, n;};
struct weight { int w, a, b;};
bool compx(const pos& a, const pos& b) {
	return a.x < b.x;
}
bool compy(const pos& a, const pos& b) {
	return a.y < b.y;
}
bool compz(const pos& a, const pos& b) {
	return a.z < b.z;
}
bool comp(const weight& a, const weight& b) {
	return a.w < b.w;
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) parent.push_back(i);
	vector<pos> v(n);
	vector<weight> w;
	for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y >> v[i].z, v[i].n = i;
	sort(v.begin(), v.end(), compx);
	for (int i = 0; i < n - 1; i++) w.push_back({ abs(v[i].x - v[i + 1].x),v[i].n,v[i + 1].n });
	sort(v.begin(), v.end(), compy);
	for (int i = 0; i < n - 1; i++) w.push_back({ abs(v[i].y - v[i + 1].y),v[i].n,v[i + 1].n });
	sort(v.begin(), v.end(), compz);
	for (int i = 0; i < n - 1; i++) w.push_back({ abs(v[i].z - v[i + 1].z),v[i].n,v[i + 1].n });
	sort(w.begin(), w.end(), comp);
	long long ans = 0;
	for (int i = 0; i < w.size(); i++) {
		int cost = w[i].w;
		int a = w[i].a, b = w[i].b;
		if (findp(a) != findp(b)) {
			ans += cost;
			uni(a, b);
		}
	}
	cout << ans;
}