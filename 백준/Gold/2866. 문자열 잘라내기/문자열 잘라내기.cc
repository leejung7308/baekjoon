#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int r, c, cnt = 0;
	cin >> r >> c;
	vector<string> v(r);
	unordered_map<string, bool> m;
	for (int i = 0; i < r; i++) cin >> v[i];
	for (int i = 0; i < c; i++) {
		string s;
		for (int j = r-1; j >= 0; j--) s += v[j][i];
		m[s] = true;
	}
	for (int i = 0; i < r - 1; i++) {
		unordered_map<string, bool> tmp;
		for (const auto& p : m) {
			string s = p.first;
			s.pop_back();
			if (tmp.find(s) != tmp.end()) {
				cout << cnt;
				return 0;
			}
			tmp[s] = true;
		}
		cnt++;
		m = tmp;
	}
	cout << cnt;
}