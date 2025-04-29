#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
DIR;
int n, m, ans=INF;
vector<vector<int>> v(8, vector<int>(8));
vector<pair<int, int>> cctv;
void dfs(const vector<vector<vector<vector<int>>>>& memo, const vector<vector<int>>& prev, int cur) {
	if (cur == memo.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (prev[i][j] == 0) cnt++;
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < memo[cur].size(); i++) {
		vector<vector<int>> next = prev;
		for (int j = 0; j < n; j++) for (int k = 0; k < m; k++) if (memo[cur][i][j][k] == 9) next[j][k] = 9;
		dfs(memo, next, cur + 1);
	}
}
int main() {
	FAST_IO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> v[i][j];
		if (v[i][j] > 0 && v[i][j] < 6) cctv.push_back({ i,j });
	}
	vector<vector<vector<vector<int>>>> memo(cctv.size());
	for (int i = 0; i < cctv.size(); i++) {
		vector<vector<int>> tmp;
		int y = cctv[i].first, x = cctv[i].second;
		switch (v[y][x]) {
		case 1:
			for (const auto& d : dir) {
				tmp = v;
				int cy = y, cx = x;
				while (cy >= 0 && cy < n && cx >= 0 && cx < m && v[cy][cx] != 6) {
					if (tmp[cy][cx] == 0) tmp[cy][cx] = 9;
					cy += d.first;
					cx += d.second;
				}
				memo[i].push_back(tmp);
			}
			break;
		case 2:
			for (int j = 0; j <= 1; j++) {
				tmp = v;
				int cy = y, cx = x;
				pair<int, int> d = dir[j];
				while (cy >= 0 && cy < n && cx >= 0 && cx < m && v[cy][cx] != 6) {
					if (tmp[cy][cx] == 0) tmp[cy][cx] = 9;
					cy += d.first;
					cx += d.second;
				}
				cy = y, cx = x;
				d = dir[j + 2];
				while (cy >= 0 && cy < n && cx >= 0 && cx < m && v[cy][cx] != 6) {
					if (tmp[cy][cx] == 0) tmp[cy][cx] = 9;
					cy += d.first;
					cx += d.second;
				}
				memo[i].push_back(tmp);
			}
			break;
		case 3:
			for (int j = 0; j < dir.size(); j++) {
				tmp = v;
				int cy = y, cx = x;
				pair<int, int> d = dir[j], d2 = dir[(j + 1) % 4];
				while (cy >= 0 && cy < n && cx >= 0 && cx < m && v[cy][cx] != 6) {
					if (tmp[cy][cx] == 0) tmp[cy][cx] = 9;
					cy += d.first;
					cx += d.second;
				}
				cy = y, cx = x;
				while (cy >= 0 && cy < n && cx >= 0 && cx < m && v[cy][cx] != 6) {
					if (tmp[cy][cx] == 0) tmp[cy][cx] = 9;
					cy += d2.first;
					cx += d2.second;
				}
				memo[i].push_back(tmp);
			}
			break;
		case 4:
			for (const auto& ex:dir) {
				tmp = v;
				for (const auto& d : dir) {
					if (ex == d) continue;
					int cy = y, cx = x;
					while (cy >= 0 && cy < n && cx >= 0 && cx < m && v[cy][cx] != 6) {
						if (tmp[cy][cx] == 0) tmp[cy][cx] = 9;
						cy += d.first;
						cx += d.second;
					}	
				}
				memo[i].push_back(tmp);
			}
			break;
		case 5:
			tmp = v;
			for (const auto& d : dir) {
				int cy = y, cx = x;
				while (cy >= 0 && cy < n && cx >= 0 && cx < m && v[cy][cx] != 6) {
					if (tmp[cy][cx] == 0) tmp[cy][cx] = 9;
					cy += d.first;
					cx += d.second;
				}
			}
			memo[i].push_back(tmp);
			break;
		}
	}
	dfs(memo, v, 0);
	cout << ans;
}