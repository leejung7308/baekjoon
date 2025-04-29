#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<vector<long long>> combine(11, vector<long long>(11));
int main() {
	FAST_IO;
	vector<long long> ans(10);
	for (int i = 0; i < 11; i++) combine[i][0] = combine[i][i] = 1;
	for (int n = 2; n < 11; n++) for (int k = 1; k < n; k++) combine[n][k] = combine[n - 1][k - 1] + combine[n - 1][k];
	long long n;
	cin >> n;
	int digit = 0;
	stack<pair<int, int>> st;
	while (n != 0) {
		st.push({ n % 10,digit });
		digit++;
		n /= 10;
	}
	int big = st.top().second;
	if (big == 0) {
		for (int i = 0; i < 10; i++) {
			if (i == 0 || i > st.top().first) cout << 0 << ' ';
			else cout << 1 << ' ';
		}
		return 0;
	}
	vector<long long> dp(big + 1), dz(big + 1);
	dp[0] = 1;
	dz[0] = 0;
	for (int d = 1; d < dp.size(); d++) {
		dp[d] = 9 * dp[d - 1] + pow(10, d) + dp[d - 1];
	}
	for (int d = 1; d < dz.size(); d++) {
		long long sum = 0;
		for (int i = 1; i <= d; i++) sum += i * combine[d][i] * pow(9, d - i);
		dz[d] = dz[d - 1] + 9 * sum;
	}
	vector<int> prev(10);
	while (!st.empty()) {
		int r = st.top().first, d = st.top().second;
		st.pop();
		if (r == 0 && d > 0) {
			prev[r]++;
			continue;
		}
		long long sum = 0;
		for (int i = 1; i <= d; i++) sum += i * combine[d][i] * pow(9, d - i);
		if (d == big) ans[0] += (r - 1) * sum + dz[d - 1];
		if (d > 0) {
			if (d != big) ans[0] += r * sum + pow(10, d);
			for (int i = 1; i < 10; i++) {
				ans[i] += r * dp[d - 1];
				if (i < r) ans[i] += pow(10, d);
			}
			for (int i = 0; i < 10; i++) ans[i] += prev[i] * r * pow(10, d);
			prev[r]++;
		}
		else {
			for (int i = 0; i <= r; i++) ans[i]++;
			for (int i = 0; i < 10; i++) ans[i] += prev[i] * (r + 1);
		}
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}