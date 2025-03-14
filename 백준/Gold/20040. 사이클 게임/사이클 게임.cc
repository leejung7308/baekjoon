#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
vector<int> parent;
int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	FAST_IO;
	int n, m, ans = 0;
	cin >> n >> m;
	parent = vector<int>(n);
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 1; i <= m && ans == 0; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) ans = i;
		else uni(a, b);
	}
	cout << ans;
}