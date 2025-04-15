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
	vector<int> idx(n), v, arr(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		if (v.empty()) {
			v.push_back(a);
			idx[i] = 1;
		}
		else if (v.back() < a) {
			v.push_back(a);
			idx[i] = v.size();
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), a);
			*it = a;
			idx[i] = it - v.begin() + 1;
		}
	}
	int j = v.size();
	vector<int> ans;
	for (int i = n - 1; i >= 0 && j > 0; i--) {
		if (idx[i] == j) {
			ans.push_back(arr[i]);
			j--;
		}
	}
	cout << ans.size() << '\n';
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
}