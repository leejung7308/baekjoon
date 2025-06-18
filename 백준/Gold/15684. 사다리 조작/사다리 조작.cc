#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
int n, m, h;
int line[12][31];
void print() {
	cout << "==========\n";
	for (int i = 1; i <= n; i++) cout << i << ' ';
	cout << "\n----------\n";
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			cout << line[j][i] << ' ';
		}
		cout << '\n';
	}
	cout << "==========\n";
}
bool check() {
	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int j = 1; j <= h; j++) {
			if (line[cur][j]) cur = line[cur][j];
		}
		//cout << i << ' ' << cur << '\n';
		if (cur != i) return false;
	}
	return true;
}
bool dfs(int cnt, int maxn, int cline, int num) {
	if (cnt == maxn) {
		//print();
		return check();
	}
	for (int i = 1; i < n; i++) {
		if (i < cline) continue;
		for (int j = 1; j <= h; j++) {
			if (i == cline && j < num) continue;
			if (line[i][j]) continue;
			if (line[i+1][j]) continue;
			line[i][j] = i + 1;
			line[i + 1][j] = i;
			if (dfs(cnt + 1, maxn, i, j)) return true;
			line[i][j] = 0;
			line[i + 1][j] = 0;
		}
	}
	return false;
}
int main() {
	FAST_IO;
	cin >> n >> m >> h;
	while (m--) {
		int a, b;
		cin >> a >> b;
		line[b][a] = b+1;
		line[b + 1][a] = b;
	}
	if (dfs(0, 0, 1, 1)) cout << 0;
	else if (dfs(0, 1, 1, 1)) cout << 1;
	else if (dfs(0, 2, 1, 1)) cout << 2;
	else if (dfs(0, 3, 1, 1)) cout << 3;
	else cout << -1;
}