#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	priority_queue<int> pq;
	vector<pair<int, int>> v;
	while (n--) {
		int s, t;
		cin >> s >> t;
		v.push_back({ s,t });
	}
	sort(v.begin(), v.end());
	for(auto& i:v) {
		pq.push(-i.second);
		if (-pq.top() <= i.first) pq.pop();
	}
	cout << pq.size();
}