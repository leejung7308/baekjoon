#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n, k, cnt = 0, ans = 0;
	cin >> n >> k;
	vector<int> seq(k);
	vector<queue<int>> idx(k + 1);
	vector<bool> used(k + 1);
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < k; i++) {
		cin >> seq[i];
		idx[seq[i]].push(i);
	}
	for (int i = 0; i < k; i++) {
		if (!used[seq[i]]) {
			used[seq[i]] = true;
			if (cnt == n) {
				int out = pq.top().second;
				pq.pop();
				used[out] = false;
				ans++;
			}
			else cnt++;
		}
		idx[seq[i]].pop();
		if (idx[seq[i]].empty()) pq.push({ INF,seq[i] });
		else pq.push({ idx[seq[i]].front(),seq[i] });
	}
	cout << ans;
}