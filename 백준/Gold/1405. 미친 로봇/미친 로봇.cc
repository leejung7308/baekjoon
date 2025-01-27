#include<bits/stdc++.h>
#include<unordered_map>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define LL long long
#define LD long double
using namespace std;
vector<vector<bool>> visited(30, vector<bool>(30));
vector<pair<int, int>> dir = { {0,1},{0,-1},{1,0},{-1,0} };
vector<int> p(4);
int n;
LD ans = 0;
void dfs(int y, int x, int cnt, LD pb) {
	if (cnt == n) {
		ans += pb;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i].first;
		int nx = x + dir[i].second;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = true;
		dfs(ny, nx, cnt + 1, pb/100 * p[i]);
		visited[ny][nx] = false;
	}

}
int main() {
	FAST_IO;
	cout << fixed;
	cout.precision(10);
	cin >> n;
	for (int i = 0; i < 4; i++) cin >> p[i];
	visited[15][15] = true;
	dfs(15, 15, 0, 1);
	cout << ans;
}