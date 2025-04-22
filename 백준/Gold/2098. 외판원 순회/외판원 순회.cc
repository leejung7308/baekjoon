#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int n;
vector<vector<int>> v, dp;
bool visited(int bits, int city) {
	return bits & (1 << city);
}
int visit(int bits, int city) {
	return bits | (1 << city);
}
int tsp(int cur, int bits) {
	if (bits == (1 << n) - 1) return v[cur][0] != 0 ? v[cur][0] : INF;
	if (dp[cur][bits] != -1) return dp[cur][bits];
	dp[cur][bits] = INF;
	for (int i = 0; i < n; i++) {
		if (!visited(bits, i) && v[cur][i] != 0) 
			dp[cur][bits] = min(dp[cur][bits], tsp(i, visit(bits, i)) + v[cur][i]);
	}
	return dp[cur][bits];
}
int main() {
	FAST_IO;
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));
	dp = vector<vector<int>>(n, vector<int>(pow(2, n), -1));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
	cout << tsp(0, 1);
}