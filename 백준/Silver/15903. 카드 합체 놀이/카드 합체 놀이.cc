#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	priority_queue<long long> pq;
	while (n--) {
		long long tmp;
		cin >> tmp;
		pq.push(-tmp);
	}
	while (m--) {
		long long first = -pq.top();
		pq.pop();
		long long second = -pq.top();
		pq.pop();
		pq.push(-(first + second));
		pq.push(-(first + second));
	}
	long long ans = 0;
	while (!pq.empty()) {
		ans += -pq.top();
		pq.pop();
	}
	cout << ans;
}