#include<bits/stdc++.h>
#include<unordered_map>
#define INF 987654321
using namespace std;
vector<int> post, in;
unordered_map<int, int> postidx, inidx;
void searchtree(int root, int lend, int rend) {
	int rootidx = inidx[root];
	int postrootidx = postidx[root];
	int leftsize = rootidx - lend;
	int rightsize = rend - rootidx;
	cout << root << ' ';
	if (leftsize > 0) {
		int leftroot = post[postrootidx - rightsize - 1];
		searchtree(leftroot, lend, rootidx - 1);
	}
	if (rightsize > 0) {
		int rightroot = post[postrootidx - 1];
		searchtree(rightroot, rootidx + 1, rend);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		in.push_back(tmp);
		inidx[tmp] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		post.push_back(tmp);
		postidx[tmp] = i;
	}
	searchtree(post[n - 1], 0, n - 1);
}