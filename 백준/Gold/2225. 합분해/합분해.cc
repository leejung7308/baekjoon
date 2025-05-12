#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int n, c;
vector<vector<int>> dp(201,vector<int>(201));
int main() {
	FAST_IO;
	cin >> n >> c;
	dp[0][0] = 1;
	for (int i = 1; i <= c; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[i - 1][j] == 0) continue;
			for (int k = 0; k <= n; k++) {
				if (j + k > n) continue;
				dp[i][j + k] += dp[i - 1][j];
				dp[i][j + k] %= 1000000000;
			}
		}
	}
	cout << dp[c][n];
}