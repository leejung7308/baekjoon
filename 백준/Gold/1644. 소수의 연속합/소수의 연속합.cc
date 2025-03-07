#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
vector<int> prime;
vector<long long> dp;
vector<bool> num;
void getprime(int n){
	num = vector<bool>(n + 1);
	int s = (int)sqrt(n);
	for (int i = 2; i <= s; i++) {
		for (int j = 2; j * i <= n; j++) {
			num[j * i] = true;
		}
	}
	prime.push_back(0);
	for (int i = 2; i <= n; i++) {
		if (!num[i]) prime.push_back(i);
	}
}
void getdp() {
	dp = vector<long long>(prime.size());
	dp[0] = prime[0];
	for (int i = 1; i < dp.size(); i++) {
		dp[i] = dp[i - 1] + prime[i];
	}
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	getprime(n);
	getdp();
	int s = 0, e = 1, cnt = 0;
	while (s != e && e < dp.size()) {
		int cur;
		cur = dp[e] - dp[s];
		if (cur < n) e++;
		else if (cur > n) s++;
		else if (cur == n) {
			cnt++;
			e++;
		}
	}
	cout << cnt;
}