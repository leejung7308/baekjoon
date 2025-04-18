#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
const pair<int, int> operator+(const pair<int, int>& lhs, const pair<int,int>& rhs) {
	return { lhs.first + rhs.first,lhs.second + rhs.second };
}
const pair<int, int> operator-(const pair<int, int>& lhs, const pair<int, int>& rhs) {
	return { lhs.first - rhs.first,lhs.second - rhs.second };
}
int g(const vector<vector<int>>& v, const pair<int, int>& pos) {
	return v[pos.first][pos.second];
}
void s(vector<vector<int>>& v, const pair<int, int>& pos, int x) {
	v[pos.first][pos.second] = x;
}
void printv(const vector<vector<int>>& v) {
	for (int i = 1; i < v.size() - 1; i++) {
		for (int j = 1; j < v.size() - 1; j++) cout << v[i][j] << ' ';
		cout << '\n';
	}
	cout << "---------------------\n";
}
void dfs(const vector<pair<int, int>>& dir, const vector<vector<int>>& v, int& ans, int cnt) {
	//cout << "======" << cnt <<"======\n";
	//printv(v);
	if (cnt >= 5) return;
	int n = v.size() - 2;
	for (const auto& d : dir) {
		vector<vector<int>> next = v;
		vector<vector<bool>> merged(v.size(), vector<bool>(v.size()));
		int modifier = 0, j = 0;
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			bool moved = false;
			do {
				moved = false;
				if (d.first < 0 || d.second < 0) {
					modifier = 1;
					j = 1;
				}
				else if (d.first > 0 || d.second > 0) {
					modifier = -1;
					j = n;
				}
				while(true) {
					pair<int, int> cp, np;
					d.first ? cp = { j,i } : cp = { i,j };
					np = cp + d;
					if (g(next, cp) == -1) break;
					if (g(next, cp) == 0 || g(next, np) == -1 || (g(next, np) != 0 && g(next, np) != g(next, cp))) {
						j += modifier;
						continue;
					}
					if (g(next, np) == g(next, cp) && !merged[np.first][np.second] && !merged[cp.first][cp.second]) {
						s(next, cp, 0);
						s(next, np, g(next, np) * 2);
						merged[np.first][np.second] = true;
						moved = true;
						flag = true;
						ans = max(ans, g(next, np));
					}
					else if (g(next, np) == 0) {
						s(next, np, g(next, cp));
						s(next, cp, 0);
						moved = true;
						flag = true;
					}
					j += modifier;
				}
			} while (moved);
		}
		if(flag) dfs(dir, next, ans, cnt + 1);
	}
}
int main() {
	FAST_IO;
	DIR;
	int n, ans = 0;
	cin >> n;
	vector<vector<int>> v(n + 2, vector<int>(n + 2, -1));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> v[i][j], ans = max(v[i][j], ans);
	dfs(dir, v, ans, 0);
	cout << ans;
}