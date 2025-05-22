#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<pair<int, int>> dir = { {-1,1},{0,1},{1,1} };
int r, c, ans = 0;
vector<string> v(10000);
bool dfs(int y, int x) {
	v[y][x] = 'p';
	if (x == c - 1) return true;
	for (const auto& d : dir) {
		int ny = y + d.first, nx = x + d.second;
		if (ny < 0 || ny >= r) continue;
		if (v[ny][nx] == 'x' || v[ny][nx] == 'p') continue;
		if (dfs(ny, nx)) return true;
	}
	return false;
}
int main() {
	FAST_IO;
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> v[i];
	for (int i = 0; i < r; i++) if (dfs(i, 0)) ans++;
	cout << ans;
}