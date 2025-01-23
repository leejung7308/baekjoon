#include<bits/stdc++.h>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0);
using namespace std;
string pre, in, ans;
int prePtr = 0;
char searchtree(string tree) {
	char root = pre[prePtr];
	if (tree.size() == 1) {
		prePtr++;
		return root;
	}
	int idx = tree.find(pre[prePtr]);
	prePtr++;
	if (idx > 0) {
		string left = tree.substr(0, idx);
		ans.push_back(searchtree(left));
	}
	if (idx < tree.size() - 1) {
		string right = tree.substr(idx + 1);
		ans.push_back(searchtree(right));
	}
	return root;
}
int main() {
	FAST_IO;
	while (cin >> pre >> in) {
		ans = "";
		prePtr = 0;
		ans.push_back(searchtree(in));
		cout << ans <<'\n';
	}
}