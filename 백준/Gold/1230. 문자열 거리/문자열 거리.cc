#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
int main() {
	FAST_IO;
	string o, n;
	int mindp = 0;
	getline(cin, o);
	getline(cin, n);
	o = " " + o;
	n = " " + n;
	vector<int> dp(n.size());
	dp[0] = 1;
	for (int i = 1; i < o.size(); i++) {
		vector<int> tmp(n.size());
		mindp = 1000;
		for (int j = 1; j < n.size(); j++) {
			if (dp[j - 1]) mindp = min(mindp, dp[j - 1]);
			if (o[i] == n[j]) {
				if (dp[j - 1]) tmp[j] = dp[j - 1];
				else if (mindp != 1000) tmp[j] = mindp + 1;
			}
		}
		dp = tmp;
	}
	int ans = 1000;
	for (const int& d : dp) if(d != 0) ans = min(ans, d);
	if (ans == dp[n.size() - 1]) ans--;
	if (ans != 1000) cout << ans;
	else cout << -1;
}