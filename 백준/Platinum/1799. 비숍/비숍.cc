#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int ans = 0;
vector<bool> col(20), row(20);
void printv(const vector<vector<int>>& v) {
	cout << "------------------\n";
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) cout << v[i][j] << ' ';
		cout << '\n';
	}
	cout << "------------------\n";
}
vector<vector<int>> tiltboard(const vector<vector<int>>& v) {
	vector<vector<int>> ret(2 * v.size() - 1, vector<int>(2 * v.size() - 1));
	int sy = 0, sx = v.size() - 1;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			ret[sy + j][sx + j] = v[i][j];
		}
		sy++, sx--;
	}
	return ret;
}
void bruteforce(vector<vector<int>>& v, int cnt, int y) {
	if (y >= v.size()){
		//if (cnt > ans) printv(v);
		ans = max(ans, cnt);
		return;
	}
	bool flag = false;
	for (int j = 0; j < v.size(); j++) {
		if (col[j]) continue;
		if (v[y][j] == 1) {
			flag = true;
			v[y][j] = 2;
			row[y] = true, col[j] = true;
			bruteforce(v, cnt + 1, y + 1);
			row[y] = false, col[j] = false;
			v[y][j] = 1;
		}
	}
	if(!flag) bruteforce(v, cnt, y + 1);
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
	v = tiltboard(v);
	bruteforce(v, 0, 0);
	cout << ans;
}