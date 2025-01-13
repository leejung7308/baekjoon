#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	priority_queue<int> minus, plus;
	while (n--) {
		int tmp;
		cin >> tmp;
		if (tmp < 0) minus.push(-tmp);
		else plus.push(tmp);
	}
	int ans = 0;
	if (minus.empty()) {
		ans += plus.top();
		for (int i = 0; i < m; i++) {
			if (!plus.empty()) plus.pop();
		}
	}
	else if (plus.empty()) {
		ans += minus.top();
		for (int i = 0; i < m; i++) {
			if (!minus.empty()) minus.pop();
		}
	}
	else {
		if (minus.top() > plus.top()) {
			ans += minus.top();
			for (int i = 0; i < m; i++) {
				if (!minus.empty()) minus.pop();
			}
		}
		else {
			ans += plus.top();
			for (int i = 0; i < m; i++) {
				if (!plus.empty()) plus.pop();
			}
		}
	}
	while (!minus.empty()) {
		ans += minus.top() * 2;
		for (int i = 0; i < m; i++) {
			if (!minus.empty()) minus.pop();
		}
	}
	while (!plus.empty()) {
		ans += plus.top() * 2;
		for (int i = 0; i < m; i++) {
			if (!plus.empty()) plus.pop();
		}
	}
	cout << ans;
}