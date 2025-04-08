#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
struct circle {
	int x;
	int y;
	int r;
};
double distance(const pair<int, int>& a, const pair<int, int>& b) {
	return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}
bool isgroup(const circle& a, const circle& b) {
	if (a.r + b.r >= distance({ a.x,a.y }, { b.x,b.y })) return true;
	else return false;
}
int findparent(vector<int>& parent, int x) {
	if (parent[x] == x) return x;
	return parent[x] = findparent(parent, parent[x]);
}
void Union(vector<int>& parent, int a, int b) {
	a = findparent(parent, a);
	b = findparent(parent, b);
	a < b ? parent[b] = a : parent[a] = b;
}
int main() {
	FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		int n, g = 0;
		cin >> n;
		unordered_map<int, vector<circle>> mem;
		vector<int> parent(1);
		for (int i = 0; i < n; i++) {
			circle cur;
			cin >> cur.x >> cur.y >> cur.r;
			if (i == 0) {
				mem[g].push_back(cur);
				continue;
			}
			int flag = -1;
			for (auto& p : mem) {
				for (int j = 0; j < p.second.size(); j++) {
					if (isgroup(p.second[j], cur)) {
						if (flag == -1) {
							p.second.push_back(cur);
							flag = p.first;
							break;
						}
						else Union(parent, p.first, flag);
					}
				}
			}
			if (flag == -1) {
				mem[++g].push_back(cur);
				parent.push_back(g);
			}
		}
		int ans = 0;
		for (int i = 0; i < parent.size(); i++) {
			int p = findparent(parent, i);
			if (p == i) ans++;
		}
		cout << ans << '\n';
	}
}