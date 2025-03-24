#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n, m, cur = 0, st = 0, max_cnt = 0, cur_cnt = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cin >> m;
	vector<int> w(m);
	for (int i = 0; i < m; i++) cin >> w[i];
	sort(v.rbegin(), v.rend());
	sort(w.rbegin(), w.rend());
	if (w[0] > v[0]) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		if (cur + 1 < v.size() && w[i] <= v[cur + 1]) {
			cur++;
			st += max_cnt - cur_cnt;
			cur_cnt = 0;
		}
		if (cur_cnt == max_cnt) {
			if (st != 0) st--;
			else {
				st = cur;
				cur_cnt++;
				max_cnt++;
			}
		}
		else cur_cnt++;
		//cout << "limit: " << v[cur] << " weight: " << w[i] << " max_cnt: " << max_cnt << " cur_cnt: " << cur_cnt << " stack: " << st << '\n';
	}
	cout << max_cnt;
}