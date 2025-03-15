#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
int d, p, q, ans = 2000000001;
int main() {
	FAST_IO;
	cin >> d >> p >> q;
	int big, small;
	if (p > q) {
		big = p;
		small = q;
	}
	else {
		big = q;
		small = p;
	}
	if (d < p && d < q) {
		cout << small;
		return 0;
	}
	if (d % p == 0 || d % q == 0) {
		cout << d;
		return 0;
	}
	unordered_map<int, bool> memo;
	int bcnt = d / big + 1;
	int cur = big * bcnt;
	int remainder = cur - d;
	while (bcnt) {
		ans = min(ans, remainder + d);
		if (remainder == 0) break;
		if (memo[remainder]) break;
		memo[remainder] = true;
		int next = (big - remainder) / small + 1;
		if ((big - remainder) % small == 0) next--;
		remainder = remainder - big + next * small;
		bcnt--;
	}
	if (remainder >= 0) ans = min(ans, remainder + d);
	cout << ans;
}