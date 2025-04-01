#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
double distance(pair<int, int> a, pair<int, int> b) {
	return sqrt((long long)(b.first - a.first) * (b.first - a.first) + (long long)(b.second - a.second) * (b.second - a.second));
}
int main() {
	FAST_IO;
	int n;
	double mindist = INF;
	pair<int, int> ans;
	cin >> n;
	vector<pair<int, int>> pos(n);
	for (int i = 0; i < n; i++) cin >> pos[i].first >> pos[i].second;
	for (int i = 0; i < n; i++) {
		double maxdist = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			double dist = distance(pos[i], pos[j]);
			if (dist > maxdist) maxdist = dist;
		}
		if (mindist > maxdist) {
			mindist = maxdist;
			ans = pos[i];
		}
	}
	cout << ans.first << ' ' << ans.second;
}