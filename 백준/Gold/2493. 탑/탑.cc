#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n;
	cin >> n;
	stack<pair<int,int>> st;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		if (i == 0) {
			st.push({ tmp,i });
			cout << 0 << ' ';
			continue;
		}
		while (!st.empty() && st.top().first < tmp) st.pop();
		if (st.empty()) cout << 0 << ' ';
		else cout << st.top().second << ' ';
		st.push({ tmp,i });
	}
}