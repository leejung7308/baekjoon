#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}
int main() {
	FAST_IO;
	int n, d, ans = 0;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		if (v[i].first > v[i].second) swap(v[i].first, v[i].second);
	}
	cin >> d;
	sort(v.begin(), v.end(), cmp);
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int s = v[i].first, e = v[i].second;
		if (e - s > d) continue;
		pq.push(-s);
		while (!pq.empty()) {
			if (-pq.top() < e - d) pq.pop();
			else break;
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
}