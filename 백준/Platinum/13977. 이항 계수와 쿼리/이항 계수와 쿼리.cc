#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
vector<LL> fact(4000001, 1);
LL Pow(LL n, int exp) {
	if (exp == 0) return 1;
	if (exp == 1) return n;
	if (exp % 2 == 0) {
		LL tmp = Pow(n, exp / 2);
		return (tmp * tmp) % MOD;
	}
	else {
		LL tmp = Pow(n, exp - 1);
		return (tmp * n) % MOD;
	}
}
int main() {
	FAST_IO;
	int m;
	cin >> m;
	for (int i = 1; i < 4000001; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	while (m--) {
		int n, k;
		cin >> n >> k;
		cout << fact[n] * Pow(fact[n - k] * fact[k] % MOD, MOD - 2) % MOD << '\n';
	}
}