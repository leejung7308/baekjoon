#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define LL long long
#define pii pair<int,int>
using namespace std;
int n, m, t;
int v[52][50];
int f[52];
void removeNum() {
	set<pii> removelist;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int idx = (f[i] + j) % m;
			int adjidx = (f[i + 1] + j) % m;
			if (v[i][idx] == 0) continue;
			if (v[i][idx] == v[i][(idx + 1) % m]) removelist.insert({ i,idx }), removelist.insert({ i,(idx + 1) % m });
			if (v[i][idx] == v[i + 1][adjidx]) removelist.insert({ i,idx }), removelist.insert({ i + 1,adjidx });
		}
	}
	if (removelist.size() == 0) {
		int cnt = 0;
		float avg, sum = 0;
		for (int i = 1; i <= n; i++) for (int j = 0; j < m; j++) if (v[i][j] != 0) cnt++, sum += v[i][j];
		avg = sum / cnt;
		for (int i = 1; i <= n; i++) for (int j = 0; j < m; j++) {
			if (v[i][j] == 0) continue;
			if (v[i][j] < avg) v[i][j]++;
			else if (v[i][j] > avg) v[i][j]--;
		}
	}
	else for (const auto& p : removelist) v[p.first][p.second] = 0;
}
int main() {
	FAST_IO;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];
	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;
		for (int i = 1; i <= n; i++) {
			if (i % x != 0) continue;
			if (d == 0) f[i] = m + (f[i] - k) % m;
			else f[i] = (f[i] + k) % m;
		}
		removeNum();
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) for (int j = 0; j < m; j++) if (v[i][j] != 0) ans += v[i][j];
	cout << ans;
}