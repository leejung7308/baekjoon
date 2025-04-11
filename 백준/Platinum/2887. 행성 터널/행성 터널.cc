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
struct pos {int x, y, z;};
struct weight { int w, a, b;};
bool compx(const pair<int, pos>& a, const pair<int, pos>& b) {
	return a.second.x < b.second.x;
}
bool compy(const pair<int, pos>& a, const pair<int, pos>& b) {
	return a.second.y < b.second.y;
}
bool compz(const pair<int, pos>& a, const pair<int, pos>& b) {
	return a.second.z < b.second.z;
}
bool comp(const weight& a, const weight& b) {
	return a.w < b.w;
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) parent.push_back(i);
	vector<pair<int,pos>> v(n);
	vector<weight> w;
	for (int i = 0; i < n; i++) cin >> v[i].second.x >> v[i].second.y >> v[i].second.z, v[i].first = i;
	sort(v.begin(), v.end(), compx);
	for (int i = 0; i < n - 1; i++) w.push_back({ abs(v[i].second.x - v[i + 1].second.x),v[i].first,v[i + 1].first });
	sort(v.begin(), v.end(), compy);
	for (int i = 0; i < n - 1; i++) w.push_back({ abs(v[i].second.y - v[i + 1].second.y),v[i].first,v[i + 1].first });
	sort(v.begin(), v.end(), compz);
	for (int i = 0; i < n - 1; i++) w.push_back({ abs(v[i].second.z - v[i + 1].second.z),v[i].first,v[i + 1].first });
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