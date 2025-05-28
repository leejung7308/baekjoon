#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define LL long long
#define pii pair<int,int>
using namespace std;
struct fish {
	int n;
	int d;
};
void printv(const vector<vector<fish>>& v) {
	cout << "=============================\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) cout << v[i][j].n << '\t';
		cout << '\n';
	}
	cout << "=============================\n";
}
vector<pii> dir = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
int dfs(vector<vector<fish>> v, map<int,pii> fishes, pii shark, int prev) {
	//printv(v);
	for (const auto& p : fishes) {
		int y = p.second.first, x = p.second.second;
		int n = v[y][x].n, d = v[y][x].d;
		while (true) {
			int ny = y + dir[d].first, nx = x + dir[d].second;
			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) ++d %= 8;
			else if (v[ny][nx].n == -1) ++d %= 8;
			else {
				v[y][x] = { n,d };
				if (v[ny][nx].n != 0) swap(fishes[n], fishes[v[ny][nx].n]);
				else fishes[n] = { ny,nx };
				swap(v[y][x], v[ny][nx]);
				break;
			}
		}
	}
	int sy = shark.first, sx = shark.second, sd = v[sy][sx].d;
	sy += dir[sd].first;
	sx += dir[sd].second;
	vector<pii> moves;
	while (sy >= 0 && sy < 4 && sx >= 0 && sx < 4) {
		if (v[sy][sx].n != 0) moves.push_back({ sy,sx });
		sy += dir[sd].first;
		sx += dir[sd].second;
	}
	if (moves.size() == 0) return prev;
	int next = 0;
	for (const pii& p : moves) {
		int ny = p.first, nx = p.second;
		vector<vector<fish>> tmp = v;
		map<int, pii> f = fishes;
		int n = tmp[ny][nx].n, d = tmp[ny][nx].d;
		tmp[ny][nx] = { -1,d };
		tmp[shark.first][shark.second] = { 0,0 };
		f.erase(n);
		next = max(next, dfs(tmp, f, { ny,nx }, n));
	}
	return prev + next;
}
int main() {
	FAST_IO;
	vector<vector<fish>> v(4, vector<fish>(4));
	map<int, pii> fishes;
	fish shark;
	int ans = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		int a, b;
		cin >> a >> b;
		if (i == 0 && j == 0) {
			ans += a;
			shark = { -1,b - 1 };
			continue;
		}
		v[i][j] = { a,b - 1 };
		fishes[a] = { i,j };
	}
	v[0][0] = shark;
	cout << dfs(v, fishes, { 0,0 }, ans);
}