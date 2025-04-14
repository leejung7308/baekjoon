#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
struct tree { int l, r; };
int idx = 0;
void dfs(const vector<tree>& v, vector<vector<int>>& depth, int cur, int d) {
	if (v[cur].l != -1) dfs(v, depth, v[cur].l, d+1);
	depth[d].push_back(idx++);
	if (v[cur].r != -1) dfs(v, depth, v[cur].r, d+1);
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	int a, l, r;
	vector<int> ischild(n + 1);
	vector<tree> v(n + 1);
	vector<vector<int>> depth(n + 1);
	;	for (int i = 1;i <= n; i++) {
		cin >> a >> l >> r;
		if (l != -1)ischild[l] = true;
		if (r != -1)ischild[r] = true;
		v[a] = { l,r };
	}
	int start;
	for (int i = 1; i <= n; i++)if (!ischild[i]) start = i;
	dfs(v, depth, start, 0);
	int ans = -1, i = 0, id = -1;
	while (depth[i].size() != 0) {
		if (ans < depth[i].back() - depth[i][0] + 1) {
			ans = depth[i].back() - depth[i][0] + 1;
			id = i;
		}
		i++;
	}
	cout << id + 1 << ' ' << ans;
}