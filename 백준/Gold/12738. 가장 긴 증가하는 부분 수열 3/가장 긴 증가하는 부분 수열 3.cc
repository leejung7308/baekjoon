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
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (v.empty()) {
			v.push_back(input);
			continue;
		}
		if (v.back() < input) {
			v.push_back(input);
			continue;
		}
		*lower_bound(v.begin(), v.end(), input) = input;
	}
	cout << v.size();
}