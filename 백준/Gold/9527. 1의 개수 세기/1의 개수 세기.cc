#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	vector<vector<long long>> combine(65,vector<long long>(65));
	for (int i = 1; i < 65; i++) combine[i][0] = combine[i][i] = 1;
	for (int n = 2; n < 65; n++) {
		for (int k = 1; k < n; k++) combine[n][k] = combine[n - 1][k - 1] + combine[n - 1][k];
	}
	long long a, b;
	cin >> a >> b;
	long long idx = 0, bcnt = 0, acnt = 0, ocnt = 0;
	stack<int> st;
	while (b) {
		if (b & 1) st.push(idx);
		idx++;
		b >>= 1;
	}
	while (!st.empty()) {
		int cur = st.top();
		st.pop();
		bcnt += ocnt + 1;
		for (int i = 1; i <= cur; i++) bcnt += (i + ocnt) * combine[cur][i];
		ocnt++;
	}
	idx = 0, ocnt = 0;
	a--;
	while (a) {
		if (a & 1) st.push(idx);
		idx++;
		a >>= 1;
	}
	while (!st.empty()) {
		int cur = st.top();
		st.pop();
		acnt += ocnt + 1;
		for (int i = 1; i <= cur; i++) acnt += (i + ocnt) * combine[cur][i];
		ocnt++;
	}
	cout << bcnt - acnt;
}