#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int findp(vector<int>& parent, int x) {
	if (x == parent[x]) return x;
	return parent[x] = findp(parent, parent[x]);
}
void uni(vector<int>& parent, int a, int b) {
	a = findp(parent, a);
	b = findp(parent, b);
	a < b ? parent[b] = a : parent[a] = b;
}
int main() {
	FAST_IO;
	int g, p;
	cin >> g >> p;
	vector<bool> gate(g + 1);
	vector<int> parent(g + 1);
	gate[0] = true;
	for (int i = 0; i < g; i++) parent[i] = i;
	for(int i = 0; i < p; i++) {
		int gi;
		cin >> gi;
		if (!gate[gi]) {
			gate[gi] = true;
			parent[gi] = gi - 1;
			continue;
		}
		int next = findp(parent, gi);
		if (gate[next]) {
			cout << i;
			return 0;
		}
		gate[next] = true;
		parent[next] = next - 1;
	}
	cout << p;
}