#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<vector<int>> v(20, vector<int>(20));
int n, m, x, y, k;
int op(int cur) {
	if (cur == 0 || cur == 5) return cur == 0 ? 5 : 0;
	if (cur == 1 || cur == 2) return cur == 1 ? 2 : 1;
	if (cur == 3 || cur == 4) return cur == 3 ? 4 : 3;
	return -1;
}
int main() {
	FAST_IO;
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];
	vector<int> dir = { -1,1,2,3,4 };
	vector<int> dice(6, 0);
	int cur = 0;
	while (k--) {
		int d, next;
		cin >> d;
		if (d == 1) {
			if (x + 1 >= m) continue;
			next = dir[1];
			dir[1] = op(cur);
			dir[2] = cur;
			x++;
		}
		else if (d == 2) {
			if (x - 1 < 0) continue;
			next = dir[2];
			dir[1] = cur;
			dir[2] = op(cur);
			x--;
		}
		else if (d == 3) {
			if (y - 1 < 0) continue;
			next = dir[3];
			dir[3] = op(cur);
			dir[4] = cur;
			y--;
		}
		else {
			if (y + 1 >= n) continue;
			next = dir[4];
			dir[3] = cur;
			dir[4] = op(cur);
			y++;
		}
		cur = next;
		if (v[y][x] == 0) v[y][x] = dice[cur];
		else dice[cur] = v[y][x], v[y][x] = 0;
		cout << dice[op(cur)] << '\n';
		/*cout << "cur: " << cur << '\n';
		for (int i = 0; i < 6; i++) cout << dice[i] << ' ';
		cout << "\n";*/
	}
}