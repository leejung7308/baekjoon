#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
struct shark {
	int s, d, z;
};
void moveshark(vector<vector<shark>>& v) {
	vector<pair<int, int>> dir = { {0,0},{ -1,0 },{1,0},{0,1},{0,-1} };
	vector<vector<shark>> tmp(v.size(),vector<shark>(v[0].size()));
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			if (v[i][j].z == 0) continue;
			int s = v[i][j].s, d = v[i][j].d, z = v[i][j].z;
			int nr = i + dir[d].first * s, nc = j + dir[d].second * s;
			while (nr < 0 || nr >= v.size() || nc < 0 || nc >= v[0].size()) {
				if (nr < 0) nr *= -1, d = 2;
				else if (nr >= v.size()) nr = 2 * v.size() - nr - 2, d = 1;
				if (nc < 0) nc *= -1, d = 3;
				else if (nc >= v[0].size()) nc = 2 * v[0].size() - nc - 2, d = 4;
			}
 			if (tmp[nr][nc].z > z) continue;
			tmp[i][j].z == 0;
			tmp[nr][nc] = { s,d,z };
		}
	}
	v = tmp;
}
void printshark(const vector<vector<shark>>& v) {
	cout << "---------------\n";
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) cout << (v[i][j].z ? 1 : 0) << ' ';
		cout << '\n';
	}
	cout << "---------------\n";
}
int main() {
	FAST_IO;
	int r, c, m, ans = 0;
	cin >> r >> c >> m;
	vector<vector<shark>> v(r, vector<shark>(c));
	for (int i = 0; i < m; i++) {
		int R, C, S, D, Z;
		cin >> R >> C >> S >> D >> Z;
		R--, C--;
		v[R][C].s = S;
		v[R][C].d = D;
		v[R][C].z = Z;
	}
	for (int cur = 0; cur < c; cur++) {
		//printshark(v);
		for (int i = 0; i < r; i++) {
			if (v[i][cur].z == 0) continue;
			ans += v[i][cur].z;
			v[i][cur].z = 0;
			break;
		}
		moveshark(v);
	}
	cout << ans;
}