#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (v.empty()) {
			v.push_back(tmp);
			continue;
		}
		if (v.back() < tmp) v.push_back(tmp);
		else *lower_bound(v.begin(), v.end(), tmp) = tmp;
	}
	cout << v.size();
}