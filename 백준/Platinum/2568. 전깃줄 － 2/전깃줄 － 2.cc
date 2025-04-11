#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	vector<int> lis;
	vector<int> idx;
	lis.push_back(v[0].second);
	idx.push_back(0);
	for (int i = 1; i < n; i++) {
		if (lis.back() < v[i].second) {
			lis.push_back(v[i].second);
			idx.push_back(lis.size() - 1);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), v[i].second);
			*it = v[i].second;
			idx.push_back(it - lis.begin());
		}
	}
	vector<int> rans;
	int s = lis.size() - 1;
	for (int i = idx.size() - 1; i >= 0; i--) {
		if (idx[i] == s) {
			rans.push_back(v[i].first);
			s--;
		}
	}
	int r = rans.size() - 1;
	cout << n - rans.size() << '\n';
	for (int i = 0; i < n; i++) {
		if (v[i].first == rans[r]) {
			r--;
			continue;
		}
		cout << v[i].first << '\n';
	}
}