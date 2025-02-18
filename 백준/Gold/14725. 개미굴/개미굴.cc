#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
struct trie {
	map<string, trie*> children;
};
void dfs(trie* t, int level) {
	for (auto& child : t->children) {
		for (int i = 0; i < level; i++) cout << "--";
		cout << child.first << '\n';
		dfs(child.second, level + 1);
	}
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	trie* root = new trie();
	while (n--) {
		int t;
		cin >> t;
		vector<string> arr(t);
		for (int i = 0; i < t; i++) cin >> arr[i];
		trie* tmp = root;
		for (auto& str : arr) {
			if (tmp->children.count(str) == 0) tmp->children[str] = new trie();
			tmp = tmp->children[str];
		}
	}
	dfs(root, 0);
}