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
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) dp[i] += dp[j] * 2;
	}
	cout << dp[n];
}