#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int n, m;
int parent[200];
int findp(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findp(parent[x]);
}
void uni(int a, int b) {
	a = findp(a);
	b = findp(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	parent[b] = a;
}
int main() {
	FAST_IO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			if (tmp) uni(i, j);
		}
	}
	vector<int> v(m);
	for (int i = 0; i < m; i++) cin >> v[i];
	if (v.size() == 0) {
		cout << "YES";
		return 0;
	}
	int p = findp(v[0] - 1);
	for (int i = 1; i < m; i++) {
		if (findp(v[i] - 1) != p) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}