#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define DIR8 const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
int n, m;
vector<vector<int>> v;
vector<int> work;
vector<bool> visited;
bool tryconnect(int p) {
	for (int w : v[p]) {
		if (work[w] == 0) {
			work[w] = p;
			return true;
		}
	}
	for (int w : v[p]) {
		if (visited[w]) continue;
		visited[w] = true;
		if (work[w] == p) continue;
		if (tryconnect(work[w])) {
			work[w] = p;
			return true;
		}
	}
	return false;
}
int main() {
	FAST_IO;
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	work.resize(m + 1);
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		if (c == 0) continue;
		vector<int> tmp(c, 0);
		for (int j = 0; j < c; j++) cin >> tmp[j];
		v[i] = tmp;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		visited = vector<bool>(m + 1, false);
		if (tryconnect(i)) ans++;
		if (tryconnect(i)) ans++;
		if (ans == m) break;
	}
	cout << ans;
}