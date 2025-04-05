#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first < b.first) return true;
	else if (a.first > b.first) return false;
	else if (a.second < b.second) return false;
	else return true;
}
int main() {
	FAST_IO;
	int n, m, sum = 0;
	cin >> n >> m;
	vector<int> mem(n), cost(n);
	for (int i = 0; i < n; i++) cin >> mem[i];
	for (int i = 0; i < n; i++) cin >> cost[i], sum += cost[i];
	vector<int> dp(sum + 1);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int cm = mem[i];
		int cc = cost[i];
		for (int j = dp.size() - 1; j >= cc; j--) {
			dp[j] = max( dp[j], dp[j - cc] + cm );
		}
	}
	for (int i = 0; i < dp.size(); i++) {
		if (dp[i] >= m) {
			cout << i;
			return 0;
		}
	}
}