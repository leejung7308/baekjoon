#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, ans;
	cin >> n;
	ans = n;

	for (ll i = 2; i * i <= n; i++) {
		if (n % i != 0) continue;
		ans -= ans / i;
		while (n % i == 0) n /= i;
	}

	if (n > 1) ans -= ans / n;
	cout << ans;

	return 0;
}