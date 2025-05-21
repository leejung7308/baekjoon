#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int n;
long long ans = 0;
map<pair<int, int>, bool> v;
void dragoncurve(int x, int y, int d, int g) {
	vector<pair<int, int>> tmp;
	tmp.push_back({ x,y });
	int zx = x, zy = y;
	switch (d) {
	case 0:
		zx++;
		break;
	case 1:
		zy--;
		break;
	case 2:
		zx--;
		break;
	case 3:
		zy++;
		break;
	}
	tmp.push_back({ zx,zy });
	while (g) {
		int sx = tmp.back().first, sy = tmp.back().second;
		for (int i = tmp.size() - 2; i >= 0; i--) {
			int dx = tmp[i].first - sx, dy = tmp[i].second - sy;
			tmp.push_back({ sx - dy,sy + dx });
		}
		g--;
	}
	for (const auto& p : tmp) {
		if (v.find(p) != v.end()) continue;
		if (v.find({ p.first + 1,p.second }) != v.end() && v.find({ p.first + 1,p.second + 1 }) != v.end() && v.find({ p.first,p.second + 1 }) != v.end()) ans++;
		if (v.find({ p.first + 1,p.second }) != v.end() && v.find({ p.first + 1,p.second - 1 }) != v.end() && v.find({ p.first,p.second - 1 }) != v.end()) ans++;
		if (v.find({ p.first - 1,p.second }) != v.end() && v.find({ p.first - 1,p.second + 1 }) != v.end() && v.find({ p.first,p.second + 1 }) != v.end()) ans++;
		if (v.find({ p.first - 1,p.second }) != v.end() && v.find({ p.first - 1,p.second - 1 }) != v.end() && v.find({ p.first,p.second - 1 }) != v.end()) ans++;
		v[p] = true;
	}
}
int main() {
	FAST_IO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dragoncurve(x, y, d, g);
	}
	cout << ans;
}