#include<iostream>
#include<vector>
using namespace std;
int n, m;
int parent[1000001];
int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}
void findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i]=i;
	for (int i = 0; i < m; i++) {
		int cal, a, b;
		cin >> cal >> a >> b;
		if (cal == 0) unionParent(a, b);
		else findParent(a, b);
	}
}