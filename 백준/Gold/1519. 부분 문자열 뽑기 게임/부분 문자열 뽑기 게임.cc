#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
vector<int> dp;
int game(string s) {
	if (s.size() == 1) return -1;
	int n = stoi(s);
	if (dp[n] != INF) return dp[n];
	bool flag = false;
	for (int i = 1; i < s.size(); i++) {
		for (int j = 0; j <= s.size() - i; j++) {
			int tmp = stoi(s.substr(j, i));
			if (tmp == 0) continue;
			if (game(to_string(n - tmp)) != -1) continue;
			flag = true;
			dp[n] = min(dp[n], tmp);
		}
	}
	return flag ? dp[n] : (dp[n] = -1);
}
int main() {
	FAST_IO;
	string s;
	cin >> s;
	dp = vector<int>(stoi(s) + 1, INF);
	if (s.size() == 1) {
		cout << -1;
		return 0;
	}
	cout << game(s);
}