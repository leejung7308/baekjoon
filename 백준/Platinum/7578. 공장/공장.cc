#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<int> fenwick(500001);
long long sum(int idx) {
	long long ret = 0;
	while (idx) {
		ret += fenwick[idx];
		idx -= idx & -idx;
	}
	return ret;
}
void update(int n, int idx) {
	while (idx <= n) {
		fenwick[idx]++;
		idx += idx & -idx;
	}
}
int main() {
	FAST_IO;
	int n;
	long long ans = 0;
	cin >> n;
	unordered_map<int, int> m;
	vector<int> v(n);
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		m[tmp] = i;
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v[i] = m[tmp];
	}
	for (int i = n - 1; i >= 0; i--) {
		ans += sum(v[i]);
		update(n, v[i]);
	}
	cout << ans;
}