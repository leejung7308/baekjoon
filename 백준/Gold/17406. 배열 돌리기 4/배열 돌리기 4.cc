#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
struct rcs {
	int r, c, s;
};
void rotate(rcs x, vector<vector<int>>& v) {
	int r = x.r, c = x.c, s = x.s;
	for (; s > 0; s--) {
		int first = v[r - s][c + s];
		for (int i = c + s; i > c - s; i--) {
			v[r - s][i] = v[r - s][i - 1];
		}
		for (int i = r - s; i < r + s; i++) {
			v[i][c - s] = v[i + 1][c - s];
		}
		for (int i = c - s; i < c + s; i++) {
			v[r + s][i] = v[r + s][i + 1];
		}
		for (int i = r + s; i > r - s; i--) {
			v[i][c + s] = v[i - 1][c + s];
		}
		v[r - s + 1][c + s] = first;
	}
}
int arraymin(const vector<vector<int>>& v) {
	int ret = INF;
	for (int i = 1; i < v.size();i++) {
		int sum = 0;
		for (int j = 1; j < v[0].size(); j++) {
			sum += v[i][j];
		}
		ret = min(ret, sum);
	}
	return ret;
}
void printarray(const vector<vector<int>>& v) {
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 1; j < v[0].size(); j++) cout << v[i][j] << ' ';
		cout << '\n';
	}
}
int dfs(const vector<vector<int>>& v, const vector<rcs> rv, vector<bool>& visited,int cur) {
	int ret = INF;
	if (cur == rv.size()) {
		ret = arraymin(v);
		return ret;
	}
	for (int i = 0; i < rv.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		vector<vector<int>> tmp = v;
		rotate(rv[i], tmp);
		/*cout << "------\ncur: " << cur << " sel: " << i << "\n-----\n";
		printarray(tmp);*/
		ret = min(ret,dfs(tmp, rv, visited, cur+1));
		visited[i] = false;
	}
	return ret;
}
int main() {
	FAST_IO;
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> v(n + 1, vector<int>(m + 1));
	vector<rcs> rcsv;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> v[i][j];
	while (k--) {
		int r, c, s;
		cin >> r >> c >> s;
		rcsv.push_back({r,c,s});
	}
	vector<bool> visited(rcsv.size());
	cout << dfs(v, rcsv, visited, 0);
}