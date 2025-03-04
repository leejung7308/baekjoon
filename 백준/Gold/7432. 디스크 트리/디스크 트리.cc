#include<bits/stdc++.h>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
struct trie {
	map<string, trie*> children;
};
void dfs(trie* t, int d) {
	for (auto& child : t->children) {
		for (int i = 0; i < d; i++) cout << ' ';
		cout << child.first << '\n';
		dfs(child.second, d + 1);
	}
}
int main() {
	FAST_IO;
	trie* root = new trie();
	int n;
	cin >> n;
	while (n--) {
		string t, buffer;
		trie* tmp = root;
		vector<string> v;
		cin >> t;
		istringstream ss(t);
		while (getline(ss, buffer, '\\')) {
			v.push_back(buffer);
		}
		for (string& s : v) {
			if (tmp->children.count(s) == 0) tmp->children[s] = new trie();
			tmp = tmp->children[s];
		}
	}
	dfs(root, 0);
}