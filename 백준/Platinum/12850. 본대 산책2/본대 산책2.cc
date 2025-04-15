#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
const vector<vector<long long>> operator*(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
	vector<vector<long long>> ret(8, vector<long long>(8));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				ret[i][j] += a[i][k] * b[k][j];
			}
			ret[i][j] %= 1000000007;
		}
	}
	return ret;
}
int main() {
	FAST_IO;
	vector<vector<long long>> a = {
		{0,1,1,0,0,0,0,0},
		{1,0,1,1,0,0,0,0},
		{1,1,0,1,1,0,0,0},
		{0,1,1,0,1,1,0,0},
		{0,0,1,1,0,1,1,0},
		{0,0,0,1,1,0,0,1},
		{0,0,0,0,1,0,0,1},
		{0,0,0,0,0,1,1,0}
	};
	vector<vector<long long>> ans = {
		{1,0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0},
		{0,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,1,0},
		{0,0,0,0,0,0,0,1}
	};
	int n;
	cin >> n;
	while (n > 0) {
		if (n & 1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	cout << ans[0][0];
}