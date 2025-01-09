#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k, idx = -1, mn = -1, len;
	string s, ans;
	cin >> n >> k >> s;
	len = n - k;
	while (ans.size() < len) {
		mn = -1;
		for (int i = idx + 1; i <= k; i++) {
			if (mn < s[i] - '0') {
				mn = s[i] - '0';
				idx = i;
				if (s[i] - '0' == 9) break;
			}
		}
		k++;
		ans.push_back(s[idx]);
	}
	cout << ans;
}