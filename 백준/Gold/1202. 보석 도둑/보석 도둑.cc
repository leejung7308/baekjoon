#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n, k, cnt = 0;
	long long ans = 0;
	cin >> n >> k;
	vector<pair<int, int>> j;
	vector<int> b(k);
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		j.push_back({ m,v });
	}
	for (int i = 0; i < k; i++) cin >> b[i];
	sort(j.begin(), j.end());
	sort(b.begin(), b.end());
	int idx = 0;
	priority_queue<int> pq;
	for (int i = 0; i < k; i++) {
		while (idx < n && b[i] >= j[idx].first) {
			pq.push(j[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}