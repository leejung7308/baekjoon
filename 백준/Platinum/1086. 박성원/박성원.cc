#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int n, k;
vector<string> v(15);
vector<pair<int,int>> nums(15);
vector<int> remainders(51);
vector<vector<long long>> dp(100, vector<long long>(1 << 15, -1));
long long dfs(int visit, int r) {
	if (visit == (1 << n) - 1) return r == 0 ? 1 : 0;
	if (dp[r][visit] != -1) return dp[r][visit];
	dp[r][visit] = 0;
	for (int i = 0; i < n; i++) {
		if (!(visit & (1 << i))) {
			int next = r * remainders[nums[i].second] + nums[i].first;
			dp[r][visit] += dfs(visit | (1 << i), next % k);
		}
	}
	return dp[r][visit];
}
long long gcd(long long a, long long b) {
	while (b) {
		long long tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main() {
	FAST_IO;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	cin >> k;
	if (k == 1) {
		cout << "1/1";
		return 0;
	}
	remainders[0] = 1;
	for (int i = 1; i <= 50; i++) remainders[i] = remainders[i - 1] * 10 % k;
	for (int i = 0; i < n; i++) {
		int len = v[i].size();
		int num = 0;
		for (int j = 0; j < v[i].size(); j++) {
			num *= 10;
			num += v[i][j] - '0';
			num %= k;
		}
		nums[i] = { num,len };
	}
	long long ans = dfs(0, 0);
	if (ans == 0) {
		cout << "0/1";
		return 0;
	}
	long long fact = 1;
	for (int i = 1; i <= n; i++) fact *= i;
	long long g = gcd(fact, ans);
	cout << ans / g << '/' << fact / g;
}