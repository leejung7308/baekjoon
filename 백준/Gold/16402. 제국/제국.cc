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
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) { 
		parent[pb] = a; 
		parent[a] = a;
	}
	else parent[pb] = pa;
}
int main() {
	FAST_IO;
	int n, m;
	string tmp;
	cin >> n >> m;
	getline(cin, tmp);
	unordered_map<string, int> kingdom;
	vector<string> name;
	for (int i = 0; i < n; i++) parent.push_back(i);
	for (int i = 0; i < n; i++) {
		getline(cin, tmp);
		kingdom[tmp] = i;
		name.push_back(tmp);
	}
	while (m--) {
		vector<string> v;
		getline(cin, tmp);
		istringstream ss(tmp);
		while (getline(ss, tmp, ',')) v.push_back(tmp);
		int a = kingdom[v[0]], b = kingdom[v[1]];
		string w = v[2];
		if (w == "1") uni(a, b);
		else uni(b, a);
	}
	set<int> winner;
	for (int i = 0; i < n; i++) winner.insert(find(i));
	vector<string> ans;
	for (auto& it : winner) ans.push_back(name[it]);
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (string& s : ans) cout << s << '\n';
}