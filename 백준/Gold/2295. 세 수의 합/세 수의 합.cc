#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n, ans = 0;
	cin >> n;
	vector<int> v(n);
	unordered_map<int, bool> m;
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) m[v[i] + v[j]] = true;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (v[i] - v[j] < 0) continue;
		if (m.find(v[i] - v[j]) != m.end()) ans = max(ans, v[i]);
	}
	cout << ans;
}